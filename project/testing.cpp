// first attempt

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person(const string &name, const string &classroom)
        : name_(name), classroom_(classroom) {}

    const string &Name() const { return name_; }
    const string &Classroom() const { return classroom_; }

private:
    string name_;
    string classroom_;
};

class Student : public Person
{
public:
    Student(const string &name, const string &classroom, int id)
        : Person(name, classroom), id_(id), points_(0) {}

    int ID() const { return id_; }
    int Points() const { return points_; }

    void AddPoints(int points) { points_ += points; }
    bool SpendPoints(int points)
    {
        if (points_ >= points)
        {
            points_ -= points;
            return true;
        }
        return false;
    }

private:
    int id_;
    int points_;
};

class Teacher : public Person
{
public:
    Teacher(const string &name, const string &classroom)
        : Person(name, classroom), points_(100) {}

    int Points() const { return points_; }
    void AddPointsToStudent(Student *student, int points)
    {
        student->AddPoints(points);
        points_ -= points;
    }

    void ViewStudentInfo(const vector<Student> &students) const
    {
        cout << "Students in " << Classroom() << ":" << endl;
        for (const auto &student : students)
        {
            if (student.Classroom() == Classroom())
            {
                cout << student.Name() << " (ID: " << student.ID()
                     << ", Points: " << student.Points() << ")" << endl;
            }
        }
    }

private:
    int points_;
};

int main()
{
    vector<Student> students;
    vector<Teacher> teachers;

    while (true)
    {
        cout << "Enter your name (or 'q' to quit): ";
        string name;
        getline(cin, name);

        if (name == "q")
        {
            break;
        }

        cout << "Enter your classroom: ";
        string classroom;
        getline(cin, classroom);

        bool is_teacher = false;
        for (const auto &teacher : teachers)
        {
            if (teacher.Name() == name && teacher.Classroom() == classroom)
            {
                is_teacher = true;
                teacher.ViewStudentInfo(students);

                while (teacher.Points() > 0)
                {
                    cout << "Enter student ID to give points (or 'q' to stop): ";
                    string id_str;
                    getline(cin, id_str);

                    if (id_str == "q")
                    {
                        break;
                    }

                    int id = stoi(id_str);
                    for (auto &student : students)
                    {
                        if (student.ID() == id && student.Classroom() == classroom)
                        {
                            cout << "Enter points to give: ";
                            string points_str;
                            getline(cin, points_str);
                            int points = stoi(points_str);
                            teacher.AddPointsToStudent(&student, points);
                            break;
                        }
                    }
                }
                break;
            }
        }

        if (!is_teacher)
        {
            cout << "Enter your ID number: ";
            string id_str;
            getline(cin, id_str);
            int id = stoi(id_str);

            bool is_student_in_classroom = false;
            for (const auto &student : students)
            {
                if (student.ID() == id && student.Classroom() == classroom)
                {
                    is_student_in_classroom = true;

                    while (true)
                    {
                        cout << "You have " << student.Points() << " points. Enter add' to add points, 'spend' to spend points, or 'q' to quit: ";
                        string command;
                        getline(cin, command);

                        if (command == "q")
                        {
                            break;
                        }
                        else if (command == "add")
                        {
                            cout << "Enter points to add: ";
                            string points_str;
                            getline(cin, points_str);
                            int points = stoi(points_str);
                            student.AddPoints(points);
                        }
                        else if (command == "spend")
                        {
                            cout << "Enter points to spend: ";
                            string points_str;
                            getline(cin, points_str);
                            int points = stoi(points_str);
                            if (student.SpendPoints(points))
                            {
                                cout << "Points spent successfully." << endl;
                            }
                            else
                            {
                                cout << "Not enough points." << endl;
                            }
                        }
                        else
                        {
                            cout << "Invalid command." << endl;
                        }
                    }
                    break;
                }
            }

            if (!is_student_in_classroom)
            {
                cout << "You are not registered as a student in this classroom." << endl;
            }
        }
    }

    return 0;
}
