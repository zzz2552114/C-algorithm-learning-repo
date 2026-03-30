#include <bits/stdc++.h>
using namespace std;
// 归并排序的递归实现
// 先切小块，给最小块排序，再二分叠加排序
int n;
vector<int> vec;

void merge(int i, int j, int mid)
{

    vector<int> temp; // 这里会释放啊
    int t = mid + 1, l = i;
    while (l <= mid && t <= j)
    {
        if (vec[l] < vec[t])
        {
            temp.push_back(vec[l]);
            l++;
        }
        else
        {
            temp.push_back(vec[t]);
            t++;
        }
    }
    while (l <= mid)
    {
        temp.push_back(vec[l]);
        l++;
    }
    while (t <= j)
    {
        temp.push_back(vec[t]);
        t++;
    }
    for (int m = 0; m < (int)temp.size(); m++)
    {
        vec[i] = temp[m];
        i++;
    }
}

void cut(int i,int j){
    if (i >= j)
        return;
    int mid = (i + j) / 2;
    cut(i, mid);
    cut(mid + 1, j);
    merge(i, j, mid);
}


int main(){
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int t;
        cin >> t;
        vec.push_back(t);
    }
    cut(0, n - 1);
    for(int x:vec){
        cout << x << ' ';
    }
}