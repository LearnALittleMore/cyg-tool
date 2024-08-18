#include "kbqwidget.h"
#include "ui_kbqwidget.h"

KBQWidget::KBQWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::KBQWidget)
{
    ui->setupUi(this);
}

KBQWidget::~KBQWidget()
{
    delete ui;
}
