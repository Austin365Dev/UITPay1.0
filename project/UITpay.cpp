#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Student
{
public:
    int roll_number;
    string name;
    int points;
    Classroom section;

    int view_points() const
    {
        return points;
    }

    void spend_points(int amount)
    {
        if (points >= amount)
        {
            points -= amount;
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


int main()
{
    int checkStudentTeacher;
    cout << "Are you student or teacher?  "; 
    cout << "Type 1 for student and type 2 for teacher";
    cin >> checkStudentTeacher;
    
    if(checkStudentTeacher==1){
        Student s1;
        cout << "Enter your name: ";
        cin >> s1.name;
        cout << "Enter your roll number: ";
        cin >> s1.roll_number;
        if(s1.roll_number >= 1800 && s1.roll_number <=1840){
            Classroom c1;
            
        }
    }
    
    

    return 0;
}

