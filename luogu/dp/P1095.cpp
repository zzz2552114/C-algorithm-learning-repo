#include<iostream>
using namespace std;
int m, s, t;
int f[300005], dp[300005];
int main(){
    cin >> m >> s >> t;
    for (int i = 1; i <= t;i++){
        if(m>=10){
            f[i] = f[i - 1] + 60;
            m -= 10;
        }else{
            f[i] = f[i - 1];
            m += 4;
        }
    }
    for (int i = 1; i <= t;i++){
        dp[i] = max(f[i], dp[i - 1] + 17);
        if(dp[i]>=s){
            cout <<"Yes" << '\n'<< i<< endl;
            return 0;
        }
    }
    cout <<"No" << '\n'<< dp[t]<< endl;
}