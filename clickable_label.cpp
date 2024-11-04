#include "clickable_label.h"
#include <QtWidgets>

ClickableLabel::ClickableLabel (QWidget *parent) : QLabel(parent){
}

ClickableLabel::~ClickableLabel(){}

void ClickableLabel::mousePressEvent(QMouseEvent *clickedLabel) {
    emit clicked();
}
