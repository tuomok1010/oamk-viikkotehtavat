#include "student.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
            case 0:
            {
                // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
                // Lisää uusi student StudentList vektoriin.
                std::string name{};
                int age{};

                std::cout << "Enter name> ";
                std::cin >> name;
                std::cout << "Enter Age> ";
                std::cin >> age;

                studentList.emplace_back(Student(name, age));

            } break;

            case 1:
            {
                // Tulosta StudentList vektorin kaikkien opiskelijoiden
                // nimet.
                for(auto& s : studentList)
                    s.printStudentInfo();

            } break;

            case 2:
            {
                // Järjestä StudentList vektorin Student oliot nimen mukaan
                // algoritmikirjaston sort funktion avulla
                // ja tulosta printStudentInfo() funktion avulla järjestetyt
                // opiskelijat
                std::sort(studentList.begin(), studentList.end(),
                          [](Student& a, Student& b){ return a.getName() < b.getName(); });

                for(auto& s : studentList)
                    s.printStudentInfo();

            } break;

            case 3:
            {
                // Järjestä StudentList vektorin Student oliot iän mukaan
                // algoritmikirjaston sort funktion avulla
                // ja tulosta printStudentInfo() funktion avulla järjestetyt
                // opiskelijat
                std::sort(studentList.begin(), studentList.end(),
                          [](Student& a, Student& b){ return a.getAge() < b.getAge(); });

                for(auto& s : studentList)
                    s.printStudentInfo();

            } break;

            case 4:
            {
                // Kysy käyttäjältä opiskelijan nimi
                // Etsi studentListan opiskelijoista algoritmikirjaston
                // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
                // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
                std::string name{};
                std::cout << "Enter name > ";
                std::cin >> name;
                std::cout << "\n";

                auto it = std::find_if(studentList.begin(), studentList.end(),
                                       [name](Student& s){ return name.compare(s.getName()) == 0; });
                if(it != studentList.end())
                {
                    (*it).printStudentInfo();
                }

            } break;

            default:
            {
                cout<< "Wrong selection, stopping..."<<endl;
            } break;
        }
    } while(selection < 5);

    return 0;
}
