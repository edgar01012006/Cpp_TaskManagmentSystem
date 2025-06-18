#include "TaskManager.hpp"

TaskManager::TaskManager() 
    : m_users { nullptr } 
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
    m_users.emplace_back(new User(username, password));
}

void TaskManager::login(const std::string& username, const std::string& password) {
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i]->get_username() == username) {
            if (m_users[i]->get_password() == password) {
                m_users[i]->login();
            }
        }
    }
}

void TaskManager::logout(const std::string& username, const std::string& password) {
    for (int i = 0; i < m_users.size(); ++i) {
        if (m_users[i]->get_username() == username) {
            if (m_users[i]->get_password() == password) {
                m_users[i]->logout();
            }
        }
    }
}