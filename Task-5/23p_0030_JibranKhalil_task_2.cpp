#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
    void set(Node *p, Node *n)
    {
        prev = p;
        next = n;
    }
};

class DoublyLinkedList
{
    Node *head;
    int length;

public:
    DoublyLinkedList()
    {
        length = 0;
        head = NULL;
    };

    void print()
    {
        Node *curr = head;
        cout << "[";
        while (curr != NULL)
        {
            if (curr != head)
            {
                cout << ",";
            }
            cout << curr->data;
            curr = curr->next;
        }
        cout << "]" << endl;
    }

    int getLenght()
    {
        return length;
    }

    void add(int data)
    {
        Node *curr = head;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            newNode->set(curr, NULL);
            curr->next = newNode;
        }
        length++;
    }

    void insert(int data, int position)
    {
        if (position <= 0 || position > length + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }
        Node *newNode = new Node(data);
        if (position == 1)
        {
            newNode->set(nullptr, head);
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            position--;
            Node *curr = head;
            for (int i = 0; i < position - 1; i++)
            {
                curr = curr->next;
            }
            newNode->set(curr, curr->next);
            if (curr->next != NULL)
            {
                curr->next->prev = newNode;
            }
            curr->next = newNode;
        }
        length++;
    }

    void remove(int position)
    {
        if (position <= 0 && position > length)
        {
            cout << "Out of index";
            return;
        }

        Node *curr = head;

        if (position == 1)
        {

            head = curr->next;
            head->prev = NULL;
        }
        else
        {
            for (int i = 0; i < position - 1; i++)
            {
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            if (curr->next != NULL)
                curr->next->prev = curr->prev;
        }
        length--;
        free(curr);
    }

    int get(int position)
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return 0;
        }
        else
        {
            Node *curr = head;
            for (int i = 0; i < position; i++)
            {
                curr = curr->next;
            }
            return curr->data;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(8);
    list.add(9);
    cout << "Input List :";
    list.print();

    DoublyLinkedList list1, list2;

    for (int i = 0; i < list.getLenght(); i++)
    {
        int data = list.get(i);
        if (data % 2 == 0)
        {
            list1.add(data);
        }
        else
        {
            list2.add(data);
        }
    }

    cout << "Output List 1 :";
    list1.print();
    cout << "Output List 2 :";
    list2.print();
    return 0;
}