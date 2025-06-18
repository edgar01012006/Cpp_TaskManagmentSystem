#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Task.hpp"

class User {
	private:
		static size_t m_id; // check later
		std::string m_username;
		std::string m_password;
		std::vector<Task*> m_tasks;
		bool is_logged; // 1 == logged, 0 == not logged
	public:
		/* constructors */
		User(const std::string& username, const std::string& password);
		User(const User& rhs, const std::string& username, const std::string& password);
		User& operator=(const User& rhs);
		User(User&& rhs, const std::string& username, const std::string& password);
		User& operator=(User&& rhs);
		~User();

		/* methods */
		void add_task(Task* task);
		void delete_task(size_t task_id);
		void edit_task(size_t task_id, const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, Task_Category newCategory, Task_Priority newPriority);
		void list_tasks() const;
		void search_task(size_t task_id) const;
		std::string get_username() const;
		std::string get_password() const;
		void login();
		void logout();
};

#endif /* USER_HPP */
