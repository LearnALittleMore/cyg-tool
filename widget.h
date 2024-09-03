#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPoint>
#include <map>
#include <QString>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class widget_main;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void initMainWindow();
    void initStyleSheet();
    void initFuncWidgets();

private:
    Ui::widget_main *ui;
    std::map<QString, QWidget*> m_funcWidgets;

    int m_curWinSize;
    bool m_mouPress;
    QPoint m_mouPoint;

private slots:
    void on_btn_min_clicked();
    void on_btn_max_clicked();
    void on_btn_close_clicked();
    void on_listWidget_itemClicked(QListWidgetItem*item);
};
#endif // WIDGET_H
