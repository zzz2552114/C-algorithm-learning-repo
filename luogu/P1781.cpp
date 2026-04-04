#include<bits/stdc++.h>
using namespace std;

bool cmp(string a,string b){
    if(a.size()==b.size()){
        return a > b;
    }
    return a.size() > b.size();
}
int main(){
    int n;
    cin >> n;
    vector<string> vec(n);
    unordered_map<string, int> mp;
    for (int i = 0; i < n;i++){
        cin >> vec[i];
        mp[vec[i]] = i+1;
    }
    sort(vec.begin(), vec.end(), cmp);
    cout << mp[vec[0]] << '\n' << vec[0] << endl;
}