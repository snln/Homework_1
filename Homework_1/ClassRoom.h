#pragma once
#include <iostream>;
using namespace std;

class ClassRoom
{
private:
	char* teacher;
	char* subject;
	char* theme;
	unsigned int students;
	double area;

public:
	ClassRoom()
	{
		area = 46.5;
		students = 22;
		teacher = new char[100];
		strcpy_s(teacher, 99, "Alex");
		subject = new char[100];
		strcpy_s(subject, 99, "C++");
		theme = new char[100];
		strcpy_s(theme, 99, "OOP");
	}
	ClassRoom(const char* teacher, const char* subject,
		const char* theme, double area, unsigned int students)
	{
		SetTeacher(teacher);
		SetSubject(subject);
		SetTheme(theme);
		SetArea(area);
		SetStudents(students);
	}

	~ClassRoom()
	{
		if (teacher != nullptr) delete[] teacher;
		if (subject != nullptr) delete[] subject;
		if (theme != nullptr) delete[] theme;
	}

	void Show() const
	{
		cout << "Welcome to the  " << subject << " class, today's theme is " << theme << ". Your teacher is " << teacher << ".\n";
	}
	void ReplaceTeacher() const
	{
		cout << "HERESY!\n";
	}
	void AskQuestion() const
	{
		cout << "You've raised your hand and asked a question.\n";
	}
	void StudentJoin()
	{
		cout << "Someone's joined the lesson.\n";
		SetStudents(GetStudents() + 1);
	}
	void StudentLeft()
	{
		cout << "Someone's left :c\n";
		SetStudents(GetStudents() - 1);
	}

	void SetTeacher(const char* teacher)
	{
		if (strlen(teacher) == 0)
			throw "Oops! Incorrect value for teacher!\n";

		this->teacher = new char[100];
		strcpy_s(this->teacher, 99, teacher);
	}
	void SetSubject(const char* subject)
	{
		if (strlen(subject) == 0)
			throw "Oops! Incorrect value for subject!\n";

		this->subject = new char[100];
		strcpy_s(this->subject, 99, subject);
	}
	void SetTheme(const char* theme)
	{
		if (strlen(theme) == 0)
			throw "Oops! Incorrect value for theme!\n";

		this->theme = new char[100];
		strcpy_s(this->theme, 99, theme);
	}
	void SetArea(double area)
	{
		if (area < 0)
			throw "Oops! Incorrect value for area!\n";

		this->area = area;
	}
	void SetStudents(unsigned int students)
	{
		if (students <= 0)
			throw "Oops! Incorrect value for students!\n";

		this->students = students;
	}


	unsigned int GetStudents() const
	{
		return students;
	}
	double GetArea() const
	{
		return area;
	}
	string GetTeacher() const
	{
		return teacher;
	}
	string GetSubject() const
	{
		return subject;
	}
	string GetTheme() const
	{
		return theme;
	}
};