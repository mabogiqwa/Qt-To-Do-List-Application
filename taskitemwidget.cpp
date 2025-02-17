#include "taskitemwidget.h"

TaskItemWidget::TaskItemWidget(const QString &text, QWidget *parent)
    : QWidget(parent)
{

    layout = new QHBoxLayout(this);
    layout->setContentsMargins(10,5,10,5);

    checkbox = new QCheckBox(this);
    checkbox->setStyleSheet(
        "QCheckBox {"
        "   spacing: 5px;"
        "}"
        "QCheckBox::indicator {"
        "   width: 20px;"
        "   height: 20px;"
        "   border-radius: 10px;"
        "   border: 2px solid white;"
        "   background: transparent;"
        "}"
        "QCheckBox::indicator:checked {"
        "   background-color: rgba(255,255,255,0.8);"
        "   image: url(icons/check.png)"
        "}"
        );

    taskLabel = new QLabel(text, this);
    taskLabel->setStyleSheet(
        "QLabel {"
        "   color: white;"
        "   font-size: 14px;"
        "}"
    );

    layout->addWidget(checkbox);
    layout->addWidget(taskLabel);
    layout->addStretch();

    setStyleSheet(
        "TaskItemWidget {"
        "   background-color: rgba(0,0,0,0.3);"
        "   border-radius: 10px;"
        "   margin: 2px;"
        "   padding: 5px;"
        "}"
    );

    fadeOutAnimation = new QPropertyAnimation(this, "windowOpacity", this);
    fadeOutAnimation->setDuration(500);
    fadeOutAnimation->setStartValue(1.0);
    fadeOutAnimation->setEndValue(0.0);

    connect(checkbox, &QCheckBox::clicked, this, [this]() {
        startRemovalAnimation();
    });

    connect(fadeOutAnimation, &QPropertyAnimation::finished, this, [this]() {
        emit taskCompleted(this);
    });
}

void TaskItemWidget::startRemovalAnimation()
{
    fadeOutAnimation->start();
}
