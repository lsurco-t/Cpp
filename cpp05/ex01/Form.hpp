#pragma once
#include <iostream>

class Form {

	private:
		const std::string _name;
		bool  			  _isSigned;
		const int         _signGrade;
		const int		  _executeGrade;

	public:
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string& getName(void);
		bool getIsSigned(void);
		const int getSignGrade(void);
		const int getExecuteGrade(void); 

};

std::ostream& operator<<(std::ostream& out, const Form& f);