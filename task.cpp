#include <iostream>
#include <string>

using namespace std;

int main()
{

    //  memory allocation with new and delete

    int *ptr1 = new int(100);
    cout << "ptr1 =" << *ptr1 << endl;
    delete ptr1;

    //  memory allocation with maloc and free

    int *ptr2 = (int *)malloc(sizeof(int));
    cout << "ptr2 =" << *ptr2 << endl;
    delete ptr2;

    //  array with new

    int *ptr3 = new int[10];
    free(ptr3);

    //  array with alloc

    int *ptr4 = (int *)calloc(4, sizeof(int));
    free(ptr4);

    // nothrow

    int *ptr5 = new (nothrow) int[100000000000000];
    delete[] ptr5;


    void *ptrv = new int(2);
    int *ptri = (int*) ptrv ;

    cout<<*ptri<<endl;
    cout<<*((int*)ptrv)<<endl;
    void *ptrs = new char('1');
    cout<<(char*)(ptrs)<<endl;

    // int *ptr6 = (int*) ptrv;


    return 0;
}