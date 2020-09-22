#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>

#include "grade_calculator.h"

////////////////////////////////////////////////////////////////////////////////
// TODO(student): implement these methods

double GradeCalculator::exam_average() const {
    double examSum = 0;
    for(unsigned int i = 0; i < exam_grades.size(); ++i) {
        examSum += exam_grades.at(i);
    }
    if(has_final_exam) {
        examSum += final_exam;
    }
    double examFAvg = examSum/(exam_grades.size() + 1);

    if(final_exam > examFAvg) {
        return final_exam;
    }

    return examFAvg;
} 

double GradeCalculator::zybook_average() const {
    double zybookPreSum = 0;
    for(unsigned int i = 0; i < zybook_participation_grades.size(); ++i) {
        zybookPreSum += zybook_participation_grades.at(i);
    }
    for(unsigned int i = 0; i < zybook_challenge_grades.size(); ++i) {
        zybookPreSum += zybook_challenge_grades.at(i);
    }
    double zybookSize = zybook_participation_grades.size() + zybook_challenge_grades.size();
    double zybookPreAvg = zybookPreSum / zybookSize;
    double zybookAvg = zybookPreAvg + 15;
    if (zybookAvg >= 100) {
        return 100;
    }
    return zybookAvg;
}

double GradeCalculator::hw_average() const {
    double hwSum = 0;
    for (unsigned int i = 0; i < hw_grades.size(); ++i) {
        double grade = hw_grades.at(i);
        if ((i < hw_redemption_grades.size()) && (hw_redemption_grades.at(i) - grade)/2 > 0) {
            grade += (hw_redemption_grades.at(i) - grade)/2;
        }
        hwSum += grade;
    }
    return hwSum/hw_grades.size();
}

double GradeCalculator::lw_average() const {
    double lwSum = 0;
    for (unsigned int i = 0; i < lw_grades.size(); ++i) {
        if (lw_grades.at(i) == 1) {
            lwSum += 100;
        }
    }
    return lwSum/lw_grades.size();
}

// does not apply modifiers
double GradeCalculator::final_grade_numeric() const {
    double finalGrade = 0;
    finalGrade += exam_average() * .5;
    finalGrade += zybook_average() * .07;
    finalGrade += hw_average() * .35;
    finalGrade += lw_average() * .08;
    return finalGrade;
}

// includes application of modifiers
char GradeCalculator::final_grade_letter() const {
    double grade = final_grade_numeric();
    if (!has_syllabus_ack || grade < 60) {
        return 'F';
    }
    if (grade < 70 || exam_average() < 60) {
        return 'D';
    }
    if (grade < 80) {
        return 'C';
    }
    if (grade < 90) {
        return 'B';
    }
    return 'A';
}

////////////////////////////////////////////////////////////////////////////////

void GradeCalculator::read_final_exam(std::ifstream& fin) {
    has_final_exam = true;
    fin >> final_exam;
    if (fin.fail()) {
        throw std::runtime_error("failed to read final exam grade");
    }
}

void GradeCalculator::read_exam_hw_redemption_zybook(std::ifstream& fin, const std::string& category) {
    unsigned number;
    fin >> number;
    if (fin.fail()) {
        throw std::runtime_error("failed to read " + category + " number");
    }

    std::vector<double>* vec;
    if (category == "exam") {
        vec = &exam_grades;
    } else if (category == "hw") {
        vec = &hw_grades;
    } else if (category == "hw-redemption") {
        vec = &hw_redemption_grades;
    } else if (category == "zybook") {
        char type;
        fin >> type;
        if (fin.fail()) {
            // HOW TO REACH THIS?
            throw std::runtime_error("failed to read " + category + " type");
        }
        switch (type) {
            case 'p': vec = &zybook_participation_grades; break;
            case 'c': vec = &zybook_challenge_grades; break;
            default: throw std::runtime_error("unrecognized zybook assignment type: " + type);
        }
    } else {
        throw std::runtime_error("unrecognized category: " + category);
    }
    
    double grade;
    fin >> grade;
    if (fin.fail()) {
        throw std::runtime_error("failed to read "+category+" grade");
    }

    while (number > vec->size()) {
        vec->push_back(0);
    }

    vec->at(number-1) = grade;
}

void GradeCalculator::read_lw(std::ifstream& fin) {
    unsigned number;
    fin >> number;
    if (fin.fail()) {
        throw std::runtime_error("failed to read lw number");
    }

    std::string str;
    fin >> str;
    if (fin.fail()) {
        // HOW TO REACH THIS?
        throw std::runtime_error("failed to read lw grade");
    }

    while (number > lw_grades.size()) {
        lw_grades.push_back(false);
    }

    if (str == "0" || str == "false") {
        lw_grades.at(number-1) = false;
    } else if (str == "1" || str == "true") {
        lw_grades.at(number-1) = true;
    } else {
        throw std::runtime_error("invalid lw grade value: " + str);
    }
}

void GradeCalculator::read_syllabus_ack(std::ifstream& fin) {
    std::string str;
    fin >> str;
    if (fin.fail()) {
        // HOW TO REACH THIS?
        throw std::runtime_error("failed to read syllabus-ack type");
    }
    if (str == "0" || str == "false") {
        has_syllabus_ack = false;
    } else if (str == "1" || str == "true") {
        has_syllabus_ack = true;
    } else {
        throw std::runtime_error("invalid syllabus-ack grade value: " + str);
    }
}

void GradeCalculator::load_grades(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        throw std::runtime_error("could not open file");
    }
    while (!fin.eof()) {
        std::string category;
        fin >> category;
        if (fin.fail()) {
            if (fin.eof()) {
                continue;
            } 
            // HOW TO REACH THIS?
            throw std::runtime_error("failed to read category");
        }
        if (category == "final-exam") {
            read_final_exam(fin);
        } else if (category == "exam" || category == "hw" || category == "hw-redemption" || category == "zybook") {
            read_exam_hw_redemption_zybook(fin, category);
        } else if (category == "lw") {
            read_lw(fin);
        } else if (category == "syllabus-ack") {
            read_syllabus_ack(fin);
        } else {
            throw std::runtime_error("invalid category: " + category);
        }
    }
}