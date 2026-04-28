#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int f,v;
int arr[105][105];
int dp[105][105];
int path[105][105];
int main(){
	memset(dp,0xc0,sizeof(dp));
	dp[0][0] = 0;
	scanf("%d %d",&f,&v);
	for( int i = 1;i<=f;i++){
		for(int j = 1;j<=v;j++) scanf("%d",&arr[i][j]);
		dp[0][i] = 0;
		dp[i][i] = dp[i-1][i-1] + arr[i][i];
		path[i][i] = i;
	}
	for(int i = f+1;i<=v+1;i++) dp[0][i] = 0;
	
	for(int i = 1;i<=f;i++){
		for(int j = i+1;j<=v-f+i;j++){
			for(int t = i;t<=j;t++){
				if(dp[i-1][t-1]+arr[i][t]>dp[i][j]){
					dp[i][j] = dp[i-1][t-1]+arr[i][t];
					path[i][j] = t;
				}
			}
		}
	}
	int temp[105];
	temp[f] = path[f][v];
	for(int i = f-1;i>=1;i--){
		int pos = temp[i+1];
		temp[i] = path[i][pos-1];
	}
	cout << dp[f][v] << '\n';
	for(int i = 1;i<=f;i++) cout << temp[i] << ' ';
}