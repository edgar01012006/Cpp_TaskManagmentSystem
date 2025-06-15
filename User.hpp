#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>
#include <vector>

class User {
	private:
		static size_t m_id; // check later
		std::string m_name;
		std::string m_passwd;
		std::vector<Task*> m_tasks;
		bool is_logged;
	public:
		/* constructors */
		User(const std::string& username, const std::string& password);
		User(const User& rhs);
		User& operator=(const User& rhs);
		User(User&& rhs);
		User& operator=(User&& rhs);
		~User();

		/* methods */
		void add_task();
		void delete_task();
		void edit_task();
		void list_tasks();
		void search_task();
};

#endif /* USER_HPP */
