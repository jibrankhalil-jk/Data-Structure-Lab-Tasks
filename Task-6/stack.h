#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
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

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            top--;
            Node *temp = arr;
            arr = arr->next;
            return temp->data;
        }
    }

    void push(int value)
    {
        top++;
        Node *newn = new Node(value);
        newn->next = arr;
        
        arr = newn;
    }

    int peek(int value)
    {
        top++;
        Node *newn = new Node(value);
        newn->next = arr;
        arr = newn;
    }
};

int main()
{

    Stack s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << endl;
    return 0;
}