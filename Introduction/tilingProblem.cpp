#include<bits/stdc++.h>
using namespace std;
int countTile(int n, int m, int **dp) {
	if(dp[n][m] != 0) {
		return dp[n][m];
	}
	if(n < m) {
		return 1; 
	}
	if(n == m) {
		return 2;
	}
	int h = countTile(n - m, m, dp);
	int v = countTile(n - 1, m, dp);
	return dp[n][m] = (h + v);
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int **dp = new int*[n + 1];
		for(int i = 0; i <= n; i++) {
			dp[i] = new int[m + 1];
			for(int j = 0; j <= m; j++) {
				dp[i][j] = 0;
			}
		}
		int ans = countTile(n, m, dp);
		cout << ans << endl;
	}
}