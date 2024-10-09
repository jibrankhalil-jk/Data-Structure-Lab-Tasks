#include <iostream>
#include <string>

using namespace std;

class Song
{
public:
    string title;
    string artist;
    int duration;
    Song *next;

    Song(string Title, string Artist, int Duration)
    {
        title = Title;
        artist = Artist;
        duration = Duration;
        next = NULL;
    }

    void display_in_row()
    {
        cout << "Title: " << title << ", ";
        cout << "Artist: " << artist << ", ";
        cout << "Duration: " << duration << ", " << endl;
        cout << "------------------------------------------------------" << endl;
    }
};

class PlayList
{
public:
    int length;
    Song *head;

public:
    PlayList()
    {
        length = 0;
        head = NULL;
    }

    void print()
    {
        if (length == 0)
        {
            cout << "No Songs to display" << endl;
            return;
        }
        Song *curr = head;

        for (int i = 0; i < length; i++)
        {
            curr->display_in_row();
            curr = curr->next;
        }
    }

    void add(string Title, string Artist, int Duration)
    {
        Song *newNode = new Song(Title, Artist, Duration);

        if (head == NULL)
        {
            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            Song *curr = head;

            while (curr->next != head)
            {
                curr = curr->next;
            }

            curr->next = newNode;

            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void remove()
    {
        if (length == 0)
        {
            cout << "No Songs to remove" << endl;
            return;
        }
        Song *curr = head;
        Song *slow = curr;
        if (curr->next == head)
        {
            head = NULL;
        }
        else
        {

            while (curr->next != head)
            {
                slow = curr;
                curr = curr->next;
            }
            slow->next = head;
        }

        length--;
        cout << "Songs \"" << curr->title << "\" removed!" << endl;

        delete curr;
    }
};

int main()
{
    PlayList list;

    cout << "Welcome to E Music app " << endl;
    bool exit = false;
    while (!exit)
    {
        cout << "1.Add Song" << endl;
        cout << "2.Remove song" << endl;
        cout << "3.Display All Songs" << endl;
        cout << "4.Exit" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string title;
            string artist;
            int duration;

            cout << "song Title: ";
            cin >> title;
            cout << "Artist Name: ";
            cin >> artist;
            cout << "Song duration in seconds: ";
            cin >> duration;

            list.add(title, artist, duration);
            cout << endl;
        }
        break;
        case 2:
        {
            list.remove();
            cout << endl;
        }
        break;
        case 3:
            list.print();
            break;
        case 4:
            cout << "Exiting !!" << endl;
            exit = true;
            break;
        default:
            break;
        }
    }
    return 0;
}