#include <iostream>
#include <string>

using namespace std;

class Enqueue
{
public:
    int data;
    Enqueue *next;
    Enqueue(int value)
    {
        data = value;
        next = NULL;
    }
    void enqueue(int value)
    {
        Enqueue *newn = new Enqueue(value);
        newn->next = next;
        next = newn;
    }
    int dequeue()
    {
        if (next == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            Enqueue *temp = next;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            int value = temp->next->data;
            temp->next = NULL;
            return value;
        }
    }

    int peek()
    {
        if (next == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            Enqueue *temp = next;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            return temp->data;
        }
    }
};

int main()
{

    cout << endl;

    return 0;
}