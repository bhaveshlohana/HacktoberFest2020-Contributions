#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0; i<arr.length; ++i)
        printf("%d ",arr.A[i]);
}

void Append(struct Array *arr,int x)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length++]=x;
    }

}

void Insert(struct Array *arr,int index,int x)
{
    int i;
    if(index>=0 && index<=arr->length)
    {
        for(i=arr->length; i>index; --i)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[i]=x;
        arr->length++;
    }
}

int Delete(struct Array *arr,int index)
{
    int i;
    int x=0;
    if(index>=0 && index<=arr->length)
    {
        x=arr->A[index];
        for(i=index; i<arr->length; ++i)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int LinearSearch(struct Array *arr,int key)
{
    int i;
    for(i=0; i<arr->length; ++i)
    {
        if(arr->A[i]==key)
        {
            printf("\nSearched at position %d\n",i);
            Swap(&arr->A[i],&arr->A[i-1]);
            return i;
        }
    }
    printf("Not Searched");
    return -1;
}

int BinarySearch(struct Array arr,int key)
{
    int l,h,mid;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;

        if(key==arr.A[mid])
            return mid;

        else if(key<arr.A[mid])
            h=mid-1;

        else
            l=mid+1;
    }
    return -1;
}

int RBinSearch(int A[],int l,int h,int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;

        if(key==A[mid])
            return mid;

        else if(key<A[mid])
            return RBinSearch(A,l,mid-1,key);

        else
            return RBinSearch(A,mid+1,h,key);
    }
    return -1;
}

void Reverse(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1; i<j; ++i,--j)
    {
        Swap(&arr->A[i],&arr->A[j]);
    }
}

void LeftRotate(struct Array *arr)
{
    int i,temp;
    temp=arr->A[0];
    for(i=0; i<arr->length-1; ++i)
    {
        arr->A[i]=arr->A[i+1];
    }
    arr->A[i]=temp;
}

void InsertSort(struct Array *arr,int x)
{
    if(arr->length==arr->size)
        printf("\nNo free space\n");
    else
    {
        int i;
        for(i=arr->length-1; arr->A[i]>x && i>=0; --i)
        {
            arr->A[i+1]=arr->A[i];
        }
        arr->A[i+1]=x;
        arr->length++;
    }
}

int isSorted(struct Array arr)
{
    int i;
    for(i=0; i<arr.length-1; ++i)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

void REarrange(struct Array *arr)
{
    int i=0,j=arr->length-1;
    while(i<=j)
    {
        while(arr->A[i]<0) ++i;
        while(arr->A[j]>=0) --j;
        if(i<j)
        {
            Swap(&arr->A[i],&arr->A[j]);
            ++i;
            --j;

        }

    }
}

struct Array* Merge(struct Array arr1,struct Array arr2)
{
    int i,j,k,m,n;
    i=j=k=0;
    m=arr1.length;
    n=arr2.length;
    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array));
    while(i<m && j<n)
    {
        if(arr1.A[i]<arr2.A[j])
        {
            arr3->A[k]=arr1.A[i];
            ++i;
            ++k;
        }
        else
        {
            arr3->A[k]=arr2.A[j];
            ++j;
            ++k;
        }
    }
    while(i<m)
    {
        arr3->A[k]=arr1.A[i];
        ++i;
        ++k;
    }
    while(j<n)
    {
        arr3->A[k]=arr2.A[j];
        ++j;
        ++k;
    }
    arr3->length=arr1.length+arr2.length;
    arr3->size=arr1.size+arr2.size;
    return arr3;

}

struct Array* Union(struct Array arr1,struct Array arr2)
{
    int i,j,k,m,n;
    i=j=k=0;
    m=arr1.length;
    n=arr2.length;
    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array));
    while(i<m && j<n)
    {
        if(arr1.A[i]<arr2.A[j])
        {
            arr3->A[k]=arr1.A[i];
            ++i;
            ++k;
        }
        else if(arr1.A[i]>arr2.A[j])
        {
            arr3->A[k]=arr2.A[j];
            ++j;
            ++k;
        }
        else
        {
            arr3->A[k]=arr1.A[i];
            ++i;
            ++j;
            ++k;
        }
    }
    while(i<m)
    {
        arr3->A[k]=arr1.A[i];
        ++i;
        ++k;
    }
    while(j<n)
    {
        arr3->A[k]=arr2.A[j];
        ++j;
        ++k;
    }
    arr3->length=k;
    arr3->size=arr1.size+arr2.size;
    return arr3;

}

struct Array* Intersection(struct Array arr1,struct Array arr2)
{
    int i,j,k,m,n;
    i=j=k=0;
    m=arr1.length;
    n=arr2.length;
    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array));
    while(i<m && j<n)
    {
        if(arr1.A[i]<arr2.A[j])
        {
            ++i;
        }
        else if(arr1.A[i]>arr2.A[j])
        {
            ++j;
        }
        else
        {
            arr3->A[k]=arr1.A[i];
            ++i;
            ++j;
            ++k;
        }
    }
    arr3->length=k;
    arr3->size=arr1.size;
    return arr3;
}

struct Array* Difference(struct Array arr1,struct Array arr2)
{
    int i,j,k,m,n;
    i=j=k=0;
    m=arr1.length;
    n=arr2.length;
    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array));
    while(i<m && j<n)
    {
        if(arr1.A[i]<arr2.A[j])
        {
            arr3->A[k]=arr1.A[i];
            ++i;
            ++k;
        }
        else if(arr1.A[i]>arr2.A[j])
        {
            ++j;
        }
        else
        {
            ++i;
            ++j;
        }
    }
    while(i<m)
    {
        arr3->A[k]=arr1.A[i];
        ++i;
        ++k;
    }
    arr3->length=k;
    arr3->size=arr1.size;
    return arr3;

}


int main()
{
    struct Array arr1;
    int ch;

    printf("Enter size of an array :");
    scanf("%d",&arr1.size);
    arr1.A=(int*)malloc(arr1.size*sizeof(int));
    arr1.length=0;

    printf("Menu\n");
    printf("1: Insert\n");
    printf("2: Delete\n");
    printf("3: Search\n");
    printf("4: LeftRotate\n");
    printf("5: Display\n");
    printf("6: Exit\n");


    do
    {

        printf("\nEnter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
        {
            int x, index;
            printf("Enter element and index :\n");
            scanf("%d%d",&x,&index);
            Insert(&arr1,index,x);
            break;
        }
        case 2:
        {
            int index;
            printf("Enter index :\n");
            scanf("%d",&index);
            printf("Element removed : %d",Delete(&arr1,index));
            break;
        }
        case 3:
        {
            int x;
            printf("Enter element to be searched :\n");
            scanf("%d",&x);
            printf("Searched at index: %d\n",BinarySearch(arr1,x));
            break;
        }
        case 4:
        {
            LeftRotate(&arr1);
            break;
        }
        case 5:
        {
            Display(arr1);
        }

       }  //switch ends here
    }while(ch<6);

    free(arr1.A);

        return 0;
}


