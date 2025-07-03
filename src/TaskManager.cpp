#include "TaskManager.hpp"

TaskManager::TaskManager() 
    : m_users() 
{
    //empty
}

TaskManager::~TaskManager() {
    for (int i = 0; i < m_users.size(); ++i) {
        delete m_users[i];
    }
    m_users.clear();
}

void TaskManager::regitser_user(const std::string& username, const std::string& password) {
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i]->get_username() == username) {
            std::cout << "A user by " << username << " username already exists\n";
            return;
        }
    }
    m_users.emplace_back(new User(username, password));
}

void TaskManager::login(const std::string& username, const std::string& password) {
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i]->get_username() == username) {
            if (m_users[i]->get_password() == password) {
                m_users[i]->login();
                return;
            }
        }
    }
}

void TaskManager::logout(size_t user_id) {
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i]->get_user_id() == true) {
            if (m_users[i]->chech_login() == true) {
                m_users[i]->logout();
                return;
            }
            else {
                std::cout << m_users[i]->get_username() << " wasn't logged in\n";
                return;
            }
        }
    }
}

void TaskManager::add_task(const Task& task, size_t user_id) {
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i]->get_user_id() == user_id) {
            m_users[i]->add_task(task);
            return;
        }
    }
}

void TaskManager::delete_task(size_t task_id, size_t user_id) {
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i]->get_user_id() == user_id) {
            m_users[i]->delete_task(task_id);
            return;
        }
    }
}

void TaskManager::edit_task(size_t user_id, size_t task_id, const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, Task_Category newCategory, Task_Priority newPriority) {
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i]->get_user_id() == user_id) {
            m_users[i]->edit_task(task_id, newTitle, newDescription,newDeadline, newCategory, newPriority);
            return;
        }
    }
}

void TaskManager::set_task_status(size_t user_id, size_t task_id, Task_Status status) {
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i]->get_user_id() == user_id) {
            m_users[i]->set_task_status(task_id, status);
            return;
        }
    }
}

void TaskManager::list_tasks(size_t user_id) const {
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i]->get_user_id() == user_id) {
            m_users[i]->list_tasks();
            return;
        }
    }
}

/* tests */

bool TaskManager::is_user(std::string name) const {
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i]->get_username() == name) {
            return true;
        }
    }
    return false;
}

bool TaskManager::is_logged(size_t user_id) const {
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i]->get_user_id() == user_id) {
            if (m_users[i]->chech_login() == true) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}

