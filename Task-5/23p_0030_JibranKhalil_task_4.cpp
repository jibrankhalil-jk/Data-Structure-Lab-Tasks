#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int id;
    string name;
    int price;
    int quantity;
    Node *next;
    Node *prev;
    Node(int Id, string Name, int Price, int Quantity)
    {
        id = Id;
        name = Name;
        price = Price;
        quantity = Quantity;
        next = NULL;
        prev = NULL;
    }

    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "------------------------------------------------------" << endl;
    }
    void display_in_row()
    {
        cout << "ID: " << id << ", ";
        cout << "Name: " << name << ", ";
        cout << "Price: " << price << ", ";
        cout << "Quantity: " << quantity << ", " << endl;
        cout << "------------------------------------------------------" << endl;
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
        if (head != NULL)
        {
            cout << "------------------------------------------------------" << endl;
        }
        else
        {
            cout << "List is Empty" << endl
                 << endl;
        }
        while (curr != NULL)
        {
            curr->display_in_row();
            curr = curr->next;
        }
    }

    bool isUsedBefor(int Id)
    {
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->id == Id)
            {
                return true;
            }
            curr = curr->next;
        }

        return false;
    }

    void add(int Id, string Name, int Price, int Quantity)
    {
        Node *newNode = new Node(Id, Name, Price, Quantity);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        if (head->id >= Id)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node *curr = head;
        while (curr->next != nullptr && curr->next->id < Id)
        {
            curr = curr->next;
        }

        newNode->next = curr->next;
        if (curr->next != nullptr)
        {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

    void remove(int Id)
    {
        Node *curr = head;
        if (head == NULL)
        {
            cout << "No Product to remove" << endl;
            return;
        }
        else
        {
            while (curr != NULL)
            {
                if (curr->id == Id)
                {
                    break;
                }
                curr = curr->next;
            }

            if (curr == NULL)
            {
                cout << "No Product with Id:" << Id << " to remove" << endl;
                return;
            }
            if (curr->prev == NULL)
            {
                curr->next->prev = NULL;
                head = curr->next;
            }
            else if (curr->next == NULL)
            {
                curr->prev->next = NULL;
            }
            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            delete curr;
        }
        length--;
    }

    void update(int Id, int Price)
    {
        Node *curr = head;
        if (head == NULL)
        {
            cout << "No Products to Update" << endl;
            return;
        }
        else
        {
            while (curr != NULL)
            {
                if (curr->id == Id)
                {
                    break;
                }
                curr = curr->next;
            }

            if (curr == NULL)
            {
                cout << "No Product with Id:" << Id << " to update" << endl;
                return;
            }
            else
            {
                curr->price = Price;
            }
        }
    }
    void find(int Id)
    {
        Node *curr = head;
        if (head == NULL)
        {
            cout << "No Products" << endl;
            return;
        }
        else
        {
            while (curr != NULL)
            {
                if (curr->id == Id)
                {
                    break;
                }
                curr = curr->next;
            }

            if (curr == NULL)
            {
                cout << "No Product with Id:" << Id << endl;
                return;
            }
            else
            {
                return curr->display();
            }
        }
    }
};

int main()
{
    DoublyLinkedList list;

    cout << "Welcome to Inventory management system" << endl;
    bool exit = false;
    while (!exit)
    {
        cout << "1.Add Items" << endl;
        cout << "2.Remove Items" << endl;
        cout << "3.Update Items" << endl;
        cout << "4.Display Items" << endl;
        cout << "5.Find Item" << endl;
        cout << "6.Exit" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int id;
            string name;
            int price;
            int quantity;

            cout << "ID: ";
            cin >> id;
            cout << "Name: ";
            cin >> name;
            cout << "Price: ";
            cin >> price;
            cout << "Quantity: ";
            cin >> quantity;

            list.add(id, name, price, quantity);
            cout << endl;
        }
        break;
        case 2:
        {
            int Id;
            cout << "Enter the ID:";
            cin >> Id;
            list.remove(Id);
            cout << endl;
        }
        break;
        case 3:
        {
            int id;
            int price;

            cout << "ID: ";
            cin >> id;
            cout << "Price: ";
            cin >> price;

            list.update(id, price);
            cout << endl;
        }
        break;
        case 4:
        {
            list.print();
        }
        break;
        case 5:
        {
            int Id;
            cout << "Enter the ID:";
            cin >> Id;
            list.find(Id);
            cout << endl;
        }
        break;
        case 6:
            cout << "Exiting !!" << endl;
            exit = true;
            break;
        default:
            break;
        }
    }
    return 0;
}