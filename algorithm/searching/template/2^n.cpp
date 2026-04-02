// 给一个n，每个数位上可选可不选，总共2^n选择
#include <bits/stdc++.h>
using namespace std;
// 对每个数进行枚举!!!!!!!!!!!
int n;
void dfs(int i,vector<int>& arr){ // 这里的n是第几位数 总体是一个二叉树的搜索形式
    if(i >= n) {
        for (int j = 0; j < n;j++){
            if(arr[j] == 1){
                cout << j + 1 << ' ';
            }
            else
                cout << "  ";
        }
        cout << endl;
        return;
    }
    arr[i] = 1;
    dfs(i + 1,arr);
    arr[i] = 0;
    dfs(i + 1, arr);
}

int main(){
    cin >> n;
    vector<int> arr(n);
    dfs(0,arr);
}
// 爽！！！！！！