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
    int classroom;
    

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
    int classroom;
    vector<Student> students;

    

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
     Mainmenu:
    int choice;
   
    cout << "Enter 1 for Student Database and 2 for Teacher Database: ";
    cin >> choice;
    if (choice == 1)
    {
        string student_name;
        int id_number, classroom;
        cout << "Enter your name: ";
        getline(cin,student_name,'\n');
        
        
        cout << "Enter your ID number: ";
        cin >> id_number;
        
        cout << "Enter your classroom number: ";
        cin >> classroom;
        studentMenu:
        Student s1={student_name,id_number,0,classroom};
        int s_choice;
        cout << "Enter 1 to view points, 2 to spend points: ";
        cin >> s_choice;
        if (s_choice == 1)
        {
            s1.view_points();
            int stchoice=0;
            cout << "Press 1 to go back to Student's Menu/n 2 to Main Menu /n 3 to exit the program"; 
            cin >> stchoice; 
            if(stchoice == 1){
                goto studentMenu;             
            }
            else if(stchoice==2){
                goto Mainmenu;            
            }
            else if(stchoice==3){
                cout << "Terminating Program........";            
            }
            else{
                cout << "Invalid choice!";
            }
            
        }
        else if (s_choice == 2)
        {
            int amount;
            cout << "Enter amount: ";
            cin >> amount;
            s1.spend_points(amount);
            
            int stchoice=0;
            cout << "Press 1 to go back to Student's Menu/n 2 to Main Menu /n 3 to exit the program"; 
            cin >> stchoice; 
            if(stchoice == 1){
                goto studentMenu;             
            }
            else if(stchoice==2){
                goto Mainmenu;            
            }
            else if(stchoice==3){
                cout << "Terminating Program........";            
            }
            else{
                cout << "Invalid choice!";
            }
        }
        else
        {
            cout << "Invalid choice." << endl;
            
            int stchoice=0;
            cout << "Press 1 to go back to Student's Menu/n 2 to Main Menu /n 3 to exit the program"; 
            cin >> stchoice; 
            if(stchoice == 1){
                goto studentMenu;             
            }
            else if(stchoice==2){
                goto Mainmenu;            
            }
            else if(stchoice==3){
                cout << "Terminating Program........";            
            }
            else{
                cout << "Invalid choice!";
            }
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
        
        Teacher t={name,classroom};
        
        teacherMenu:
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
            cout << "Enter Classroom for student: ";
            cin >> classroom2;
            Student s2={name2,id_number2,classroom2};
            t.add_student(s2);
            
            int stchoice=0; 
            cout << "Press 1 to go back to Teacher's Menu ^^  2 to Main Menu ^^  3 to exit the program"; 
            cin >> stchoice; 
            if(stchoice == 1){
                goto teacherMenu;             
            }
            else if(stchoice==2){
                goto Mainmenu;            
            }
            else if(stchoice==3){
                cout << "Terminating Program........";            
            }
            else{
                cout << "Invalid choice!";
            }
        }
        else if (t_choice == 2)
        {
            t.view_classroom_info();
            int stchoice=0;
            cout << "Press 1 to go back to Teacher's Menu ^^  2 to Main Menu ^^ 3 to exit the program: "; 
            cin >> stchoice; 
            if(stchoice == 1){
                goto teacherMenu;             
            }
            else if(stchoice==2){
                goto Mainmenu;            
            }
            else if(stchoice==3){
                cout << "Terminating Program........";            
            }
            else{
                cout << "Invalid choice!";
            }
        }
        else if (t_choice == 3)
        {
            int assign_idnum;
            int amount;
            cout << "Enter id number for student to assign points to him/her: ";
            cin >> assign_idnum;
            cout << "How many points do you want to spend?"; 
            cin >> amount; 
            
            
            t.assign_points(assign_idnum,amount);
            
            int stchoice=0;
            cout << "Press 1 to go back to Teacher's Menu ^^  2 to Main Menu ^^  3 to exit the program: "; 
            cin >> stchoice; 
            if(stchoice == 1){
                goto teacherMenu;             
            }
            else if(stchoice==2){
                goto Mainmenu;            
            }
            else if(stchoice==3){
                cout << "Terminating Program........";            
            }
            else{
                cout << "Invalid choice!";
            }
        }
        else
        {
            cout << "Invalid choice." << endl;
            
            int stchoice=0;
            cout << "Press 1 to go back to Teacher's Menu ^^  2 to Main Menu ^^ 3 to exit the program: "; 
            cin >> stchoice; 
            if(stchoice == 1){
                goto teacherMenu;             
            }
            else if(stchoice==2){
                goto Mainmenu;            
            }
            else if(stchoice==3){
                cout << "Terminating Program........";            
            }
            else{
                cout << "Invalid choice!";
            }
        }
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
    return 0;
}
