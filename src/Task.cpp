#include "Task.hpp"

size_t Task::count_m_task_id = 0;

Task::Task(const std::string& title, const std::string& description, const std::string& deadline, Task_Category category, Task_Priority priority) 
    : m_title { title }
    , m_description { description }
    , m_deadline { deadline }
    , m_category { category }
    , m_priority { priority }
    , m_task_id { ++count_m_task_id }
{
    //empty
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

/* methods */

void Task::edit(const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, Task_Category newCategory, Task_Priority newPriority) 
{
    m_title = newTitle;
    m_description = newDescription;
    m_deadline = newDeadline;
    m_category = newCategory;
    m_priority = newPriority;
}

void Task::set_status(Task_Status status) {
    m_status = status;
}

void Task::set_priority(Task_Priority priority) {
    m_priority = priority;
}

std::string Task::categoryToString(Task_Category category) const {
    switch (category) {
        case Task_Category::NONE: return "NONE";
        case Task_Category::WORK: return "WORK";
        case Task_Category::STUDY: return "STUDY";
        case Task_Category::PERSONAL: return "PERSONAL";
    }
    return "NONE";
}

std::string Task::priorityToString(Task_Priority priority) const {
    switch (priority) {
        case Task_Priority::NONE: return "NONE";
        case Task_Priority::LOW: return "LOW";
        case Task_Priority::MID: return "MID";
        case Task_Priority::HIGH: return "HIGH";
        case Task_Priority::URGENT: return "URGENT";
    }
    return "NONE";
}
std::string Task::statusToString(Task_Status status) const {
    switch (status) {
        case Task_Status::NONE: return "NONE";
        case Task_Status::NOT_STARTED: return "NOT_STARTED";
        case Task_Status::IN_PROGRESS: return "IN_PROGRESS";
        case Task_Status::COMPLETED: return "COMPLETED";
    }
    return "NONE";
}

void Task::display_info() const {
    std::cout << "Title: " << m_title << "\nDescription: " << m_description << "\nDeadline: " << m_deadline << "\nCategory: " << categoryToString(m_category) << "\nPriority: " << priorityToString(m_priority) << "\nStatus: " << statusToString(m_status) << "\nTask ID: " << m_task_id << std::endl;
}

size_t Task::get_task_id() const {
    return m_task_id;
}