#include "student.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    std::vector<Student> students;
    while (!inputFile.eof()) {
        std::string name;
        inputFile >> name;
        std::vector<int> grades;
        for (int i = 0; i < 4; ++i) {
            int grade;
            inputFile >> grade;
            grades.push_back(grade);
        }
        Student newStudent(name, grades);
        students.push_back(newStudent);
    }


    // Сортировка студентов по среднему баллу
    std::sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.calculateAverageGrade() > s2.calculateAverageGrade();
        });

    // Вывод трех самых сильных студентов
    for (int i = 0; i < 3 && i < students.size(); ++i) {
        students[i].printInfo();
    }

    inputFile.close();
    outputFile.close();
    return 0;
}