#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    void set(Node *prev, Node *next)
    {
        this->prev = prev;
        this->next = next;
    }
};

class DouplyLinkedList
{
private:
    Node *head;
    int length;

public:
    DouplyLinkedList()
    {
        head = nullptr;
        length = 0;
    }
    void display()
    {
        Node *curr = head;
        cout << "[";
        while (curr != NULL)
        {
            if (curr != head)
                cout << ",";
            cout << curr->data;
            curr = curr->next;
        }
        cout << "]" << endl;
    };

    void add(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }

            newNode->set(curr, NULL);
            curr->next = newNode;
        }
        length++;
    }

    void insertInAscendingOrder(int data)
    {
        Node *newNode = new Node(data);

        // If the list is empty
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        // If the new node should be inserted at the beginning
        if (head->data >= data)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        // Find the correct position to insert the new node
        Node *curr = head;
        while (curr->next != nullptr && curr->next->data < data)
        {
            curr = curr->next;
        }

        // Insert the new node
        newNode->next = curr->next;
        if (curr->next != nullptr)
        {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }
    void remove(int position)
    {
        if (position <= 0 || position > length)
        {
            cout << "Invalid position" << endl;
            return;
        }
        Node *curr = head;
        if (position == 1)
        {
            if (curr->next != NULL)
            {
                curr->next->prev = NULL;
                head = curr->next;
            }
            else
            {
                head = NULL;
            }
        }
        else
        {
            position--;
            for (int i = 0; i <= position; i++)
            {
                curr = curr->next;
            }

            cout << curr->data;
        }
        length--;
        delete curr;
    }
};

int main()
{
    DouplyLinkedList list;
    list.insertInAscendingOrder(1);
    list.insertInAscendingOrder(3);
    list.insertInAscendingOrder();
    list.display();
    // list.insert(0,0);
    list.insertInAscendingOrder(13);
    list.display();
    list.remove(2);
    list.display();

    cout << endl;

    return 0;
}