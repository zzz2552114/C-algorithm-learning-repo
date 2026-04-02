#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> dir(n),lr(m),num(m);
    vector<string> dowhat(n);
    for (int i = 0; i < n;i++){
        cin >> dir[i] >> dowhat[i];
    }
    for (int i = 0; i < m;i++){
        cin >> lr[i] >> num[i];
    }
    // 输入完毕

    // 开始模拟
    // 因为是一个圈，想到取模运算
    // 想一下朝向和左右的逻辑，定义顺时针为0，逆时针为1，如果朝向圈内，左为顺时针，如果朝向圈外，右为顺时针，想到了位运算。00 -> 0 11->0 异或运算为0是顺时针，为1是逆时针
    int pos = 0;
    for (int i = 0; i < m;i++){
        int fin = lr[i] ^ dir[pos];
        if(fin){
            pos += num[i];
            pos %= n;
        }
        else{
            pos -= num[i];
            pos %= n;
            if(pos<0)
                pos += n;
        }
    }
    cout << dowhat[pos] << endl;
}