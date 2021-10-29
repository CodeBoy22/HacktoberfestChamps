#include<bits/stdc++.h>
#include<numeric>
#include<math.h>
using namespace std;
const int INF = 1e9;
const int N = 1e7+3;

int maxEvenOdd(int arr[], int n){
    int res = 1;
    int curr = 1;

    for(int i=0; i<n; i++){
        if((arr[i]%2 == 0 and arr[i-1]%2 != 0) or (arr[i]%2 != 0 and arr[i-1]%2 == 0)){
            curr ++;
            res = max(res, curr);
        }
    }

    return res;
}

int main()
{
    int n; cin>>n;
    int arr[n]; for(int i=0; i<n; i++) cin>>arr[i];

    cout<<maxEvenOdd(arr, n)<<endl;
    return 0;
}