#include <iostream>
#include <string>

#include <cstdlib>

using namespace std;

int rnd()
{
    return rand() % 100 + 1;
}

float avg(int *array, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(array + i);
    }
    return (sum / size);
}
void critical(int *array, int size)
{
    float total = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) < 40)
        {
            cout << "\tproduct : " << *(array + i) << " at [" << i + 1 << "]" << endl;
            total++;
        }
    }
    cout << "\t\t\tTotal Products " << total << endl;
}
int findTopSellingProduct(int *array, int size)
{
    int max = *array;
    int max_Prod_index = 0;
    for (int i = 1; i < size; i++)
    {
        if (max < *(array + i))
        {
            max = *(array + i);
            max_Prod_index = i;
        }
    }

    int total = 1;
    for (int i = 0; i < size; i++)
    {
        if (max == *(array + i) && max_Prod_index != i)
        {
            total++;
        }

        if (max == *(array + i))
        {
            cout << "\tproduct : " << max << " at [" << i + 1 << "]" << endl;
        }
    }

    cout << "\t total:" << total << endl;
    return max;
}
int *findSecondBestSeller(int *array, int size, int top)
{
    int second = top == *array - 1;
    int ind = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) != top)
        {
            if (second < *(array + i))
            {
                second = *(array + i);
                ind = i;
            }
        }
    }
    int *ptritme = new int[2];
    *ptritme = second;
    *(ptritme + 1) = ind + 1; // position

    return ptritme;
}
void sortByPopularity(int *array, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (*(array + j) < *(array + (j + 1)))
            {
                int temp = *(array + j);
                *(array + j) = *(array + (j + 1));
                *(array + (j + 1)) = temp;
            }
        }
    }
}

int main()
{

    int size = 5;
    // cout << "Enter products size : ";
    // cin >> size;
    // int *products = new (nothrow) int[size];
    int *products = new (nothrow) int[size];

    int ar[] = {20, 90, 60, 80, 90};
    products = ar;

    cout << "Products [ ";
    for (int i = 0; i < size; i++)
    {
        // *(products + i) = rnd();

        if (i == 0)
        {
            cout << *(products + i);
        }
        else
        {
            cout << "," << *(products + i);
        }
    }
    cout << " ]" << endl;

    cout << "Average Stock Value : " << avg(products, size) << endl;
    cout << "Critical Products : " << endl;
    critical(products, size);
    cout << "Top Selling products :" << endl;
    int top_prod_index = findTopSellingProduct(products, size);
    cout << "Second Best-Selling Product:" << endl;
    int *item = findSecondBestSeller(products, size, top_prod_index);
    cout << "\tSecond top product : " << *item << " at [" << *(item + 1) << "]" << endl;

    sortByPopularity(products, size);
    cout << "After Sorting : " << endl;

    cout << "Products [ ";
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            cout << *(products + i);
        }
        else
        {
            cout << "," << *(products + i);
        }
    }
    cout << " ]" << endl;

    return 0;
}