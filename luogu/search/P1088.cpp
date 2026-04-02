#include <bits/stdc++.h>
using namespace std;
int n, m,ans = 0;
vector<int> start;
const int maxN = 1e5 + 10;
int check[maxN];
int arr[maxN];

void basedfs(int i){
    if (i >= n)
    {
        ans++;
        if (ans == m)
        {
            for (int k = 0; k < n; k++)
            {
                cout << arr[k] << ' ';
            }
            cout << endl;
        }
        return;
    }
    for (int j = 1; j <= n;j++){
        if(!check[j]){
            check[j] = 1;
            arr[i] = j ;
            basedfs(i + 1);
            if(ans ==m)
                return;
            check[j] = 0;

        }
    }
}

void dfs(int i,int k){
    check[k] = 0;
    for (int j = k+1; j <= n;j++){
        if(!check[j]){
            check[arr[i]] = 0;
            arr[i] = j;
            check[j] = 1;
            basedfs(i + 1);
            if(ans == m)
                return;
            check[j] = 0;
        }
    }
    dfs(i - 1, start[i - 1]);
}

int main(){
    cin >> n >> m;
    int t;
    memset(check, 0, sizeof(check));
    for (int i = 0; i < n;i++){
        cin >> t;
        start.push_back(t);
        arr[i] = t;
        check[t] = 1;
    }
    check[start[n - 1]] = 0;

    dfs(n - 2,start[n-2]);
}