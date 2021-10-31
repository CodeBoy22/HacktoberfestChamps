#include<iostream>
// #include<algorithm>

using namespace std;

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
} 

int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l-1;
    for(int j=l; j<=h-1; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[h]);

    return (i+1);
}

void qSort(int arr[], int l, int h)
{
    if(l<h)
    {
        int  p = partition(arr, l, h);
        qSort(arr, l, p-1);
        qSort(arr, p+1, h);
    }
}

void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    int arr[] = {10, 7, 8, 9, 1, 5};
    n = 6;
    qSort(arr, 0, n-1);
    print(arr, n);

    return 0;
}