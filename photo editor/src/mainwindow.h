#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bmp.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    BMPImage image;
    QString filename;
    BitmapFileHeader bmfh;
    BitmapInfoHeader bmih;
    BGR** pixels;
    bool save;

private slots:
    void on_OpenFile_clicked();

    void on_Square_clicked();

    void on_SaveFile_clicked();

    void on_Turn_clicked();

    void on_Print_clicked();

    void on_Undo_clicked();

    void on_color_clicked();

    void on_fill_color_clicked();

    void on_ColorPrint_clicked();

    void on_Info_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
