#include "Task.hpp"

size_t Task::m_task_id = 0;

Task::Task(const std::string& title, const std::string& description, const std::string& deadline, Task_Category category, Task_Priority priority) 
    : m_title { title }
    , m_description { description }
    , m_deadline { deadline }
    , m_category { category }
    , m_priority { priority } 
{
    ++m_task_id;
}

Task::Task(const Task& rhs) 
    : m_title { rhs.m_title }
    , m_description { rhs.m_description }
    , m_deadline { rhs.m_deadline }
    , m_category { rhs.m_category }
    , m_priority { rhs.m_priority } 
{
    m_task_id = rhs.m_task_id;
}   

Task& Task::operator=(const Task& rhs) {
    if (this == &rhs) {
        return *this;
    }
    m_task_id = rhs.m_task_id;
    m_title = rhs.m_title;
    m_description = rhs.m_description;
    m_deadline = rhs.m_deadline;
    m_category = rhs.m_category;
    m_priority = rhs.m_priority;
    m_status = rhs.m_status;
    return *this;
}

Task::Task(Task&& rhs)
    : m_title { std::move(rhs.m_title) }
    , m_description { std::move(rhs.m_description) }
    , m_deadline { std::move(rhs.m_deadline) }
    , m_category { rhs.m_category }
    , m_priority { rhs.m_priority }
    , m_status { rhs.m_status }
{
    m_task_id = rhs.m_task_id;

    rhs.m_task_id = 0;
    rhs.m_category = Task_Category::NONE;
    rhs.m_priority = Task_Priority::NONE;
    rhs.m_status = Task_Status::NONE;
}

Task& Task::operator=(Task&& rhs) {
    if (this == &rhs) {
        return *this;
    }
    m_task_id = rhs.m_task_id;
    m_title = std::move(rhs.m_title);
    m_description = std::move(rhs.m_description);
    m_deadline = std::move(rhs.m_deadline);
    m_category = rhs.m_category;
    m_priority = rhs.m_priority;
    m_status = rhs.m_status;

    rhs.m_task_id = 0;
    rhs.m_category = Task_Category::NONE;
    rhs.m_priority = Task_Priority::NONE;
    rhs.m_status = Task_Status::NONE;
    return *this;
}


Task::~Task() {
    //empty;
}