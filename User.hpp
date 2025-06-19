#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Task.hpp"

class User {
	private:
		static size_t counter_m_id;
		size_t m_id;
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
		void add_task(const Task& task);
		void delete_task(size_t task_id);
		void edit_task(size_t task_id, const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, Task_Category newCategory, Task_Priority newPriority);
		void set_task_status(size_t task_id, Task_Status status);
		void list_tasks() const;
		void search_task(size_t task_id) const;
		std::string get_username() const;
		std::string get_password() const;
		size_t get_user_id() const;
		bool chech_login() const;
		void login();
		void logout();
};

#endif /* USER_HPP */
