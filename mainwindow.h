#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QListWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSplitter>
#include <QStyle>
#include <QIcon>
#include <QAction>
#include <QFont>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QSize sizeHint() const;
    void addMenuItem(const QString &text, const QString &iconPath);

};
#endif // MAINWINDOW_H
