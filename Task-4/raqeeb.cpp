#include <iostream>

using namespace std;

class Student
{
private:
    int Id;
    float Gpa;
    string Name;
    Student *next;

public:
    Student(int id, string name, float gpa)
    {
        Id = id;
        Name = name;
        Gpa = gpa;
        next = NULL;
    }
    int student_Id()
    {
        return Id;
    };
    string student_Name()
    {
        return Name;
    };
    float student_Gpa()
    {
        return Gpa;
    };
    Student *Next()
    {
        return next;
    };

    void update_Next(Student *new_next) { next = new_next; };
    void Display_Student()
    {
        cout << "ID: " << Id << ", Name: " << Name << ", GPA: " << Gpa << endl;
    }
};

class LinkedList
{
private:
    Student *head;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        size = 0;
    };

    void display_all_students()
    {
        Student *curr = head;
        while (curr != NULL)
        {
            curr->Display_Student();
            curr = curr->Next();
        }
    }

    void add_student(int id, float gpa, string name)
    {
        Student *new_student = new Student(id, name, gpa);
        if (size == 0)
        {
            head = new_student;
        }
        else
        {
            Student *curr = head;
            while (curr->Next() != NULL)
            {
                curr = curr->Next();
            }
            curr->update_Next(new_student);
        }
        size++;
    };

    Student *search_student(int id)
    {
        Student *curr = head;
        while (curr != NULL)
        {
            if (id == curr->student_Id())
            {
                return curr;
            }
            curr = curr->Next();
        }
        return NULL;
    }

    float average()
    {
        float sum = 0;
        if (size > 0)
        {
            Student *curr = head;
            while (curr != NULL)
            {
                sum += curr->student_Gpa();
                curr = curr->Next();
            }
            return (sum / size);
        }
        else
        {
            return 0;
        }
    }

    void remove_student(int student_id)
    {

        bool isStudent = false;

        Student *curr = head;
        Student *prev = head;

        while (curr != NULL)
        {
            if (student_id == curr->student_Id())
            {
                if (prev == curr)
                {
                    head = curr->Next();
                }
                else
                {
                    prev->update_Next(curr->Next());
                }
                delete curr;
                size -= 1;
                cout << "Student removed successfully." << endl;
                return;
            }
            prev = curr;
            curr = curr->Next();
        }
        cout << "No Student Found." << endl;
    }
};

int main()
{
    bool exit = true;

    LinkedList student = LinkedList();

    cout << "Welcome to the Student Registration System!" << endl;
    cout << "\n1. Add a student" << endl;
    cout << "2. Remove a student" << endl;
    cout << "3. Search for a student" << endl;
    cout << "4. Display all students" << endl;
    cout << "5. Calculate average GPA" << endl;
    cout << "6. Exit" << endl;

    ;
    for (bool exit = false; exit == false;)
    {
        int input;
        cout << endl
             << "Enter your choice: ";
        cin >> input;

        if (input == 1)
        {
            int student_id;
            float student_gpa;
            string student_name;
            cout << "Enter student ID: ";
            cin >> student_id;
            cout << "Enter student name: ";
            cin >> student_name;
            cout << "Enter student GPA: ";
            cin >> student_gpa;
            student.add_student(student_id, student_gpa, student_name);
            cout << "Student added successfully." << endl;
        }
        else if (input == 2)
        {
            int student_id;
            cout << "Enter student ID to remove: ";
            cin >> student_id;
            student.remove_student(student_id);
        }
        else if (input == 3)
        {
            int student_id;
            cout << "Enter student ID to search: ";
            cin >> student_id;
            Student *isStudentValid = student.search_student(student_id);
            if (isStudentValid != NULL)
            {
                cout << "Student found: " << endl;
                isStudentValid->Display_Student();
            }
            else
                cout << "No Student found!" << endl;
        }
        else if (input == 4)
        {
            cout << "Student Records:" << endl;
            student.display_all_students();
        }
        else if (input == 5)
            cout << "Average GPA: " << student.average() << endl;
        else if (input == 6)
        {
            cout << "Goodbye!" << endl;
            exit = true;
        }
    }

    return 0;
}