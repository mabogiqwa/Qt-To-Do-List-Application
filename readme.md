# To-Do List Application

A modern, sleek task management application built with Qt/C++ that helps you organize your daily tasks with a beautiful user interface.

![Application Screenshot](screenshots/app_screenshot.png)

## Features

- **Intuitive Task Management**: Easily add, view, and complete tasks
- **Category Organization**: Sort tasks by different categories (My Day, Important, Tasks, Groceries)
- **Elegant UI**: Modern dark theme with translucent elements and smooth animations
- **Task Completion Animation**: Satisfying fade-out animation when tasks are marked as complete
- **Search Functionality**: Quickly find tasks with the integrated search bar
- **Date Integration**: Shows current date automatically in header

## Requirements

- Qt 5.12 or higher
- C++11 compatible compiler
- Qt Creator 4.8 or higher (recommended for development)

## Installation

### Building from Source

1. Clone the repository:
```bash
git clone https://github.com/yourusername/todo-list-app.git
cd todo-list-app
```

2. Open the project in Qt Creator:
```bash
qtcreator todo-list-app.pro
```

3. Configure the project for your kit and build

### Binary Installation

Pre-built binaries are available for:
- Windows 10/11
- macOS 10.14+
- Ubuntu 20.04+

Download the latest release from the [Releases](https://github.com/yourusername/todo-list-app/releases) page.

## Usage

### Adding Tasks

1. Type your task in the input field at the bottom of the window
2. Press Enter to add the task to your list
3. The application supports natural language input like "Pay electricity bill by Friday 6pm"

### Completing Tasks

1. Click the checkbox next to any task to mark it as complete
2. The task will fade out and be removed from your list

### Navigating Categories

Use the sidebar to navigate between different task categories:
- **My Day**: Tasks for today
- **Important**: High priority tasks
- **Tasks**: All tasks
- **Groceries**: Shopping list items

## Project Structure

The application consists of several key components:

- `MainWindow`: Main application window that contains the sidebar and content area
- `TaskInputWidget`: Handles task creation and input
- `TaskItemWidget`: Displays individual tasks with completion checkboxes
- Custom styling for a cohesive dark theme experience

## Customization

### Theme Customization

The application uses a dark theme by default, but you can modify the color scheme in `main.cpp`:

```cpp
a.setStyleSheet(
    "QWidget {"
    "   color: white;"  // Change text color
    "   background-color: #2E2E2E;"  // Change background color
    "}"
);
```

### Background Images

To change the background image, modify the following line in `mainwindow.cpp`:

```cpp
contentArea->setStyleSheet("background-image: url('path/to/your/image.jpg');");
```

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Icon assets from [source/attribution]
- Background image from [source/attribution]
- Inspiration from Microsoft To Do and other modern task management applications
