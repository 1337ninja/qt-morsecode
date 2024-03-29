#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>
#include <sstream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget),
      plaintextMorseConverter(new PlaintextMorseConverter)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(0);
    ui->morseCode->setReadOnly(true);
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &Widget::onIndexChanged);
    disconnect(ui->morseCode, &QTextEdit::textChanged, this, &Widget::onMorseCodeChanged);
    connect(ui->plainText, &QTextEdit::textChanged, this, &Widget::onPlainTextChanged);
}

Widget::~Widget()
{
    delete ui;
    delete plaintextMorseConverter;
}

void Widget::onIndexChanged(int index)
{
   qDebug() << "Index: "<<index;
   ui->plainText->clear();
   ui->morseCode->clear();
   QPoint plainTextPos = ui->plainText->pos();
   QPoint morseCodePos = ui->morseCode->pos();
   ui->plainText->move(morseCodePos);
   ui->morseCode->move(plainTextPos);
   /* Text to Morse */
   if (0 == index) {
       disconnect(ui->morseCode, &QTextEdit::textChanged, this, &Widget::onMorseCodeChanged);
       connect(ui->plainText, &QTextEdit::textChanged, this, &Widget::onPlainTextChanged);
       ui->morseCode->setReadOnly(true);
       ui->plainText->setReadOnly(false);
   }
   /* Morse to Text */
   else if (1 == index) {
       disconnect(ui->plainText, &QTextEdit::textChanged, this, &Widget::onPlainTextChanged);
       connect(ui->morseCode, &QTextEdit::textChanged, this, &Widget::onMorseCodeChanged);
       ui->morseCode->setReadOnly(false);
       ui->plainText->setReadOnly(true);
   }
}

void Widget::onPlainTextChanged()
{
    qDebug() <<" Text changed.." << ui->plainText->toPlainText();
    std::string plainText = ui->plainText->toPlainText().toStdString();
    std::string morseCode = plaintextMorseConverter->convert(plainText);
    ui->morseCode->setPlainText(QString::fromStdString(morseCode));
}

void Widget::onMorseCodeChanged()
{
    qDebug() <<" Morse code entered.." << ui->morseCode->toPlainText();
    std::string morseText = ui->morseCode->toPlainText().toStdString();
    std::string plainText = plaintextMorseConverter->inverseConvert(morseText);
    ui->plainText->setPlainText(QString::fromStdString(plainText));
}
