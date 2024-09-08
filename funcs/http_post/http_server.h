#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <QWidget>

namespace Ui {
class HttpServer;
}

class HttpServer : public QWidget
{
    Q_OBJECT

public:
    explicit HttpServer(QWidget *parent = nullptr);
    ~HttpServer();

private:
    Ui::HttpServer *ui;

private slots:
    void on_btn_servStart_clicked();
};

#endif // HTTP_SERVER_H
