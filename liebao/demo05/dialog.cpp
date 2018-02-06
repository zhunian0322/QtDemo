#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // 设置正则表达式
    QRegExp regexp("[A-Za-z][1-9][0-9]{0,2}");
    // 设置列编辑器输入限制
    ui->lineEdit->setValidator(new QRegExpValidator(regexp,this));
}

Dialog::~Dialog()
{
    delete ui;
}

 void Dialog::on_lineEdit_textChanged(){

     ui->OKButton->setEnabled(ui->lineEdit->hasAcceptableInput());
 }
