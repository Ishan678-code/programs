#include <iostream>
#include <vector>
struct Task {
    std::string description;
    std::string dueDate;
    bool isCompleted;
};
std::vector<Task> tasks;
void displayMenu() {
    std::cout << "To-Do List Menu:" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. Remove Task" << std::endl;
    std::cout << "3. Mark Task as Completed" << std::endl;
    std::cout << "4. View Tasks" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}
void addTask() {
    Task newTask;
    std::cout << "Enter task description: ";
    std::cin >> newTask.description;
    // You can add due date input and initialize isCompleted as needed.
    tasks.push_back(newTask);
    std::cout << "Task added successfully!" << std::endl;
}
void removeTask() {
    int index;
    std::cout << "Enter the index of the task to remove: ";
    std::cin >> index;
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        std::cout << "Task removed successfully!" << std::endl;
    } else {
        std::cout << "Invalid index. Task not found." << std::endl;
    }
}
void markTaskAsCompleted() {
    int index;
    std::cout << "Enter the index of the task to mark as completed: ";
    std::cin >> index;
    if (index >= 0 && index < tasks.size()) {
        tasks[index].isCompleted = true;
        std::cout << "Task marked as completed!" << std::endl;
    } else {
        std::cout << "Invalid index. Task not found." << std::endl;
    }
}
void viewTasks() {
    for (size_t i = 0; i < tasks.size(); i++) {
        std::cout << "Task " << i << ": ";
        if (tasks[i].isCompleted) {
            std::cout << "[Completed] ";
        }
        std::cout << tasks[i].description << std::endl;
    }
}
int main() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                viewTasks();
                break;
            case 5:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
