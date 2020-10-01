
#include<iostream>
using namespace std;

int Partition ( int A[],int start ,int end) {
    int i = start + 1;
    int piv = A[start] ;            //make the first element as pivot element.
    for(int j =start + 1; j <= end ; j++ )  {
    /*rearrange the array by putting elements which are less than pivot
       on one side and which are greater that on other. */

          if ( A[ j ] < piv) {
                 swap (A[ i ],A [ j ]);
            i += 1;
        }
   }
   swap ( A[ start ] ,A[ i-1 ] ) ;  //put the pivot element in its proper place.
   return i-1;                      //return the position of the pivot
}

void QuickSort ( int A[ ] ,int start , int end ) {
   if( start < end ) {
        //stores the position of pivot element
         int piv_pos = Partition (A,start , end ) ;     
         QuickSort (A,start , piv_pos -1);    //sorts the left side of pivot.
         QuickSort ( A,piv_pos +1 , end) ; //sorts the right side of pivot.
   }
}

int main()
{
    int a[] = {854,177,839,428,733,143,112,751}; // you can input number during runtime
    QuickSort(a,0,7);
    cout<<"Sorted Array = ";
    for(int i = 0; i < 8; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

