#ifndef TASKINPUTWIDGET_H
#define TASKINPUTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QListWidget>

class TaskInputWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TaskInputWidget(QWidget *parent = nullptr, QLabel *existingImage = nullptr);
    void showPlaceholderImage();
    void hidePlaceholderImage();

signals:
    void taskAdded(const QString &task);

private:
    QLineEdit *inputField;
    QLabel *placeholderImage;
    QVBoxLayout *mainLayout;
    QListWidget *taskList;

    void setupUI();
    void handleTaskInput();
};

#endif // TASKINPUTWIDGET_H
