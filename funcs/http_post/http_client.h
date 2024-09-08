#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <QWidget>

namespace Ui {
class HttpClient;
}

class HttpClient : public QWidget
{
    Q_OBJECT

public:
    explicit HttpClient(QWidget *parent = nullptr);
    ~HttpClient();

private:
    Ui::HttpClient *ui;
};

#endif // HTTP_CLIENT_H
