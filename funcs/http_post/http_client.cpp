#include "http_client.h"
#include "ui_http_client.h"

HttpClient::HttpClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HttpClient)
{
    ui->setupUi(this);
}

HttpClient::~HttpClient()
{
    delete ui;
}
