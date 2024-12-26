#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "student.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::fstream file;
    file.open("input.txt", std::ios::in);

    if (file.is_open()) {
        file >> n;
        std::vector<Student> students(n);

        for (int i = 0; i < n; i++) {
            std::string fio;
            std::vector<int> scores(4);
            file >> fio;
            for (int j = 0; j < 4; j++) {
                file >> scores[j];
            }
            students[i].set(fio, scores);
        }

        file.close();

        // Печать параметров всех студентов
        for (int i = 0; i < n; i++) {
            students[i].printInfo();
        }

        // Сортировка по среднему баллу в убывающем порядке
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.calculateAverageScore() > b.calculateAverageScore();
            });

        // Печать параметров трех самых сильных студентов
        std::cout << "Три самых сильных студента:" << std::endl;
        for (int i = 0; i < std::min(3, n); i++) {
            students[i].printInfo();
        }
    }
    else {
        std::cout << "Ошибка открытия файла" << std::endl;
    }

    return 0;
}