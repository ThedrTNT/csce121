#include <iostream>
#include <fstream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using namespace std;

Course::Course(string id, string title, Date startTime, Date endTime) : id(id), title(title), startTime(startTime), endTime(endTime) {

}

string Course::getID() {
	return id;
}

string Course::getTitle() {
	return title;
}

Date Course::getStartTime() {
	return startTime;
}

Date Course::getEndTime() {
	return endTime;
}

void Course::addAttendanceRecord(AttendanceRecord ar) {
	if(ar.getDate() > endTime || ar.getDate() < startTime) {
		cout << "did not save this record." << endl;
		return;
	}

	attendanceRecords.push_back(ar);
}

void Course::outputAttendance() {
	if (attendanceRecords.size() == 0) {
    	cout << "No Records" << endl;
   		return;
  	}
  	for(size_t i = 0; i < attendanceRecords.size(); ++i) {
  		AttendanceRecord record = attendanceRecords.at(i);
  		string courseID = record.getCourseID();
  		string studentID = record.getStudentID();
  		Date time = record.getDate();
    	cout << time.getDateTime() << "," << courseID << "," << studentID << endl;
  	}
}

void Course::outputAttendance(string student_id) {
	bool records = false;
	if (attendanceRecords.size() == 0) {
    	cout << "No Records" << endl;
   		return;
  	}
  	for(size_t i = 0; i < attendanceRecords.size(); ++i) {
  		AttendanceRecord record = attendanceRecords.at(i);
  		string courseID = record.getCourseID();
  		string studentID = record.getStudentID();
  		Date time = record.getDate();

  		if(studentID == student_id) {
    		cout << time.getDateTime() << "," << courseID << "," << studentID << endl;
    		records = true;
  		}

  	}
  	if (!records) {
  		cout << "No Records" << endl;
  	}
}