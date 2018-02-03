
#include <QApplication>
#include <QWidget>
#include <QString>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *window = new QWidget;  // 部件

    window->setWindowTitle(QObject::tr("Enter Your Age")); // 设置部件标题

    QSpinBox *spinbox = new QSpinBox;  // 整数旋转框(允许用户通过单机向上/向下按钮来增加/减少当前显示的值)
    spinbox->setRange(0,200);       // 设置整数旋转框的数据范围

    QSlider *slider = new QSlider(Qt::Horizontal);     // 滑块，拖动显示对应数值,让这个滑块控件水平布局
    slider->setRange(0,200);        // 设置滑块数值范围

    QHBoxLayout *layout = new QHBoxLayout; // 水平布局
    layout->addWidget(spinbox);     // 将整数旋转框添加到布局
    layout->addWidget(slider);      // 将滑块添加到布局

    // 将整数旋转框与滑块互相关联
    QObject::connect(spinbox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)),spinbox,SLOT(setValue(int)));
    spinbox->setValue(40);  // 设置初值(关联后设置)

    window->setLayout(layout);      // 设置部件使用布局
    window->show();  // 显示部件

    return a.exec();
}
