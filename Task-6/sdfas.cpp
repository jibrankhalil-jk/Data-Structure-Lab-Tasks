#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node(string value)
    {
        data = value;
        next = NULL;
    }
};

class Stack
{
public:
    Node *arr;
    int top;

    Stack()
    {
        top = -1;
        arr = NULL;
    }

    string pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return "";
        }
        else
        {
            top--;
            Node *temp = arr;
            arr = arr->next;
            return temp->data;
        }
    }

    void push(string value)
    {
        top++;
        Node *newn = new Node(value);
        newn->next = arr;
        arr = newn;
    }

    string peek()
    {
        if (top == -1)
        {
            return "";
        }
        return arr->data;
    }
};

void print_menu(string current[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "\t" << i << ". " << current[i] << endl;
    }
}

int main()
{
    Stack navigations_back, navigations_forward;

    string home[] = {"Home", "Admission", "Campuses", "Student", "Services"};
    string Admission[] = {"Admission Shedule", "Undergraduate", "Graduate", "International", "Scholarships"};
    string Campuses[] = {"Islamabad", "Karachi", "Faisalabad", "Lahore", "Peshawar"};
    string Student[] = {"Student Portal", "Student Services", "Student Affairs", "Student Clubs", "Student Societies"};
    string Services[] = {"Library", "Transport", "Hostel", "Cafeteria", "Sports"};

    navigations_back.push(home[0]);

    string *current_menu = home;

    string pages[5];
    int index = 0;

    int input;
    do
    {
        cout << "7. Back \t\t URl : https://www.nu.edu.pk/";
        for (int i = 0; i < index; i++)
        {
            cout << pages[i] << "/";
        }
        cout << "\t\t 8. Go forward \t\t 9. Exit" << endl;

        print_menu(current_menu);

        cin >> input;

        if (input >= 0 && input <= 4)
        {
            index = input;
        }

        switch (index)
        {
        case 0:
            current_menu = home;
            break;
        case 1:
            current_menu = Admission;
            break;
        case 2:
            current_menu = Campuses;
            break;
        case 3:
            current_menu = Student;
            break;
        case 4:
            current_menu = Services;
            break;

        default:
            break;
        }

    } while (input != 9);

    return 0;
}