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
    connect(ui->plainText, &QTextEdit::textChanged, this, &Widget::onplainTextChanged);
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

void Widget::onplainTextChanged()
{
    qDebug() <<" Text changed.." << ui->plainText->toPlainText();
    ui->morseCode->setReadOnly(true);
    std::string plainText = ui->plainText->toPlainText().toStdString();
    std::string morse;
    for (auto c : plainText) {
        morse += converter.plainTextToMorseCode(c);
        ui->morseCode->setPlainText(QString::fromStdString(morse));
    }
}
