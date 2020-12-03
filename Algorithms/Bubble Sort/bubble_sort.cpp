#include <iostream>
using namespace std;

void swap(int *f, int *l);

void bubbleSort(int numbers[], int n);

void printsortedarray(int numbers[], int n);

int main()
{
    int n ;
    cout<<"Enter no of elements: \n";
    cin>>n;

    int numbers[n];
    cout<<"Enter the elements: \n";

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    bubbleSort(numbers, n);
    cout<<"Sorted array: \n";
    printsortedarray(numbers, n);
    return 0;
}

void swap(int *f, int *l)
{
    int temp = *f;
    *f = *l;
    *l = temp;
}

void bubbleSort(int numbers[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    for (j = 0; j < n-i-1; j++)
        if (numbers[j] > numbers[j+1])
            swap(&numbers[j], &numbers[j+1]);
}

void printsortedarray(int numbers[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << numbers[i] << " ";
    cout << endl;
}
