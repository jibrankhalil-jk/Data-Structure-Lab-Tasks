#include <iostream>

using namespace std;

void reverse_array(int *array, int size)
{
  int *first = array;
  int *last = array + size - 1;

  for (; first < last; first++, last--)
  {
    int temp = *first;
    *first = *last;
    *last = temp;
  }
}

int find_min(int *array, int size)
{
  int min = *array;
  for (int i = 0; i < size; i++)
  {
    if (min >= *(array + i))
    {
      min = *(array + i);
    }
  }
  return min;
}
int find_max(int *array, int size)
{
  int max = *array;
  for (int i = 0; i < size; i++)
  {
    if (max <= *(array + i))
    {
      max = *(array + i);
    }
  }
  return max;
}
void shift(int *array, int size)
{
  int *start = array;
  int temp = *(array + size - 1);

  for (int *end = array + size - 1; end > start; end--)
  {
    *end = *(end - 1);
  }
  *start = temp;
}

void print(int *array, int length)
{
  cout << "{ ";
  for (int i = 0; i < length; i++)
  {
    cout << *(array + i) << ", ";
  }

  cout << "}" << endl;
}

int main()
{

  const int array_length = 5;
  int myArra[array_length] = {4, 1, 6, 3, 8};

  // pointer of functions
  void (*reverseArrayptr)(int *, int) = reverse_array;
  int (*findMinptr)(int *, int) = find_min;
  int (*findMaxptr)(int *, int) = find_max;
  void (*shiftArrayptr)(int *, int) = shift;
  void (*printArrayptr)(int *, int) = print;

  // printing array
  printArrayptr(myArra, array_length);
  // find min and max
  cout << "min : " << findMinptr(myArra, array_length) << endl;
  cout << "max : " << findMaxptr(myArra, array_length) << endl;
  // reversig the array
  cout << "Reversing array " << endl;
  reverseArrayptr(myArra, array_length);
  printArrayptr(myArra, array_length);
  // shifting the array
  cout << "shifting array" << endl;
  shiftArrayptr(myArra, array_length);
  printArrayptr(myArra, array_length);

  return 0;
}