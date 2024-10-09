#include <iostream>
#include <string>

using namespace std;

class Stack
{
    int *head;
    int top;
    int size;

public:
    Stack(int ssize)
    {
        head = new int[ssize];
        top = -1;
        size = ssize;
    }
    int pop()
    {
        if (top <= -1)
        {
            // cout << "Stack is empty" << endl;
            cout << "Stack underflow" << endl;
            return -1;
        }
        else
        {
            int value = *(head + top);
            top--;
            return value;
        }
    }
    int peek()
    {
        if (top == -1)
        {
            // cout << "Stack is empty" << endl;
            cout << "Stack underflow" << endl;
            return -1;
        }
        else
            return *(head + top);
    }

    void push(int value)
    {
        if (top == size)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        else
        {
            top++;
            *(head + top) = value;
        }
    }
};

int main()
{

    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout
        << endl;

    return 0;
}