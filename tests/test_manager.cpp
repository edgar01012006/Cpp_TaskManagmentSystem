#include <gtest/gtest.h>
#include "../include/TaskManager.hpp"

TEST(ManagerTest, Registration) {
    TaskManager manager;
    manager.regitser_user("Edgar", "pass1234");
    manager.regitser_user("Arman", "pass1111");
    EXPECT_TRUE(manager.is_user("Edgar"));
    EXPECT_FALSE(manager.is_user("Robert"));
}

TEST(ManagerTest, Login) {
    TaskManager manager;
    manager.regitser_user("Edgar", "pass1234");
    manager.login("Edgar", "pass1234");
    EXPECT_TRUE(manager.is_logged(3));
}

TEST(ManagerTest, AddingTasks) {
    TaskManager manager;
    manager.regitser_user("Edgar", "pass1234");
    manager.login("Edgar", "pass1234");
    size_t Edgar_id = 4;
    Task task1("Task1", "Buy Groceries", "6/18/2025", Task_Category::PERSONAL, Task_Priority::HIGH); 
    Task task2("Task2", "Build a TaskManagment", "6/19/2025", Task_Category::STUDY, Task_Priority::URGENT);
    manager.add_task(task1, Edgar_id);
    manager.add_task(task2, Edgar_id);
    std::cout << "Edgar's tasks\n";
    manager.list_tasks(Edgar_id);
    manager.edit_task(Edgar_id, task1.get_task_id(), "Task1" , "Buy Groceries", "6/20/2025", Task_Category::PERSONAL, Task_Priority::MID);
    manager.set_task_status(Edgar_id, task2.get_task_id(), Task_Status::COMPLETED);
    std::cout << "Edgar's tasks after updating task1 and task 2\n";
    manager.list_tasks(Edgar_id);
    manager.delete_task(task2.get_task_id(), Edgar_id);
    std::cout << "Edgar's tasks after deleting task2\n";
    manager.list_tasks(Edgar_id);
    manager.logout(Edgar_id);
}