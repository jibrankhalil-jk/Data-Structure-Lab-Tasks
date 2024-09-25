#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    int id;
    string name;
    int price;
    int quantity;
    Product *next;
    Product *prev;

    Product(
        int Id,
        string Name,
        int Price,
        int Quantity)
    {
        this->id = Id;
        this->name = Name;
        this->price = Price;
        this->quantity = Quantity;

        this->next = NULL;
        this->prev = NULL;
    }
    Product(Product *p, int Id, string Name, int Price, int Quantity, Product *n)
    {
        this->id = Id;
        this->name = Name;
        this->price = Price;
        this->quantity = Quantity;

        this->next = n;
        this->prev = p;
    };

    void set(Product *p, Product *n)
    {
        this->prev = p;
        this->next = n;
    };
    void Display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    };
    void Display_Adress()
    {
        cout << "[" << this << "]" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    };
};

class List
{
private:
    Product *head;
    int length;

public:
    List()
    {
        head = NULL;
        length = 0;
    }
    void display()
    {
        Product *curr = head;
        if (length != 0)
            cout << "-----------------------" << endl;
        while (curr->next != NULL)
        {
            curr->Display();
            cout << "-----------------------" << endl;
            curr = curr->next;
        }
    };
    void display_a()
    {
        Product *curr = head;
        if (length != 0)
            cout << "-----------------------" << endl;
        for (int i = 0; i < length; i++)

        // while (curr != NULL)
        {
            cout << " " << curr->id << " \t" << curr->prev << " {" << curr << "} " << curr->next << endl;
            cout << "-----------------------" << endl;
            curr = curr->next;
        }
    };

    bool isIndexUsedBefore(int index)
    {
        Product *curr = head;
        for (int i = 0; i < length; i++)
        {
            if (curr->id == index)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void add_at_index(Product *p, int index)
    {
        Product *curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        p->set(curr, NULL);
        curr->next = p;
    }

    void add(int Id, string Name, int Price, int Quantity)
    {
        Product *newProduct = new Product(Id, Name, Price, Quantity);
        if (head == NULL)
        {
            head = newProduct;
            length++;
            return;
        }
        if (isIndexUsedBefore(Id))
        {
            cout << "ID Used befor" << endl;
            return;
        }
        else
        {
            Product *curr = head;
            while (curr->next != NULL)
            {
                if (Id < curr->id)
                    break;
                curr = curr->next;
            }
            if (curr->next == NULL)
            {
                newProduct->set(curr, NULL);
                curr->next = newProduct;
            }
            else
            {
                newProduct->set(curr->prev, curr);
                curr->prev->next = newProduct;
                curr->prev = newProduct;
            }
        }
        length++;
    }
    
};

int main()
{

    List products = List();
    products.add(1, "Product 1", 100, 10);
    products.display_a();
    cout << "**************************" << endl;

    products.add(7, "Product 3", 100, 10);
    products.display_a();
    cout << "**************************" << endl;

    products.add(9, "Product 2", 100, 10);
    products.display_a();
    cout << "**************************" << endl;

    products.add(12, "Product 2", 100, 10);
    products.display_a();
    cout << "**************************" << endl;

    products.add(3, "Product 2", 100, 10);
    products.display_a();
    cout << "**************************" << endl;

    products.add(22, "Product 2", 100, 10);
    products.display_a();
    cout << "**************************" << endl;

    // products.add(8, "Product 2", 100, 10);
    // products.add(9, "Product 2", 100, 10);
    // // products.add(10, "Product 2", 100, 10);

    // // products.display();
    // products.display_a();

    cout
        << endl;
    return 0;
}