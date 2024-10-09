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
            return "-";
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
            return "-";
        }
        return arr->data;
    }

    void clear()
    {
        top = -1;
        arr = NULL;
    }
};

int main()
{
    Stack navigations_back, navigations_forward;
    string url = "";

    int input = 0;
    bool first = true;
    do
    {
        cout << "7. Back \t\t" << url << "\t\t 8. Go forward \t\t 9. Exit" << endl;
        cout << "1. Enter URL" << endl;
        cin >> input;
        if (input == 1)
        {
            if (first)
            {
                first = true;
            }
            if (url != "")
            {
                navigations_back.push(url);
            }
            cout << "Enter URL: ";
            cin >> url;
            navigations_forward.clear();
            continue;
        }

        switch (input)
        {
        case 7:
            if (navigations_back.peek() == "-")
            {
                cout << "No more pages to go back" << endl;
                continue;
            }
            else
            {
                {
                    navigations_forward.push(url);
                    url = navigations_back.peek();
                    cout << "Navigated back to " << url << endl;
                    navigations_back.pop();
                }
            }
            break;
        case 8:
            if (navigations_forward.peek() == "-")
            {
                cout << "No more pages to go forward" << endl;
                continue;
            }
            else
            {
                navigations_back.push(url);
                url = navigations_forward.peek();
                cout << "Navigated forward to " << url << endl;
                navigations_forward.pop();
            }
            break;

        default:
            break;
        }

    } while (input != 9);
    cout << "Exiting" << endl;

    return 0;
}