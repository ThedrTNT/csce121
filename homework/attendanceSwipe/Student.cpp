#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(string student_id, string name) {
	this->name = name;
	id = student_id;
}

string Student::get_id() {
	return id;
}

string Student::get_name() {
	return name;
}

void Student::addCourse(string course_id) {
	course_ids.push_back(course_id);
}

void Student::listCourses() {
	if (course_ids.size() == 0) {
    	cout << "No Courses" << endl;
   		return;
  	}
  	for(size_t i = 0; i < course_ids.size(); ++i) {
    	cout << course_ids.at(i) << endl;
  	}
}