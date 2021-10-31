#include <iostream>
using namespace std;
int main()
{
int size = 10;
int array[size];
for (int i = 0; i< size; i++)
{
cout<< "Index " <<i<< " ";
cin>> array[i];
}
int key;
cout<< "\nEnter the number you want to search: ";
cin>>key;
int ele = -1;
for (int i = 0; i< size; i++)
{
if (array[i] == key)
{
ele = i;

}
}
cout<< "\nThe index of number " << key << " is " <<ele<<endl;
return 0;
}



