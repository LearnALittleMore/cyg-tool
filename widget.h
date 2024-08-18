#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <map>
#include <QString>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void initMainWindow();
    void initStyleSheet();
    void initFuncWidgets();
    void initConnect();

private:
    Ui::Widget *ui;
    std::map<QString, QWidget*> m_funcWidgets;

    int m_curWinSize;

private slots:
    void on_btn_min_clicked();
    void on_btn_max_clicked();
    void on_btn_close_clicked();
    void sl_listWidget_clicked(QListWidgetItem *item);
};
#endif // WIDGET_H
