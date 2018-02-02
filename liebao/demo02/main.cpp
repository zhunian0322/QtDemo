
#include <QApplication>
#include <QPushButton>

/**
* 创建一个按钮，点击按钮窗体退出
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建一个按钮
    QPushButton *button = new QPushButton();
    // 连接button的信号与QApplication的槽函数(点击按钮，窗体退出)
    QObject::connect(button,SIGNAL(clicked()),&a,SLOT(quit()));

    button->show();

    return a.exec();
}
