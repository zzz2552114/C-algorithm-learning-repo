#include <bits/stdc++.h>
using namespace std;

int n;

void fast(vector<int>& vec, int i,int j){
    // 选取第一个元素作为基准值
    if(i >= j)
        return;
    int stan = vec[i] ;
    int l = i, r = j;
    // 双指针，因为选取了第一个元素，所以先动右指针
    while(1)
    {
        for (; r > l;r--)
        {
            if (vec[r] < stan)
            {
                vec[l] = vec[r];
                l++;
                break;
            }
        }
        if(l == r)
            break;
        for (; l < r;l++)
        {
            if(vec[l] > stan)
            {
                vec[r] = vec[l];
                r--;
                break;
            }
        }
        if (l == r)
            break;
    }
    /*
    这里的想法简直惊为天人。！！！首先要知道我们最后指针相遇的时候是会把i=j的地方赋值成stan的
    接下来看循环
    以第一轮为例，把vec[i]赋值成vec[j]，然后i++
    什么意思呢？这里实际上是把比stan小的扔到指针的地方，指针前移，最后stan肯定在这个小的数的右边
    ！！！
    */
    vec[l] = stan;
    fast(vec, i , l - 1);
    fast(vec, r+1 , j);
}
int main() 
{

    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n;i++)
    {
        cin >> vec[i];
    }
    fast(vec,0,n-1);
    for (int x: vec){
        cout << x << ' ';
    }
}