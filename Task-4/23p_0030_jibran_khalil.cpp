#include <iostream>
#include <string> 
#include <iomanip> //  to user setprecision function, to shoq .xx float number

using namespace std;

class Student
{
private:

    int id;
    float gpa;
    string name;
    Student *next;

public:
    Student(int id, string name, float gpa) : id(id), name(name), gpa(gpa)
    {
        next = NULL;
    }
    Student() : id(0), name(" "), gpa(0.0)
    {
        next = NULL;
    }

    // getter functions
    int get_Id() { return id; };
    string get_Name() { return name; };
    float get_Gpa() { return gpa; };
    Student *get_next() { return next; };

    // setter functions
    void set_Id(int student_id) { id = student_id; };
    void set_Name(string student_name) { name = student_name; };
    void set_Gpa(float student_gpa) { gpa = student_gpa; };
    void set_next(Student *new_next) { next = new_next; };

    // diplay student data
    void display()
    {
        cout << "ID: " << id;
        cout << ", Name: " << name;
        cout << ", GPA: " << gpa << endl;
    }
};

class LinkedList
{
private:

    Student *head;
    Student *current;
    int length;

    void next() { current = current->get_next(); }
    void start() { current = head; }

public:

    LinkedList()
    {
        head = NULL;
        length = 0;
    };

    void display()
    {
        start();
        while (current != NULL)
        {
            current->display();
            next();
        }
    }

    void add(Student student)
    {
        Student *new_student = new Student(student.get_Id(), student.get_Name(), student.get_Gpa());
        if (length == 0)
        {
            head = new_student;
        }
        else
        {
            start();
            while (current->get_next() != NULL)
            {
                next();
            }
            current->set_next(new_student);
        }
        length++;
    };

    bool remove(int id)
    {

        bool validStudent = false;
        start();
        Student *slow = head;

        while (current != NULL)
        {
            if (id == current->get_Id())
            {
                validStudent = true;
                break;
            }
            slow = current;
            next();
        }
        if (validStudent)
        {
            if (slow == current)
            {
                head = current->get_next();
            }
            else
            {
                slow->set_next(current->get_next());
            }
            delete current;
            length--;
            return true;
        }
        else
        {
            return false;
        }
    }

    Student *find(int id)
    {
        start();
        while (current != NULL)
        {
            if (id == current->get_Id())
            {
                return current;
            }

            next();
        }
        return NULL;
    }

    float find_average()
    {
        float sum = 0;
        if (length > 0)
        {
            start();
            while (current != NULL)
            {
                sum += current->get_Gpa();
                next();
            }
            return (sum / length);
        }
        else
        {
            return 0;
        }
    }

};

int main()
{
    bool exit = true;

    LinkedList list = LinkedList();

    cout << "Welcome to the Student Registration System!" << endl;
    cout << "\n1. Add a student\n2. Remove a student\n3. Search for a student\n4. Display all students\n5. Calculate average GPA\n6. Exit" << endl;

    while (exit)
    {
        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            float gpa;
            string name;

            cout << "Enter student ID:";
            cin >> id;

            cout << "Enter student name: ";
            cin >> name;

            cout << "Enter student GPA: ";
            cin >> gpa;

            Student temp = Student(id, name, gpa);
            list.add(temp);
            cout << "Student added successfully." << endl;
        }
        break;
        case 2:
        {
            int id;
            cout << "Enter student ID to remove: ";
            cin >> id;
            if (list.remove(id))
            {
                cout << "Student removed successfully." << endl;
            }
            else
            {
                cout << "No Student Found." << endl;
            }
        }
        break;
        case 3:
        {
            int id;
            cout << "Enter student ID to search: ";
            cin >> id;
            Student *student = list.find(id);
            if (student)
            {
                cout << "Student found: " << endl;
                student->display();
            }
            else
            {
                cout << "No Student found!" << endl;
            }
        }
        break;
        case 4:
        {
            cout << "Student Records:" << endl;
            list.display();
        }
        break;
        case 5:
        {
            cout << "Average GPA: " << setprecision(3) << list.find_average() << endl;
        }
        break;
        case 6:
        {
            cout << "Goodbye!" << endl;
            exit = false;
        }
        break;
        default:
        {
            cout << "Invalid Choice Retry" << endl;
            continue;
        }
        break;
        }
    }

    cout << endl;
    return 0;
}