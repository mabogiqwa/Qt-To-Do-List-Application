#include "taskinputwidget.h"

TaskInputWidget::TaskInputWidget(QWidget *parent, QLabel *existingImage)
    : QWidget{parent}, placeholderImage(existingImage)
{
    setupUI();
}

void TaskInputWidget::setupUI() {
    mainLayout = new QVBoxLayout(this);

    inputField = new QLineEdit(this);
    inputField->setPlaceholderText("Try typing 'Pay electricity bill by Friday 6pm'");
    inputField->setStyleSheet(
        "QLineEdit {"
        "   padding: 10px;"
        "   padding-left: 40px;"
        "   border-radius: 20px;"
        "   background-color: rgba(0,0,0,0.5);"
        "   color: white;"
        "   font-size: 14px;"
        "}"
        );

    taskList = new QListWidget(this);
    taskList->setStyleSheet(
                "QListWidget {"
                "   background: transparent;"
                "   border: none;"
                "}"
    );

    mainLayout->addWidget(inputField);
    mainLayout->addWidget(taskList);

    connect(inputField, &QLineEdit::returnPressed, this, &TaskInputWidget::handleTaskInput);
}

void TaskInputWidget::handleTaskInput() {
    QString taskText = inputField->text().trimmed();
    if (!taskText.isEmpty()) {
        QListWidgetItem *item = new QListWidgetItem(taskText);
        taskList->addItem(item);
        inputField->clear();

        if (taskList->count() == 1 && placeholderImage) {
            placeholderImage->hide();
        }

        emit taskAdded(taskText);
    }
}
