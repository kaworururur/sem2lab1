#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>

class Student {
private:
    std::string fio;
    std::vector<int> examScores;
public:
    Student();
    void set(std::string fio, std::vector<int> scores);
    double calculateAverageScore();
    void printInfo();
};

#endif