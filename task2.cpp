#include <iostream>
#include <string>

using namespace std;

char *subs(char *array, int startIndex, int stopIndex)
{
    if (stopIndex >= startIndex)
    {
        int size = stopIndex - startIndex + 1;
        char *text = new char[size];
        int j = 0;
        for (int i = startIndex; i <= stopIndex; i++, j++)
        {
            *(text + j) = *(array + i);
        }

        return text;
    }
    else
    {
        return nullptr;
    }
}

int main()
{

    // char text[] = "My name is ali";
    string text;
    cout << "Entered string is :";
    cin >> text;
    int arraySize = sizeof(text) / sizeof(text[0]);
    char txt[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        txt[i] = text[i];
    }

    cout << "> " << subs(txt, 3, 6);

    return 0;
}