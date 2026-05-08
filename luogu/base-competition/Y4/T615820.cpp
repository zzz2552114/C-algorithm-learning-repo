#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    cin >> t;
    while (t--){
        long long n,x;
        cin >> n >> x;
        // 看了题解之后思路和我的很像，最后是约束加数的个数要等于2的某个幂次
        // 因为最后是要表示成2的幂次个x的幂次相加，发现每次把x降幂都会导致加数多x-1的某个倍数
        // 所以先把这个数用x的进制表示出来然后枚举每个系数就可以了
        // !!!这里不是枚举每个系数，这里只需要判断同余即可，因为x-1的系数可以取到任意正整数

        // 所以先用x进制表示即可
        if(x==1){
            bool flag = 1;
            for (long long i = 1; i <= n + 1;i*=2){
                if(i==n){
                    flag = 0;
                    cout << "Yes" <<'\n';
                }
            }
            if(flag) cout << "No" <<'\n';
            continue;
        }
        long long s = 0;
        long long t = n;
        while(t>0){
            s += t % x;
            t /= x;
        }
        bool flag = 1;
        for (long long i = 1; i <=n;i*=2) {
            if(i<s) continue;
            if((i-s)%(x-1)==0) {
                cout << "Yes" << '\n';
                flag = 0;
                break;
            }
        }
        if(flag) cout << "No" << '\n';
    }
}