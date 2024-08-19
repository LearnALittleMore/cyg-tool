#ifndef KBQWIDGET_H
#define KBQWIDGET_H

#include <QWidget>

namespace Ui {
class KBQWidget;
}

class KBQWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KBQWidget(QWidget *parent = nullptr);
    ~KBQWidget();

    void initWidget();

private:
    Ui::KBQWidget *ui;

private slots:
    void on_btn_start_close_clicked();
};

#endif // KBQWIDGET_H
