/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *OpenFile;
    QPushButton *SaveFile;
    QPushButton *Info;
    QLabel *BMP;
    QWidget *formLayoutWidget;
    QFormLayout *Square_lay;
    QLabel *label_2;
    QLineEdit *x1;
    QLabel *label_3;
    QLineEdit *y1;
    QLabel *label_5;
    QLineEdit *x2;
    QLabel *label_6;
    QLineEdit *y2;
    QLabel *label_9;
    QLineEdit *size1;
    QLabel *label_11;
    QCheckBox *fill;
    QPushButton *color;
    QPushButton *fill_color;
    QPushButton *Square;
    QLabel *label;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_5;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *x1_2;
    QLabel *label_12;
    QLineEdit *y1_2;
    QLabel *label_13;
    QLineEdit *x2_2;
    QLabel *label_14;
    QLineEdit *y2_2;
    QRadioButton *a90;
    QRadioButton *a180;
    QRadioButton *a270;
    QPushButton *Turn;
    QPushButton *Undo;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout;
    QLabel *label_4;
    QRadioButton *variant1;
    QRadioButton *variant2;
    QRadioButton *variant3;
    QPushButton *ColorPrint;
    QLabel *label_10;
    QLineEdit *size2;
    QPushButton *Print;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1383, 757);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        OpenFile = new QPushButton(centralWidget);
        OpenFile->setObjectName(QStringLiteral("OpenFile"));
        OpenFile->setGeometry(QRect(10, 10, 89, 31));
        SaveFile = new QPushButton(centralWidget);
        SaveFile->setObjectName(QStringLiteral("SaveFile"));
        SaveFile->setGeometry(QRect(130, 10, 89, 31));
        Info = new QPushButton(centralWidget);
        Info->setObjectName(QStringLiteral("Info"));
        Info->setGeometry(QRect(370, 10, 51, 31));
        BMP = new QLabel(centralWidget);
        BMP->setObjectName(QStringLiteral("BMP"));
        BMP->setGeometry(QRect(380, 50, 251, 211));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(190, 50, 168, 301));
        Square_lay = new QFormLayout(formLayoutWidget);
        Square_lay->setSpacing(6);
        Square_lay->setContentsMargins(11, 11, 11, 11);
        Square_lay->setObjectName(QStringLiteral("Square_lay"));
        Square_lay->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        Square_lay->setWidget(0, QFormLayout::SpanningRole, label_2);

        x1 = new QLineEdit(formLayoutWidget);
        x1->setObjectName(QStringLiteral("x1"));

        Square_lay->setWidget(1, QFormLayout::FieldRole, x1);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        Square_lay->setWidget(2, QFormLayout::LabelRole, label_3);

        y1 = new QLineEdit(formLayoutWidget);
        y1->setObjectName(QStringLiteral("y1"));

        Square_lay->setWidget(2, QFormLayout::FieldRole, y1);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        Square_lay->setWidget(3, QFormLayout::LabelRole, label_5);

        x2 = new QLineEdit(formLayoutWidget);
        x2->setObjectName(QStringLiteral("x2"));

        Square_lay->setWidget(3, QFormLayout::FieldRole, x2);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        Square_lay->setWidget(4, QFormLayout::LabelRole, label_6);

        y2 = new QLineEdit(formLayoutWidget);
        y2->setObjectName(QStringLiteral("y2"));

        Square_lay->setWidget(4, QFormLayout::FieldRole, y2);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        Square_lay->setWidget(5, QFormLayout::LabelRole, label_9);

        size1 = new QLineEdit(formLayoutWidget);
        size1->setObjectName(QStringLiteral("size1"));

        Square_lay->setWidget(5, QFormLayout::FieldRole, size1);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        Square_lay->setWidget(6, QFormLayout::LabelRole, label_11);

        fill = new QCheckBox(formLayoutWidget);
        fill->setObjectName(QStringLiteral("fill"));
        fill->setEnabled(true);
        fill->setChecked(false);

        Square_lay->setWidget(6, QFormLayout::FieldRole, fill);

        color = new QPushButton(formLayoutWidget);
        color->setObjectName(QStringLiteral("color"));

        Square_lay->setWidget(7, QFormLayout::LabelRole, color);

        fill_color = new QPushButton(formLayoutWidget);
        fill_color->setObjectName(QStringLiteral("fill_color"));

        Square_lay->setWidget(7, QFormLayout::FieldRole, fill_color);

        Square = new QPushButton(formLayoutWidget);
        Square->setObjectName(QStringLiteral("Square"));

        Square_lay->setWidget(8, QFormLayout::SpanningRole, Square);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        Square_lay->setWidget(1, QFormLayout::LabelRole, label);

        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(20, 200, 151, 241));
        formLayout_5 = new QFormLayout(formLayoutWidget_2);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(formLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setTextFormat(Qt::AutoText);

        formLayout_5->setWidget(0, QFormLayout::SpanningRole, label_7);

        label_8 = new QLabel(formLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_8);

        x1_2 = new QLineEdit(formLayoutWidget_2);
        x1_2->setObjectName(QStringLiteral("x1_2"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, x1_2);

        label_12 = new QLabel(formLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_12);

        y1_2 = new QLineEdit(formLayoutWidget_2);
        y1_2->setObjectName(QStringLiteral("y1_2"));

        formLayout_5->setWidget(2, QFormLayout::FieldRole, y1_2);

        label_13 = new QLabel(formLayoutWidget_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_13);

        x2_2 = new QLineEdit(formLayoutWidget_2);
        x2_2->setObjectName(QStringLiteral("x2_2"));

        formLayout_5->setWidget(3, QFormLayout::FieldRole, x2_2);

        label_14 = new QLabel(formLayoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, label_14);

        y2_2 = new QLineEdit(formLayoutWidget_2);
        y2_2->setObjectName(QStringLiteral("y2_2"));

        formLayout_5->setWidget(4, QFormLayout::FieldRole, y2_2);

        a90 = new QRadioButton(formLayoutWidget_2);
        a90->setObjectName(QStringLiteral("a90"));

        formLayout_5->setWidget(5, QFormLayout::LabelRole, a90);

        a180 = new QRadioButton(formLayoutWidget_2);
        a180->setObjectName(QStringLiteral("a180"));

        formLayout_5->setWidget(5, QFormLayout::FieldRole, a180);

        a270 = new QRadioButton(formLayoutWidget_2);
        a270->setObjectName(QStringLiteral("a270"));

        formLayout_5->setWidget(6, QFormLayout::LabelRole, a270);

        Turn = new QPushButton(formLayoutWidget_2);
        Turn->setObjectName(QStringLiteral("Turn"));

        formLayout_5->setWidget(7, QFormLayout::SpanningRole, Turn);

        Undo = new QPushButton(centralWidget);
        Undo->setObjectName(QStringLiteral("Undo"));
        Undo->setGeometry(QRect(250, 10, 91, 31));
        formLayoutWidget_3 = new QWidget(centralWidget);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(20, 50, 151, 151));
        formLayout = new QFormLayout(formLayoutWidget_3);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label_4);

        variant1 = new QRadioButton(formLayoutWidget_3);
        variant1->setObjectName(QStringLiteral("variant1"));

        formLayout->setWidget(1, QFormLayout::LabelRole, variant1);

        variant2 = new QRadioButton(formLayoutWidget_3);
        variant2->setObjectName(QStringLiteral("variant2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, variant2);

        variant3 = new QRadioButton(formLayoutWidget_3);
        variant3->setObjectName(QStringLiteral("variant3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, variant3);

        ColorPrint = new QPushButton(formLayoutWidget_3);
        ColorPrint->setObjectName(QStringLiteral("ColorPrint"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ColorPrint);

        label_10 = new QLabel(formLayoutWidget_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_10);

        size2 = new QLineEdit(formLayoutWidget_3);
        size2->setObjectName(QStringLiteral("size2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, size2);

        Print = new QPushButton(formLayoutWidget_3);
        Print->setObjectName(QStringLiteral("Print"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, Print);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1383, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        OpenFile->setText(QApplication::translate("MainWindow", "Open file", Q_NULLPTR));
        SaveFile->setText(QApplication::translate("MainWindow", "Save File", Q_NULLPTR));
        Info->setText(QApplication::translate("MainWindow", "Info", Q_NULLPTR));
        BMP->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Square", Q_NULLPTR));
        x1->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", " y1 = ", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", " x2 = ", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", " y2 = ", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "size =", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "fill", Q_NULLPTR));
        fill->setText(QString());
        color->setText(QApplication::translate("MainWindow", "Color", Q_NULLPTR));
        fill_color->setText(QApplication::translate("MainWindow", "Fill color", Q_NULLPTR));
        Square->setText(QApplication::translate("MainWindow", "Draw", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", " x1 = ", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Turn", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", " x1 = ", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", " y1 = ", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", " x2 = ", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", " y2 = ", Q_NULLPTR));
        a90->setText(QApplication::translate("MainWindow", "90", Q_NULLPTR));
        a180->setText(QApplication::translate("MainWindow", "180", Q_NULLPTR));
        a270->setText(QApplication::translate("MainWindow", "270", Q_NULLPTR));
        Turn->setText(QApplication::translate("MainWindow", "Draw", Q_NULLPTR));
        Undo->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Frame", Q_NULLPTR));
        variant1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        variant2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        variant3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        ColorPrint->setText(QApplication::translate("MainWindow", "Color", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "size =", Q_NULLPTR));
        Print->setText(QApplication::translate("MainWindow", "Draw", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
