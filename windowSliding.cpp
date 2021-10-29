#include<bits/stdc++.h>
#include<numeric>
#include<math.h>
using namespace std;
const int INF = 1e9;
const int N = 1e7+3;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k; cin>>k;

    int curr_sum = 0;
    for(int i = 0; i < k; i++){
        curr_sum += arr[i];
    }

    int max_sum = curr_sum;
    for(int i=k; i < n; i++){
        curr_sum += arr[i];
        curr_sum -= arr[i-k];
        max_sum = max(max_sum, curr_sum);
    }

    cout<<max_sum<<endl;
    return 0;
}