#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include <string>

enum class Task_Category {
	NONE,
	WORK,
	STUDY,
	PERSONAL
};

enum class Task_Priority {
	NONE,
	LOW,
	MID,
	HIGH,
	URGENT
};

enum class Task_Status {
	NONE,
	NOT_STARTED,
	IN_PROGRESS,
	COMPLETED
};

class Task {
	private:
		static size_t m_task_id; // check later
		//std::string m_user_id; // user id why? what's the need for it?
		std::string m_title; 
		std::string m_description;
		std::string m_deadline; 
		Task_Category m_category;
		Task_Priority m_priority;
		Task_Status m_status;
	public:
		/* constructors */
		Task(const std::string& title, const std::string& description, const std::string& deadline, Task_Category category, Task_Priority priority);
		Task(const Task& rhs);
		Task& operator=(const Task& rhs);
		Task(Task&& rhs);
		Task& operator=(Task&& rhs);
		~Task();

		/* methods */
		void edit(const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, Task_Category newCategory, Task_Priority newPriority);
		void set_status(Task_Status status);
		void set_priority(Task_Priority priority);
		std::string categoryToString(Task_Category category) const;
		std::string priorityToString(Task_Priority priority) const;
		std::string statusToString(Task_Status status) const;
		void display_info() const;
		size_t get_task_id() const;
};

#endif /* TASK_HPP */

