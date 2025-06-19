#include "User.hpp"

size_t User::counter_m_id = 0;

User::User(const std::string& username, const std::string& password) 
    : m_username { username }
    , m_password { password }
    , m_tasks()
    , m_id { ++counter_m_id }
{
    //empty;
}

User::User(const User& rhs, const std::string& username, const std::string& password) 
    : m_username { username }
    , m_password { password }
    , m_tasks { rhs.m_tasks }
    , m_id { ++counter_m_id }
{
    //empty
}

User& User::operator=(const User& rhs) {
    if (this == &rhs) {
        return *this;
    }
    m_tasks = rhs.m_tasks;
    return *this;
}

User::User(User&& rhs, const std::string& username, const std::string& password) 
    : m_username { username }
    , m_password { password }
    , m_tasks { std::move(rhs.m_tasks) }
    , m_id { ++counter_m_id }
{
    //empty
}

User& User::operator=(User&& rhs) {
    if (this == &rhs) {
        return *this;
    }
    m_tasks = std::move(rhs.m_tasks);
    return *this;
}

User::~User() {
    for (int i = 0; i < m_tasks.size(); ++i) {
        delete m_tasks[i];
    }
    m_tasks.clear();
}

/* methods */

void User::add_task(const Task& task) {
    m_tasks.emplace_back(new Task(task));
}

void User::delete_task(size_t task_id) {
    for (int i = 0; i < m_tasks.size(); ++i) {
        if (m_tasks[i]->get_task_id() == task_id) {
            delete m_tasks[i];
            m_tasks.erase(m_tasks.begin() + i);
            return;
        }
    }
}

void User::edit_task(size_t task_id, const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, Task_Category newCategory, Task_Priority newPriority) {
    for (int i = 0; i < m_tasks.size(); ++i) {
        if (m_tasks[i]->get_task_id() == task_id) {    
            m_tasks[i]->edit(newTitle, newDescription, newDeadline, newCategory, newPriority);
            return;
        }
    }
}

void User::set_task_status(size_t task_id, Task_Status status) {
    for (int i = 0; i < m_tasks.size(); ++i) {
        if (m_tasks[i]->get_task_id() == task_id) {
            m_tasks[i]->set_status(status);
            return; 
        }
    }
}

void User::list_tasks() const {
    for (int i = 0; i < m_tasks.size(); ++i) {
        m_tasks[i]->display_info();
    }
}

void User::search_task(size_t task_id) const {
    for (int i = 0; i < m_tasks.size(); ++i) {
        if (m_tasks[i]->get_task_id() == task_id) {
            m_tasks[i]->display_info();
            return;
        }
    }
}

std::string User::get_username() const {
    return m_username;
}

std::string User::get_password() const {
    return m_password;
}

size_t User::get_user_id() const {
    return m_id;
}

bool User::chech_login() const {
    return is_logged;
}

void User::login() {
    is_logged = 1;
}

void User::logout() {
    is_logged = 0;
}