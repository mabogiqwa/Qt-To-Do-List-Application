#include "mainwindow.h"
#include "taskinputwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("To-Do List Application");

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setStyleSheet("background-color: #2E2E2E;");

    QWidget *sidebar = new QWidget(this);
    sidebar->setFixedWidth(280);
    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebar);
    sidebarLayout->setSpacing(0);
    sidebarLayout->setContentsMargins(0,0,0,0);

    QWidget *searchWidget = new QWidget(sidebar);
    QHBoxLayout *searchLayout = new QHBoxLayout(searchWidget);
    searchLayout->setContentsMargins(0,0,0,0);

    QLineEdit *searchInput = new QLineEdit(searchWidget);
    searchInput->setPlaceholderText("Search for task");
    searchInput->setFixedWidth(280);
    searchInput->setFixedHeight(40);

    searchLayout->addWidget(searchInput);
    searchWidget->setLayout(searchLayout);

    QAction *searchAction = new QAction(searchInput);
    searchAction->setIcon(style()->standardIcon(QStyle::SP_FileDialogContentsView));
    searchInput->addAction(searchAction, QLineEdit::TrailingPosition);

    QListWidget *menuList = new QListWidget(sidebar);

    //Items definition
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
    contentArea = new QWidget(this);
    //QVBoxLayout *contentLayout = new QVBoxLayout(contentArea);

    QLabel *contentLabel = new QLabel(contentArea);
    contentLabel->resize(150,30);
    contentLabel->move(35,45);
    contentLabel->setStyleSheet("QLabel { background: transparent; color: white; font-size: 15px; }");
    QDate currentDate = QDate::currentDate();
    QString dateString = currentDate.toString("dddd, MMMM d");
    contentLabel->setText(dateString);

    QLabel *title = new QLabel("My Day",contentArea);
    title->resize(200,50);
    title->move(35,5);
    title->setStyleSheet("QLabel {background: transparent; color: white; font-size: 28px; font-weight: bold; }");

    contentArea->setStyleSheet("background-image: url('C:/Users/realm/OneDrive/Documents/QtProjects/todolist2-without-ui/images/nature theme 3.jpg');"
                               "background-repeat: no-repeat;"
                               "background-position: center;"
                               "background-size: 800px 800px;");

    imageLabel = new QLabel(contentArea);
    QPixmap pixmap("C:/Users/realm/OneDrive/Documents/QtProjects/todolist2-without-ui/icons/center.png");
    QPixmap scaledImage = pixmap.scaled(250,200,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imageLabel->setPixmap(scaledImage);
    imageLabel->resize(scaledImage.size());
    imageLabel->setStyleSheet("QLabel { background: transparent; }");
    imageLabel->move(200,200);

    TaskInputWidget *taskInput = new TaskInputWidget(contentArea, imageLabel);
    taskInput->setAttribute(Qt::WA_TranslucentBackground);
    taskInput->setAutoFillBackground(false);
    taskInput->move(40,490);
    taskInput->resize(560,150);

    setupTasksArea();
    connect(taskInput, &TaskInputWidget::taskAdded, this, &MainWindow::addNewTask);

    // Layout: Sidebar and Content
    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(sidebar);
    splitter->addWidget(contentArea);
    splitter->setStretchFactor(1, 1);

    splitter->setHandleWidth(0);
    splitter->setStyleSheet("QSplitter::handle { background-color: none; }");

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(splitter);

    connect(menuList, &QListWidget::currentRowChanged, [contentLabel, dateString](int currentRow) {
        switch (currentRow) {
        case 0:
            contentLabel->setText(dateString);
            break;
        case 1:
            contentLabel->setText(dateString);
            break;
        case 2:
            contentLabel->setText(dateString);
            break;
        default:
            contentLabel->setText(dateString);
            break;
        }
    });
}

QSize MainWindow::sizeHint() const
{
    return QSize(900,850);
}

void MainWindow::setupTasksArea()
{
    tasksScrollArea = new QScrollArea(contentArea);
    tasksScrollArea->setStyleSheet(
        "QScrollArea {"
        "   background: transparent;"
        "   border: none;"
        "}"
        "QScrollArea > QWidget > QWidget {"
        "   background: transparent;"
        "}"
        "ScrollBar {"
        "  background: rgba(255,255,255,0.1);"
        "  width: 10px;"
        "}"
    );

    QWidget *viewport = new QWidget;
    viewport->setStyleSheet("background: transparent");
    tasksScrollArea->setViewport(viewport);


    tasksScrollArea->setWidgetResizable(true);
    tasksScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tasksScrollArea->move(25, 85);
    tasksScrollArea->resize(560, 390);

    tasksContainer = new QWidget(tasksScrollArea);
    tasksContainer->setStyleSheet("background: transparent");
    tasksLayout = new QVBoxLayout(tasksContainer);
    tasksLayout->setSpacing(5);
    tasksLayout->setContentsMargins(0,0,0,0);
    tasksLayout->addStretch();

    tasksScrollArea->setWidget(tasksContainer);
}

void MainWindow::addNewTask(const QString &taskText)
{
    TaskItemWidget *taskWidget = new TaskItemWidget(taskText, tasksContainer);
    tasksLayout->insertWidget(tasksLayout->count() - 1, taskWidget);
    connect(taskWidget, &TaskItemWidget::taskCompleted, this, &MainWindow::removeCompletedTask);
}

void MainWindow::removeCompletedTask(TaskItemWidget *widget)
{
    tasksLayout->removeWidget(widget);
    widget->deleteLater();

    bool hasVisibleTasks = false;
    for (int i = 0; i < tasksLayout->count(); i++)
    {
        if (QWidget *w = tasksLayout->itemAt(i)->widget()) {
            if(w->isVisible() && !qobject_cast<TaskItemWidget*>(w)) {
                hasVisibleTasks = true;
                break;
            }
        }
    }

    if (!hasVisibleTasks && imageLabel) {
        imageLabel->show();
    }
}

MainWindow::~MainWindow()
{
}
