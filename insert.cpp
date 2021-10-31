#include <iostream>
using namespace std;
int main()
{
int size;
cout<< "Enter the size of array: ";
cin>>size;
int arr[size];
for (int i = 0; i< size; i++) {
cout<< "Index " <<i<< " ";
cin>>arr[i];
}
int key;
cout<< "Enter the value you want to insert" <<endl;
cin>>key;
int i;
for(i=size-1; (i>= 0 &&arr[i] > key); i--) {
arr[i+1] = arr[i];
}
arr[i+1]=key;
size = size+1;
cout<< "Array after insertion" <<endl;
for(int i=0; i<size; i++) {
cout<<arr[i] << " ";
}
cout<<endl;
return 0;
}



