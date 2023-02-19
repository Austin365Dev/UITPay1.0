#include<iostream>
#include<string.h>
#include<vector>

using namespace std; 

class Student{
    public:
        string name; 
        int id_number; 
        int classroom;
        int points=0; 

    void view_points(){
        cout << "Your total points: " << points << endl;
    }

    void spend_points(int amount){
        if (amount <= points){
            points -= amount; 
        }
        else{
            cout << "Insufficient Points! ";
        }
    }

};

class Classroom
{
public:
    string name;
    vector<Student> students;

    void add_student(const Student &student)
    {
        students.push_back(student);
    }

    void assign_points(const string &student_name, int points)
    {
        for (Student &student : students)
        {
            if (student.name == student_name)
            {
                student.points += points;
                break;
            }
        }
    }

    void print_students() const
    {
        for (const Student &student : students)
        {
            cout << "Name: " << student.name << ", Roll Number: " << student.roll_number << ", Points: " << student.points << std::endl;
        }
    }
};

class Teacher
{
public:
    string name;
    vector<Classroom> classrooms;

    void add_classroom(const Classroom &classroom)
    {
        classrooms.push_back(classroom);
    }

    void assign_points(const std::string &classroom_name, const std::string &student_name, int points)
    {
        for (Classroom &classroom : classrooms)
        {
            if (classroom.name == classroom_name)
            {
                classroom.assign_points(student_name, points);
                break;
            }
        }
    }

    void print_classrooms() const
    {
        for (const Classroom &classroom : classrooms)
        {
            std::cout << "Classroom: " << classroom.name << std::endl;
            classroom.print_students();
            std::cout << std::endl;
        }
    }
};

int main(){

    Student s1; 
    cout << "Enter your name: "; 
    cin >> s1.name; 

    cout << "Enter your id number: "; 
    cin >> s1.id_number; 

    cout << "Enter your year: "; 
    cin >> s1.classroom;

    s1.view_points();


    return 0;
}