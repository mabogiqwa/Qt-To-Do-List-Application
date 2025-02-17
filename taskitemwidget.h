#ifndef TASKITEMWIDGET_H
#define TASKITEMWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QPropertyAnimation>

class TaskItemWidget: public QWidget
{
    Q_OBJECT
public:
    explicit TaskItemWidget(const QString &text, QWidget *parent = nullptr);
};

#endif // TASKITEMWIDGET_H
