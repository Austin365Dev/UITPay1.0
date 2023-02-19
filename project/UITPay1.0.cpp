#include <iostream>
#include <string>
#include <vector>

struct Student
{
    std::string name;
    int roll_number;
    int points;

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
    std::string name;
    std::vector<Student> students;

    void add_student(const Student &s)
    {
        students.push_back(s);
    }

    void assign_points(const std::string &name, int points)
    {
        for (Student &s : students)
        {
            if (s.name == name)
            {
                s.points += points;
                break;
            }
        }
    }

    void print_students() const
    {
        std::cout << "Classroom " << name << ":\n";
        for (const Student &s : students)
        {
            std::cout << "  Name: " << s.name << ", Roll Number: " << s.roll_number
                      << ", Points: " << s.points << "\n";
        }
    }
};

class TeacherDatabase
{
public:
    std::vector<Classroom> classrooms;

    void add_classroom(const Classroom &c)
    {
        classrooms.push_back(c);
    }

    void assign_points(const std::string &classroom_name,
                       const std::string &student_name, int points)
    {
        for (Classroom &c : classrooms)
        {
            if (c.name == classroom_name)
            {
                c.assign_points(student_name, points);
                break;
            }
        }
    }

    void print_classrooms() const
    {
        for (const Classroom &c : classrooms)
        {
            c.print_students();
        }
    }
};

class StudentDatabase
{
public:
    std::vector<Student> students;

    void add_student(const std::string &name, int roll_number)
    {
        Student s = {name, roll_number, 0};
        students.push_back(s);
    }

    void print_students() const
    {
        std::cout << "Student Database:\n";
        for (const Student &s : students)
        {
            std::cout << "  Name: " << s.name << ", Roll Number: " << s.roll_number
                      << ", Points: " << s.points << "\n";
        }
    }
};

int main()
{
    Teacher t;
    t.name = "Ms. Smith";

    Classroom c1;
    c1.name = "CSC101";

    Student s1;
    s1.name = "Alice";
    s1.roll_number = 1;
    s1.points = 0;

    Student s2;
    s2.name = "Bob";
    s2.roll_number = 2;
    s2.points = 0;

    c1.add_student(s1);
    c1.add_student(s2);

    t.add_classroom(c1);

    Classroom c2;
    c2.name = "CSC102";

    Student s3;
    s3.name = "Charlie";
    s3.roll_number = 3;
    s3.points = 0;

    Student s4;
    s4.name = "David";
    s4.roll_number = 4;
    s4.points = 0;

    c2.add_student(s3);
    c2.add_student(s4);

    t.add_classroom(c2);

    t.assign_points("CSC101", "Alice", 10);
    t.assign_points("CSC102", "David", 20);

    std::cout << "Teacher: " << t.name << std::endl;
    t.print_classrooms();

    return 0;
}
