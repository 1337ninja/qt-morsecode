#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(0);
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &Widget::onIndexChanged);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onIndexChanged(int index)
{
   qDebug() << "Index: "<<index;
   QPoint plainTextPos = ui->plainText->pos();
   QPoint morseCodePos = ui->morseCode->pos();
   ui->plainText->move(morseCodePos);
   ui->morseCode->move(plainTextPos);
}

