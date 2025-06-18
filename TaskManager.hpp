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
		void logout(const std::string& username, const std::string& password);
		void add_task();
		void delete_task();
		void edit_task();
		void display_task();
};


#endif /* TASKMANAGER_HPP */

