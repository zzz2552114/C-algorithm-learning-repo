#include<bits/stdc++.h>
using namespace std;
long long n,m,d;
int main(){
    
    long long ans = 0;
    cin >> n >> m >> d;
    if(m ==0 && n ==0){
        cout << 0;
        return 0;
    }
    if(m==0 || m<n*(d+1)){
        cout << -1;
        return 0;
    }
    else if(n*(d+2) > m){
        ans = m - n * (d+1);
    }
    else{
        ans = ((m - n * (d + 2))) / (d + 1);
        ans += n;
    }
    cout << ans;
}