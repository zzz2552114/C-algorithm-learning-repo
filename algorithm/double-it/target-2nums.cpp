#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> func(vector<int> vec, int target)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        int sum = vec[i] + vec[j];
        if (sum > target)
            j--;
        else if (sum < target)
            i++;
        else
            return {i, j};
    }
    return {};
}

int main(){
    int target;
    cin >> n >> target;
    vector<int> vec(n);
    for(int i = 0; i < n;i++){
        cin >> vec[i];
    }
    cout << func(vec, target)[0] << func(vec, target)[1] << endl;
}
