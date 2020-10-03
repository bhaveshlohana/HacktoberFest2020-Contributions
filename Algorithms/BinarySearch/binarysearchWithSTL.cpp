//Binary Search in C++ Standard Template Library (STL)

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int array[] = {1, 2, 4, 5, 7, 8, 9, 12};
    int arraysize = sizeof(array) / sizeof(array[0]);

    //sorting the array is required for Binary Search Algorithm
    sort(array, array + arraysize);

    int element; //element to be searched for
    cin >> element;

    if (binary_search(array, array + arraysize, element))
        cout << "\nElement found in the array";
    else
        cout << "\nElement not found in the array";

    return 0;
}
