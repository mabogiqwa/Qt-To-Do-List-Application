#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
#include <QComboBox>
#include <QMessageBox>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QSize sizeHint() const;

};
#endif // MAINWINDOW_H
