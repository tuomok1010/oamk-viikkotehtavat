#include "student.h"
#include <iostream>

Student::Student(std::string name, int age) : Name(name), Age(age)
{

}

void Student::setAge(int age)
{
    Age = age;
}

void Student::setName(std::string name)
{
    Name = name;
}

std::string Student::getName()
{
    return Name;
}

int Student::getAge()
{
    return Age;
}

void Student::printStudentInfo()
{
    std::cout << "Student " << Name << " Age " << Age << std::endl;
}
