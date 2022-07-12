#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "converter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onIndexChanged(int index);
    void onPlainTextChanged();
    void onMorseCodeChanged();

private:
    Ui::Widget *ui;
    Converter converter;
};
#endif // WIDGET_H
