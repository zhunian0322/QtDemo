#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

// 前置声明,前置申明会告诉 C++ 编译程序类的存在，而不用提供类定义中的所有细节
class QWidget;
class QLabel;
class QCheckBox;
class QLineEdit;
class QPushButton;

// 继承 QDialog (对话框)类
class FindDialog : public QDialog
{
    Q_OBJECT //对于所有定义了信号和槽的类，在类的开始处需加入 Q_OBJECT 宏

public:
    // 构造函数  参数为 QWidget 部件类
    FindDialog(QWidget *parent = 0);

signals:  // 信号
    /*
        Qt::CaseSensitivity 为枚举类型, 可取值Qt::CaseSensitive 和 Qt::CaseInsensitive, 表示匹配的灵敏度。
        CaseSensitive 是说要注意字母大写或小写
        CaseInsensitive 是说所有字母可以大写或小写
    */
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:  // 槽函数
    void enabledFindButton(const QString &text);
    void findClicked();


private:
    // 因为只是指针变量，使用前置声明即可
    QLabel *label;                  // 标签-找什么
    QLineEdit *lineEdit;            // 单行文本输入
    QCheckBox *backwardCheckBox;    // 选择框-向后查找
    QCheckBox *caseCheckBox;        // 选择框-区分大小写
    QPushButton *findButton;        // 按钮-开始查找
    QPushButton *closeButton;       // 按钮-关闭

};

#endif // FINDDIALOG_H
