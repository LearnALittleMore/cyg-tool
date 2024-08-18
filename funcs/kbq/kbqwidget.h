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

private:
    Ui::KBQWidget *ui;
};

#endif // KBQWIDGET_H
