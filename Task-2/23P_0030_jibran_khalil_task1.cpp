#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int rnd()
{
    // srand(unsigned(time(NULL)));
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
void critical(int *array, int size,float average)
{
    float total = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) > average)
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
        if (max > *(array + i))
        {
            max = *(array + i);
            max_Prod_index = i;
        }
    }
    cout << "\tproduct : " << max << " at [" << max_Prod_index << "]" << endl;
    return max;
}
int *findSecondBestSeller(int *array, int size, int top)
{
    int second;
    if (*array == top)
    {
        second = *(array + 1);
    }
    else if (*(array + 1) == top)
    {
        second = *array;
    }
    else
    {
        second = *array;
    }
    int ind = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) != top)
        {
            if (second > *(array + i))
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
                int tem = *(array + j);
                *(array + j) = *(array + (j + 1));
                *(array + (j + 1)) = tem;
            }
        }
    }
}

int main()
{

    int size;
    cout << "Enter products size : ";
    cin >> size;
    int *products = new (nothrow) int[size];
    cout << "Products [ ";
    for (int i = 0; i < size; i++)
    {
        *(products + i) = rnd();

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
    float average = avg(products, size);
    cout << "Average Stock Value : " << average << endl;
    cout << "Critical Products : " << endl;
    critical(products, size,average);
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