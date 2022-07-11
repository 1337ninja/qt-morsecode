#include "widget.h"
#include "./ui_widget.h"
#include "constants.h"
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
   ui->plainText->clear();
   ui->morseCode->clear();
   QPoint plainTextPos = ui->plainText->pos();
   QPoint morseCodePos = ui->morseCode->pos();
   ui->plainText->move(morseCodePos);
   ui->morseCode->move(plainTextPos);
   /* Text to Morse */
   if (0 == index) {
       ui->morseCode->setReadOnly(true);
       ui->plainText->setReadOnly(false);
   }
   /* Morse to Text */
   else if (1 == index) {
       ui->morseCode->setReadOnly(false);
       ui->plainText->setReadOnly(true);
   }
}

void Widget::onplainTextChanged()
{
    qDebug() <<" Text changed.." << ui->plainText->toPlainText();
    std::string plainText = ui->plainText->toPlainText().toStdString();
    std::string morse;
    for (int i = 0; i < plainText.size(); i++) {
        morse += converter.plainTextToMorseCode(plainText[i]);
        if (i != plainText.size() - 1) {
            morse += Constants::morseDelimiter;
        }
    }
    ui->morseCode->setPlainText(QString::fromStdString(morse));
}
