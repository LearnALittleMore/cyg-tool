#ifndef HTTP_POST_WIDGET_H
#define HTTP_POST_WIDGET_H

#include <QWidget>

namespace Ui {
class HttpPostWidget;
}

class HttpPostWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HttpPostWidget(QWidget *parent = nullptr);
    ~HttpPostWidget();

private:
    void initWidget();

private:
    Ui::HttpPostWidget *ui;

private slots:
    void on_btn_cli_clicked();
    void on_btn_serv_clicked();
};

#endif // HTTP_POST_WIDGET_H
