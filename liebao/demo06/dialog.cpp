#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // 初启动的时候隐藏
    ui->secondaryGroupBox->hide();
    ui->tertiaryGroupBox->hide();

    // 设置默认布局大小
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    // 设置下拉选择框中的值
    setColumnRange('A','Z');
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::setColumnRange(QChar first, QChar last)
{
    // 清除原本的内容
    ui->primaryComboBox->clear();

    // 添加 None 到下拉选择框
    ui->primaryComboBox->addItem(tr("None"));

    QChar ch = first;

    // 将 first 到 last 添加到下拉选择框
    while(ch <= last){
        ui->primaryComboBox->addItem(QString(ch));

        ch = ch.unicode() + 1;    // 自增
    }


}
