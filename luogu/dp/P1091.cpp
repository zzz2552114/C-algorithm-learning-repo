#include<iostream>
using namespace std;
int n,arr[105],lis[105],lds[105];
int main(){
    cin >> n;
    for (int i = 1;i<=n;i++){
        cin >> arr[i];
        lis[i] = 1;
        lds[i] = 1;
    }
    // 思路，线性dp，最大上升子序列和最大下降子序列的求和,写ON^2的复杂度即可
    for (int i = 2; i <= n;i++){
        for (int j = 1; j < i;j++)
            if (arr[i] > arr[j]) lis[i] = max(lis[i],lis[j]+1);
    }
    for (int i = n; i >= 1;i--){
        for (int j = n; j > i;j--)
            if(arr[i]>arr[j]) lds[i] = max(lds[i],lds[j]+1);
    }
    int maxl = lis[1] + lds[1];
    for (int i = 0; i <= n;i++) maxl = max(maxl,lis[i]+lds[i]);
    cout << n - maxl + 1 << endl;
}