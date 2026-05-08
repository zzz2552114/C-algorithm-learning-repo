#include<iostream>
#include<algorithm>
using namespace std;
int n,minK,maxK,arr[100010];
int main(){
	cin >> n >> minK >> maxK;
	if(maxK<minK){
		cout << -1;
		return 0;
	}
	for(int i = 1;i<=n;i++) scanf("&d",arr[i]);
	int prev = 0,back = 0;
	bool lf = 0,rf = 0;
	int ans = 0;
	if(maxK>minK){
		for(int i = 0;i<n;i++){
			if(arr[i]<maxK && arr[i]>minK){
				if(!lf) prev++;
				else if(rf) back++; 
			}
			else if(arr[i]==minK) lf = 1;
			else if(arr[i]==maxK) rf = 1;
			else if(lf && rf){
				if(prev && back) ans += prev*back;
				else ans+= max(prev,back);
			}
			else{
				lf = 0,rf = 0,prev = 0,back = 0;
			}
		}
	}
	cout << ans;
}