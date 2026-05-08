#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int arr[26];
int main()
{
	vector<char> ans;
	int maxc = 0;
	string s;
	getline(cin,s);
	int n = (int)s.size();
	for(int i = 0;i<n;i++){
		// 实则就是统计a-z各自的长度
		// 但是我还需要知道顺序。。。
		// 用一个数据结构同步记录下来就可以知道顺序了
		arr[s[i]-'a']++;
		if(arr[s[i]-'a']>maxc){
			maxc = arr[s[i]-'a'];
			ans.clear();
			ans.push_back(s[i]);
		}
		
		else if(arr[s[i]-'a'] == maxc) ans.push_back(s[i]);
	}
	string res;
	res = "";
	for(int i = 0;i<(int)ans.size();i++){
		res+=ans[i];
	}
	cout << res;
}