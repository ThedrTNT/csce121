#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "School.h"
#include "AttendanceRecord.h"

using namespace std;

void School::addStudents(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');
    string name;
    getline(ss, name);
    if (!ss.fail()) {
      students.push_back(Student(uin, name));
    }
  }
}

void School::listStudents() {
  if (students.size() == 0) {
    cout << "No Students" << endl;
    return;
  }
  for(size_t i = 0; i < students.size(); ++i) {
    cout << students.at(i).get_id() << "," << students.at(i).get_name() << endl;
  }
}

void School::addCourses(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string id;
    getline(ss, id, ',');

    string startHourString;
    getline(ss, startHourString, ':');
    istringstream sHss(startHourString);
    int startHour;
    sHss >> startHour;

    string startMinuteString;
    getline(ss, startMinuteString, ',');
    istringstream sMss(startMinuteString);
    int startMinute;
    sMss >> startMinute;

    string endHourString;
    getline(ss, endHourString, ':');
    istringstream eHss(endHourString);
    int endHour;
    eHss >> endHour;

    string endMinuteString;
    getline(ss, endMinuteString, ',');
    istringstream eMss(endMinuteString);
    int endMinute;
    eMss >> endMinute;

    string title;
    getline(ss, title);

    Date startTime(startHour, startMinute, 0);
    Date endTime(endHour, endMinute, 0);

    if (!ss.fail()) {
      courses.push_back(Course(id, title, startTime, endTime));
    }
  }
}

void School::listCourses() {
  if (courses.size() == 0) {
    cout << "No Courses" << endl;
    return;
  }
  for(size_t i = 0; i < courses.size(); ++i) {
    Course printCourse = courses.at(i);

    string id = printCourse.getID();
    string title = printCourse.getTitle();
    Date startTime = printCourse.getStartTime();
    Date endTime = printCourse.getEndTime();

    cout << id << "," << startTime.getTime(false) << "," << endTime.getTime(false) << "," << title << endl;
  }
}

void School::addAttendanceData(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);

    string yearString;
    getline(ss, yearString, '-');
    istringstream yearSS(yearString);
    int year;
    yearSS >> year;

    string monthString;
    getline(ss, monthString, '-');
    istringstream monthSS(monthString);
    int month;
    monthSS >> month;

    string dayString;
    getline(ss, dayString, ' ');
    istringstream daySS(dayString);
    int day;
    daySS >> day;

    string hourString;
    getline(ss, hourString, ':');
    istringstream hourSS(hourString);
    int hour;
    hourSS >> hour;

    string minuteString;
    getline(ss, minuteString, ':');
    istringstream minSS(minuteString);
    int minute;
    minSS >> minute;

    string secString;
    getline(ss, secString, ',');
    istringstream secSS(secString);
    int second;
    secSS >> second;

    string courseID;
    getline(ss, courseID, ',');

    string studentID;
    getline(ss, studentID);

    Date time(year, month, day, hour, minute, second);
    AttendanceRecord ar(courseID, studentID, time);

    if (!ss.fail()) {
      for (size_t i = 0; i < courses.size(); ++i) {
        if (courses.at(i).getID() == courseID) {
          courses.at(i).addAttendanceRecord(ar);
        }
      }
    }
  }
}

void School::outputCourseAttendance(string course_id) {
  for(size_t i = 0; i < courses.size(); ++i) {
    if(courses.at(i).getID() == course_id) {
      courses.at(i).outputAttendance();
      return;
    }
  }
}

void School::outputStudentAttendance(string student_id, string course_id) {
  for(size_t i = 0; i < courses.size(); ++i) {
    if(courses.at(i).getID() == course_id) {
      courses.at(i).outputAttendance(student_id);
      return;
    }
  }
  cout << "No Records" << endl;
}