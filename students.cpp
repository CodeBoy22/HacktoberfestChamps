#include <iostream>
using namespace std;
float student_percentage(float marks[], int column) {
    float percentage;
    float total = 0;
    for(int i = 0; i < column; i++) {
        total = total + marks[i];
    }
    percentage = (total / column);
    return percentage;
}
float student_total_marks(float marks[], int column) {
    float total = 0;
    for(int i = 0; i < column; i++) {
        total = total + marks[i];
    }
    return total;
}
float class_average(float marks[], int r) {
    float average;
    float total = 0;
    for(int i = 0; i < r; i++) {
        total = total + marks[i];
    }
    average = (total / r);
    return average;
}
int sorting_marks(float marks[],int l, int u) {
    float pivot = marks[l];
    float temp;
    int p = l;
    while(l <= u) {
        while(marks[l] >= pivot) {
            l = l + 1;
        }
        while(marks[u] < pivot) {
            u = u - 1;
        }
        if(l < u) {
            temp = marks[u];
            marks[u] = marks[l];
            marks[l] = temp;
        }
    }
    temp = marks[p];
    marks[p] = marks[u];
    marks[u] = temp;
    
    return u;
}
void sorting_student_marks(float marks[], int l , int u) {
    int p;
    if(l < u) {
        p = sorting_marks(marks,l,u);
        sorting_student_marks(marks,l,p-1);
        sorting_student_marks(marks,p+1,u);
    }
}
int student_rank(float marks[],int size, float search) {
    int l = 0, u = size - 1;
    int mid = (l + u) / 2;
    while(l <= u) {
        if(marks[mid] == search) {
            return mid;
        }
        else if(marks[mid] > search) {
            l = mid + 1;
            mid = (l + u) / 2;
        }
        else {
            u = mid - 1;
            mid = (l + u) / 2;
        }
    }
    return -1;
}
int main()
{
    int row = 5;
    int column = 6;
    float total_marks = 0;
    float marks[row][column];
    float totalMark[row];
    float *Student[row];
    float percentage[column];
    cout << "-----Input Student Detail--------" << endl;
    for(int i = 0; i < row; i++) {
        Student[i] = marks[i];
        cout << endl << "Enter Marks For Student no."<<i+1<<": "<< endl;
        for(int j = 0; j < column; j++) {
            cout << "\tFor subject " << j + 1 << " : ";
            cin >> Student[i][j];
        }
    }
    for(int i = 0; i < row; i++) {
        percentage[i] = student_percentage(Student[i],column); 
        totalMark[i] = student_total_marks(Student[i],column); 
    }
    cout << endl << "--------Student percentage and rank--------" << endl;
    for(int i = 0; i < row; i++) {
        cout << endl << "Student no. " << i + 1;
        cout << "Percentage : " << percentage[i];
        total_marks = 0;
        for(int j = 0; j < column; j++) {
            total_marks = total_marks + Student[i][j];
        }
        cout<<"\nposition is: "<<(student_rank(totalMark,row,total_marks)+1);
    }
    cout << endl << "--------Class average---------" << endl << endl;
    cout << "average of the class is: "<<class_average(percentage,row)<<endl;
    sorting_student_marks(totalMark,0,row);
    return 0;
}
