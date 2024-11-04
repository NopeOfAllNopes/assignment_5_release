#ifndef CLICKABLE_LABEL_H
#define CLICKABLE_LABEL_H

#include <QtWidgets>
#include <QMouseEvent>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    ClickableLabel(QWidget *parent = nullptr);
    ~ClickableLabel();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event);

    using QLabel::QLabel;
};

#endif // CLICKABLE_LABEL_H
