#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    int id_number;
    int points;

    Student(string name, int id_number, int classroom) : name(name), id_number(id_number), classroom(classroom) points(0) {}

    void view_points() const
    {
        cout << "Name: " << name << endl;
        cout << "ID Number: " << id_number << endl;
        cout << "Points: " << points << endl;
    }


    void spend_points(int amount)
    {
        if (amount <= points)
        {
            points -= amount;
            cout << "Successfully spent " << amount << " points." << endl;
            cout << "Remaining points: " << points << endl;
        }
        else
        {
            cout << "Not enough points to spend." << endl;
        }
    }
};

class Teacher
{
public:
    string name;
    string classroom;
    vector<Student> students;

    Teacher(string name, string classroom) : name(name), classroom(classroom) {}

    void add_student(const Student &student)
    {
        students.push_back(student);
    }

    void assign_points(int id_number, int points)
    {
        for (auto &student : students)
        {
            if (student.id_number == id_number)
            {
                student.points += points;
                cout << "Successfully assigned " << points << " points to " << student.name << "." << endl;
                return;
            }
        }
        cout << "No student found with ID number " << id_number << "." << endl;
    }

    void view_classroom_info() const
    {
        cout << "Classroom: " << classroom << endl;
        cout << "Teacher: " << name << endl;
        cout << "Students: " << endl;
        for (const auto &student : students)
        {
            cout << "  Name: " << student.name << endl;
            cout << "  ID Number: " << student.id_number << endl;
            cout << "  Points: " << student.points << endl;
        }
    }
};

int main()
{
    int choice;
    cout << "Enter 1 for Student Database and 2 for Teacher Database: ";
    cin >> choice;
    if (choice == 1)
    {
        string student_name;
        int id_number, classroom;
        cout << "Enter your name: ";
        cin >> student_name;
        cout << "Enter your ID number: ";
        cin >> id_number;
        cout << "Enter your classroom number: ";
        cin >> classroom;

        Student s(student_name, id_number, classroom);
        int s_choice;
        cout << "Enter 1 to view points, 2 to spend points: ";
        cin >> s_choice;
        if (s_choice == 1)
        {
            s.view_points();
        }
        else if (s_choice == 2)
        {
            int amount;
            cout << "Enter amount: ";
            cin >> amount;
            s.spend_points(amount);
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
    else if (choice == 2)
    {
        string name;
        int classroom;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your classroom number: ";
        cin >> classroom;

        Teacher t(name, classroom);
        int t_choice;
        cout << "Enter 1 to add student information, 2 to view students in the classroom, 3 to assign points: ";
        cin >> t_choice;
        if (t_choice == 1)
        {
            string name2;
            int id_number2;
            int classroom2;
            cout << "Enter Student's name: ";
            cin >> name2;
            cout << "Enter Student's id number: ";
            cin >> id_number2;
            cout << "Enter Classroom for student: ":
            cin >> classroom2;
            Student s2(name2,id_number2,classroom2);
            t.add_student(s2);
        }
        else if (t_choice == 2)
        {
            t.view_classroom_info();
        }
        else if (t_choice == 3)
        {
            int assign_idnum;
            cout << "Enter id number for student to assign points to him/her: ";
            cin >> assign_idnum;
            t.assign_points(assign_idnum);
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
    return 0;
}
