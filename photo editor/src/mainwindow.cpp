#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bmp.h"

#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <QString>
#include <QPixmap>


#include <iostream>
#include <fstream>


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OpenFile_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.bmp)"));
    QByteArray qb = file.toUtf8();
    filename = qb.data();
    if(!filename.length()){
		QMessageBox::warning(this, "Reading error", "wrong path");
		QPixmap empty;
		ui->BMP->setPixmap(empty);
        return;
    }

    image.BMPRead(filename.toStdString());

    if (image.bmfh.signature != 0x4D42){
        QMessageBox::warning(this, "Reading error", "file is not BMP");
        return;
    }
    if ((image.bmih.bitsPerPixel != 24) || (image.bmih.compression != 0)){
        QMessageBox::warning(this, "Reading error", "not 24 bits");
        return;
    }
    bmfh = image.bmfh;
    bmih = image.bmih;
    pixels = new BGR*[image.height*sizeof(BGR*)];
    for(int i=0; i<image.height; i++){
        pixels[i] = new BGR[image.width * sizeof(BGR) + (image.width*3)%4];
        for(int j=0; j<image.width; j++){
            pixels[i][j] = image.pixels[i][j];
        }
    }

    QPixmap bmp(filename);
    int w = bmp.width();
    int h = bmp.height();
    ui->BMP->setGeometry(380, 50, w, h);
    ui->BMP->setPixmap(bmp);
    save = 1;

}

void MainWindow::on_Square_clicked()
{
    if(!filename.length()){
        QMessageBox::warning(this, "Input error", "Open file");
        return;
    }
    Coordinate max,min;
    max.x = ui->x1->text().toInt();
    max.y = ui->y1->text().toInt();
    min.x = ui->x2->text().toInt();
    min.y = ui->y2->text().toInt();
    if((max.y > min.y) || (max.x > min.x)){
        QMessageBox::warning(this, "Input error", "x1 < x2, y1 < y2");
        return;
    }
    if(max.y >= image.height || max.x >= image.width || min.y >= image.height || min.x >= image.width){
        QMessageBox::warning(this, "Input error", "x1,x2 < width \ny1,y2 < height");
        return;
    }
    image.BMPDrawSquare(max, min , ui->size1->text().toInt(),ui->fill->checkState());
    save = 0;
    on_SaveFile_clicked();
    save = 1;
}

void MainWindow::on_SaveFile_clicked()
{
    if(!filename.length()){
        QMessageBox::warning(this, "Input error", "Open file");
        return;
    }
    if(save){
        bmfh = image.bmfh;
        bmih = image.bmih;
        pixels = new BGR*[image.height*sizeof(BGR*)];
        for(int i=0; i<image.height; i++){
            pixels[i] = new BGR[image.width * sizeof(BGR) + (image.width*3)%4];
            for(int j=0; j<image.width; j++){
                pixels[i][j] = image.pixels[i][j];
            }
        }
    }
    image.BMPWrite(filename.toStdString());
    QPixmap bmp(filename);
    int w = bmp.width();
    int h = bmp.height();
    ui->BMP->setGeometry(380, 50, w, h);
    ui->BMP->setPixmap(bmp);

}

void MainWindow::on_Turn_clicked()
{
    if(!filename.length()){
        QMessageBox::warning(this, "Input error", "Open file");
        return;
    }
    Coordinate max,min;
    max.x = ui->x1_2->text().toInt();
    max.y = ui->y1_2->text().toInt();
    min.x = ui->x2_2->text().toInt();
    min.y = ui->y2_2->text().toInt();

    if((max.y > min.y) || (max.x > min.x)){
        QMessageBox::warning(this, "Input error", "x1 < x2, y1 < y2");
        return;
    }
    if(max.y >= image.height || max.x >= image.width || min.y >= image.height || min.x >= image.width){
        QMessageBox::warning(this, "Input error", "x1,x2 < width \ny1,y2 < height");
        return;
    }
    if(max.y-min.y != max.x-min.x){
        QMessageBox::warning(this, "Input error", "x2-x1 = y2-y1");
        return;
    }else if(ui->a90->isChecked()){
        image.BMPTurn(max, min , 90);
    }else if(ui->a180->isChecked()){
        image.BMPTurn(max, min , 180);
    }else if(ui->a270->isChecked()){
        image.BMPTurn(max, min , 270);
    }
    save = 0;
    on_SaveFile_clicked();
    save = 1;
}

void MainWindow::on_Print_clicked()
{
    if(!filename.length()){
        QMessageBox::warning(this, "Input error", "Open file");
        return;
    }
    if(ui->size2->text().toInt() >= image.width){
        QMessageBox::warning(this, "Input error", "size < width");
        return;
    }
    if(ui->size2->text().toInt() >= image.height){
        QMessageBox::warning(this, "Input error", "size < hieght");
        return;
    }
    if(ui->variant1->isChecked()) image.Razor(ui->size2->text().toInt(),image.colorPrint,0);
    if(ui->variant2->isChecked()) image.Snowflakes(ui->size2->text().toInt(),image.colorPrint);
    if(ui->variant3->isChecked()) image.Razor(ui->size2->text().toInt(),image.colorPrint,1);

    save = 0;
    on_SaveFile_clicked();
    save = 1;

}

void MainWindow::on_Undo_clicked()
{
    if(!filename.length()){
        QMessageBox::warning(this, "Input error", "Open file");
        return;
    }
    ofstream image_buf(filename.toStdString(), ios::binary);
    image_buf.write((char*)&bmfh, sizeof(BitmapFileHeader));
    image_buf.write((char*)&bmih, sizeof(BitmapInfoHeader));
    int H = bmih.height;
    int W = bmih.width;
    unsigned int w = (W) * sizeof(BGR) + (W*3)%4;
    for(int i=0; i<H; i++){
        image_buf.write((char*)pixels[i],w);
        for(int j = 0; j<W; j++){
            image.pixels[i][j] = pixels[i][j];
        }
    }
    image_buf.close();
    QPixmap bmp(filename);
    ui->BMP->setGeometry(380, 50, W, H);
    ui->BMP->setPixmap(bmp);

}

void MainWindow::on_color_clicked()
{
    QColor color = QColorDialog::getColor().toRgb();
    image.colorSquare = {(unsigned char)color.blue(),(unsigned char)color.green(),(unsigned char)color.red()};

}

void MainWindow::on_fill_color_clicked()
{
    QColor color = QColorDialog::getColor().toRgb();
    image.colorSquare_fill = {(unsigned char)color.blue(),(unsigned char)color.green(),(unsigned char)color.red()};
}

void MainWindow::on_ColorPrint_clicked()
{
    QColor color = QColorDialog::getColor().toRgb();
    image.colorPrint = {(unsigned char)color.blue(),(unsigned char)color.green(),(unsigned char)color.red()};
}

void MainWindow::on_Info_clicked()
{
    if(!filename.length()){
        QMessageBox::warning(this, "Input error", "Open file");
        return;
    }
    QMessageBox info;
    QString inf = QString("\nsize - %1x%2").arg(image.width).arg(image.height);
    info.information(0, "Bitmap info", inf);
}
