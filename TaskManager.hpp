#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

class TaskManager {
	private:
		std::vector<User*> m_users;
		std::vector<Task*> m_all_tasks;
	public:
		void regitser_user();
		void login();
		void logout();
		void add_task();
		void delete_task();
		void edit_task();
		void display_task();
};


#endif /* TASKMANAGER_HPP */

