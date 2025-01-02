#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("TodoMate Application");

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setStyleSheet("background-color: #2E2E2E;");

    QWidget *sidebar = new QWidget(this);
    sidebar->setFixedWidth(250);
    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebar);

    QWidget *searchWidget = new QWidget(sidebar);
    QHBoxLayout *searchLayout = new QHBoxLayout(searchWidget);
    QLineEdit *searchInput = new QLineEdit(searchWidget);
    searchInput->setPlaceholderText("Search");
    searchInput->setFixedWidth(250);
    searchInput->setFixedHeight(30);
    searchLayout->addWidget(searchInput);
    searchWidget->setLayout(searchLayout);

    QListWidget *menuList = new QListWidget(sidebar);

    QListWidgetItem *myDayItem = new QListWidgetItem("My Day");
    myDayItem->setIcon(QIcon("C:/Users/realm/OneDrive/Documents/QtProjects/todolist2-without-ui/icons/sun icon.png"));

    QListWidgetItem *importantItem = new QListWidgetItem("Important");
    importantItem->setIcon(QIcon("C:/Users/realm/OneDrive/Documents/QtProjects/todolist2-without-ui/icons/star icon.png"));

    QListWidgetItem *tasksItem = new QListWidgetItem("Tasks");
    tasksItem->setIcon(QIcon(":/icons/home icon.jpg"));

    QListWidgetItem *groceryItem = new QListWidgetItem("Groceries");
    groceryItem->setIcon(QIcon(":/icons/shopping icon.png"));

    menuList->addItem(myDayItem);
    menuList->addItem(importantItem);
    menuList->addItem(tasksItem);
    menuList->addItem(groceryItem);

    menuList->setStyleSheet(
        "QListWidget::item {"
        "   height: 20px;"  // Adjust height
        "   padding: 10px;" // Add padding
        "   font-size: 16px;"
        "   color: white;"
        "}"
        );

    QPushButton *logoutButton = new QPushButton("Exit",sidebar);

    sidebarLayout->addWidget(searchWidget);
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

    connect(menuList, &QListWidget::currentRowChanged, [contentLabel](int currentRow) {
        switch (currentRow) {
        case 0:
            contentLabel->setText("This is the 'My Day' section");
            break;
        case 1:
            contentLabel->setText("This is the 'Important' section.");
            break;
        case 2:
            contentLabel->setText("This is the 'Tasks' section.");
            break;
        default:
            contentLabel->setText("Main Content Area");
            break;
        }
    });
}

QSize MainWindow::sizeHint() const
{
    return QSize(900,850);
}

MainWindow::~MainWindow()
{
}

