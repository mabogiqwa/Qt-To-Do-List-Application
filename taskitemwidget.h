#ifndef TASKITEMWIDGET_H
#define TASKITEMWIDGET_H

#include <QObject>
#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QPropertyAnimation>

class TaskItemWidget: public QWidget
{
    Q_OBJECT
public:
    explicit TaskItemWidget(const QString &text, QWidget *parent = nullptr);
    void startRemovalAnimation();

signals:
    void taskCompleted(TaskItemWidget* widget);

private:
    QCheckBox *checkbox;
    QLabel *taskLabel;
    QHBoxLayout *layout;
    QPropertyAnimation *fadeOutAnimation;
};

#endif // TASKITEMWIDGET_H
