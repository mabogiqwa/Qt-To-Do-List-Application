#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("To-Do List Application");

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setStyleSheet("background-color: #2E2E2E;");

    QWidget *sidebar = new QWidget(this);
    sidebar->setFixedWidth(250);
    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebar);
    sidebarLayout->setSpacing(0);
    sidebarLayout->setContentsMargins(0,0,0,0);

    QWidget *searchWidget = new QWidget(sidebar);
    QHBoxLayout *searchLayout = new QHBoxLayout(searchWidget);
    searchLayout->setContentsMargins(0,0,0,0);

    QLineEdit *searchInput = new QLineEdit(searchWidget);
    searchInput->setPlaceholderText("Search");
    searchInput->setFixedWidth(250);
    searchInput->setFixedHeight(30);

    searchLayout->addWidget(searchInput);
    searchWidget->setLayout(searchLayout);

    QAction *searchAction = new QAction(searchInput);
    searchAction->setIcon(style()->standardIcon(QStyle::SP_FileDialogContentsView));
    searchInput->addAction(searchAction, QLineEdit::TrailingPosition);

    QListWidget *menuList = new QListWidget(sidebar);

    QListWidgetItem *myDayItem = new QListWidgetItem("My Day");
    QFont font = myDayItem->font();
    font.setPointSize(14);
    myDayItem->setFont(font);
    myDayItem->setIcon(QIcon("C:/Users/realm/OneDrive/Documents/QtProjects/todolist2-without-ui/icons/sun icon.png"));

    QListWidgetItem *importantItem = new QListWidgetItem("Important");
    QFont font1 = importantItem->font();
    font1.setPointSize(14);
    importantItem->setFont(font1);
    importantItem->setIcon(QIcon("C:/Users/realm/OneDrive/Documents/QtProjects/todolist2-without-ui/icons/star icon.png"));

    QListWidgetItem *tasksItem = new QListWidgetItem("Tasks");
    QFont font2 = tasksItem->font();
    font2.setPointSize(14);
    tasksItem->setFont(font2);
    tasksItem->setIcon(QIcon("C:/Users/realm/OneDrive/Documents/QtProjects/todolist2-without-ui/icons/home icon.jpg"));

    QListWidgetItem *groceryItem = new QListWidgetItem("Groceries");
    QFont font3 = groceryItem->font();
    font3.setPointSize(14);
    groceryItem->setFont(font3);
    groceryItem->setIcon(QIcon("C:/Users/realm/OneDrive/Documents/QtProjects/todolist2-without-ui/icons/grocery icon.png"));

    menuList->addItem(myDayItem);
    menuList->addItem(importantItem);
    menuList->addItem(tasksItem);
    menuList->addItem(groceryItem);

    menuList->setStyleSheet(
        "QListWidget::item {"
        "   height: 20px;"
        "   padding: 10px;"
        "   font-size: 18px;"
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

    contentArea->setStyleSheet("background-image: url('C:/Users/realm/OneDrive/Documents/QtProjects/todolist2-without-ui/images/nature theme 3.jpg');"
                               "background-repeat: no-repeat;"
                               "background-position: center;"
                               "background-size: 500px 500px;");

    QLabel *contentLabel = new QLabel("Main Content Area", contentArea);
    contentLabel->setAlignment(Qt::AlignCenter);
    contentLayout->addWidget(contentLabel);

    // Layout: Sidebar and Content
    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(sidebar);
    splitter->addWidget(contentArea);
    splitter->setStretchFactor(1, 1);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0,0,0,0);
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

