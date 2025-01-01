#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("TodoMate Application");

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QWidget *sidebar = new QWidget(this);
    sidebar->setFixedWidth(250);

    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebar);

    QLabel *sidebarTitle = new QLabel("Menu",sidebar);
    sidebarTitle->setAlignment(Qt::AlignCenter);

    QListWidget *menuList = new QListWidget(sidebar);
    menuList->addItem("My Day");
    menuList->addItem("Important");
    menuList->addItem("Tasks");

    QPushButton *logoutButton = new QPushButton("Logout",sidebar);

    sidebarLayout->addWidget(sidebarTitle);
    sidebarLayout->addWidget(menuList);
    sidebarLayout->addWidget(logoutButton);

    // Main content area
    QWidget *contentArea = new QWidget(this);
    QVBoxLayout *contentLayout = new QVBoxLayout(contentArea);
    QLabel *contentLabel = new QLabel("Main Content Area", contentArea);
    contentLabel->setAlignment(Qt::AlignCenter);
    contentLayout->addWidget(contentLabel);

    // Layout: Sidebar and Content
    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(sidebar);
    splitter->addWidget(contentArea);
    splitter->setStretchFactor(1, 1);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(splitter);
}

QSize MainWindow::sizeHint() const
{
    return QSize(2000,1500);
}

MainWindow::~MainWindow()
{
}

