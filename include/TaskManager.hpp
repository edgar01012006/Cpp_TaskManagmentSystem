#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include <vector>
#include <string>
#include "User.hpp"

class TaskManager {
	private:
		std::vector<User*> m_users;
	public:
		TaskManager();
		~TaskManager();
		void regitser_user(const std::string& username, const std::string& password);
		void login(const std::string& username, const std::string& password);
		void logout(size_t user_id);
		void add_task(const Task& task, size_t user_id);
		void delete_task(size_t task_id, size_t user_id);
		void edit_task(size_t user_id, size_t task_id, const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, Task_Category newCategory, Task_Priority newPriority);
		void set_task_status(size_t user_id, size_t task_id, Task_Status status);
		void list_tasks(size_t user_id) const;
};


#endif /* TASKMANAGER_HPP */

