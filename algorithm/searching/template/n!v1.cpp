// 给一个n，对所有小于等于n的数，全排列
#include <bits/stdc++.h>
using namespace std;

int n;
// 还是对每个数枚举放在哪一位
void dfs(int i,vector<int>& arr){ // 这里的i是第几个数
    if(i>=n){
        for(int x:arr){
            cout << x << ' ';
        }
        cout << endl;
        return;
    }
    for (int j = 0; j < n;j++){
        if(!arr[j]){
            arr[j] = i+1;
            dfs(i+1, arr);
            arr[j] = 0;
        }
    }
}

int main(){
    cin >> n;
    vector<int> arr(n,0);
    dfs(0,arr);
}