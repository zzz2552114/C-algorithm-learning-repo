#include<bits/stdc++.h>
using namespace std;

bool check(string& s){
    int l = 0, r = (int)s.size() - 1;
    while(l<r){
        if(s[l] != s[r]) return 0;
        l++;
        r--;
    }
    return 1;
}
int main(){
    int t;
    cin >> t;
    long long arr[t];
    for (int i = 0;i<t;i++) cin >> arr[i];
    for (int i = 0;i<t;i++){
        long long x = 1;
        bool flag = 0;
        while(x<=arr[i]){
            string s = to_string(arr[i] - x);
            if(check(s)){
                cout << "Yes" << '\n';
                flag = 1;
                break;
            }
            x *= 2;
        }
        if(!flag) cout << "No" << '\n';
    }
}