#include <bits/stdc++.h>    
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    if(s1 ==s2){
        cout << "Equal" << endl;
    }else{
        cout << "Not Equal" << endl;
        if(s1 < s2){
            cout << s1 << endl;
        }else{
            cout << s2 << endl;
        }
    }
    if( s1.length() == s2.length()){
        cout << "Same Length" << endl;
    }else if(s1.length() < s2.length()){
        cout << s1 << endl;
    }else{
        cout << s2 << endl;
    }

    return 0;
}