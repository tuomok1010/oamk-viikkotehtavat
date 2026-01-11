#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
    public:
    Student(std::string name, int age);

    void setAge(int age);
    void setName(std::string name);
    std::string getName();
    int getAge();
    void printStudentInfo();

    private:
    std::string Name;
    int Age;
};

#endif // STUDENT_H
