#include<bits/stdc++.h>
using namespace std;
int arr[100];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n;i++) cin >> arr[i];
    for (int i = 1; i < n;i++){
        int temp = arr[i];
        int t = i - 1;
        for (; t >= 0;t--){
            if(arr[t]>temp) arr[t+1] = arr[t];
        }
        arr[t+1] = temp;
    }
    for (int i = 0; i < n;i++) cout << arr[i] << ' ';
}