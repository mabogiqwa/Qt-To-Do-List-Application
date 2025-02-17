#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSplitter>
#include <QStyle>
#include <QIcon>
#include <QAction>
#include <QFont>
#include <QFormLayout>
#include <QDateEdit>
#include <QScrollArea>
#include <QComboBox>
#include <QMessageBox>
#include <QTextEdit>
#include <QMainWindow>
#include "taskitemwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QWidget *contentArea;
    QLabel *imageLabel;
    QSize sizeHint() const;
    QVBoxLayout *tasksLayout;
    QWidget *tasksContainer;
    QScrollArea *tasksScrollArea;
    void setupTasksArea();
    void addNewTask(const QString &taskText);
    void removeCompletedTask(TaskItemWidget* widget);

};
#endif // MAINWINDOW_H
