#include <iostream>
#include <string>

using namespace std;

bool isBracket(char v)
{
    switch (v)
    {
    case '[':
    case ']':
    case '(':
    case ')':
    case '{':
    case '}':
        return true;
    default:
        return false;
    }
    return false;
}
bool isBalanced(char start, char end)
{
    if ((start == '[' && end == ']') || (start == '(' && end == ')') ||
        (start == '{' && end == '}'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string input;
    cin >> input;
    stack<char> list;
    for (int i = 0; i < input.size(); i++)
    {
        if (list.empty())
        {
            list.push(input[i]);
            continue;
        }
        if (input[i] == ']' || input[i] == ')' || input[i] == '}')
        {
            if (isBalanced(list.top(), input[i]))
            {
                list.pop();
                continue;
            }
        }
        if (isBracket(input[i]))
        {
            list.push(input[i]);
            continue;
        }
    }

    if (list.empty() == true)
        cout << "true";
    else
        cout << "false" << endl;

    return 0;
}
