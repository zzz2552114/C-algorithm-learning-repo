#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,target;
    cin >> n>>target;

    vector<int> vec(n);
    for (int i = 0; i < n;i++){
        cin >> vec[i];
    }
    // 已知vector有序递增，找一个最左边的target
    int l = 0, r = n - 1;
    while(l<r){
        int mid = (l + r) / 2; // 这里是(l+r)/2而不是(l+r+1)/2是为了处理形如(0,1)的边界条件
        if (vec[mid] >= target){
            r = mid; // 这里很显然是要把右指针往做拉，拿(1,2,2,2,2,3)举例即可，因为要求最左边的2
        }
        else
            l = mid + 1;
    } // 最后肯定会会合的
    if(vec[l] == target){
        cout << l << endl;
    }else
        cout << "Not found";
}