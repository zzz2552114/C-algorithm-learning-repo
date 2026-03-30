/* 
题干：一个数组nums，一个整数k，任意把nums全部分成k个 连续 的k部分
并且对这k个部分求和，把nums里k个求和的最大值记为Max
找到所有分法里Max最小的那一种分法，并且返回最小的Max
2024-5 T3
*/
#include <bits/stdc++.h>
using namespace std;
// 二分答案
int n,k;

bool check(int mid, vector<int> vec){
    // 因为说了要把nums分成连续的，可以一个一个往里面扔
    int sum = 0, i = 0, cnt = 1;
    while(i<n){
        if(sum+vec[i]<=mid){
            sum += vec[i];
        }
        else{
            sum = vec[i];
            cnt++;
        }
        i++;
        if(cnt > k){
            return 0;
        }
    }
    return 1;
}


int main(){
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0;i<n;i++){
        cin >> nums[i];
    }
    int l = 1, r = 1e9; // 这里右边界取决于数据范围，这里用l和r试图二分夹出来答案Max.min
    while(l < r){
        int mid = (l + r) / 2;
        // 下面要借助一个bool函数来判断mid
        if(check(mid,nums)){
            r = mid;
        }
        else
            l = mid+1;
    }
    cout << r << endl;
}