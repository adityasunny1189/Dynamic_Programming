#include<bits/stdc++.h>
using namespace std;

// Top-Down
int topDown(int n, int *dp) {
	if(n == 1 || n == 7 || n == 10) {
		return 1;
	}
	if(dp[n] != 0) {
		return dp[n];
	}
	int x = topDown(n - 1, dp);
	int y  = INT_MAX;
	int z = INT_MAX;
	if(n > 7) {
		y = topDown(n - 7, dp);
	}
	if(n > 10) {
		z = topDown(n - 10, dp);
	}
	dp[n] = min(min(x, y), z) + 1;
	return dp[n];
}

int bottomUp(int n) {
	int *dp = new int[100];
	dp[1] = dp[7] = dp[10] = 1;
	for(int i = 2; i <= n; i++) {
		if(i == 7 || i == 10) {
			continue;
		}
		int x = dp[i - 1];
		int y = INT_MAX, z = INT_MAX;
		if(i > 7) {
			y = dp[i - 7];
		}
		if(i > 10) {
			z = dp[i - 10];
		}
		dp[i] = min(min(x, y), z) + 1;
	}
	return dp[n];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int *dp = new int[100];
		cout << "Top-Down: " << topDown(n, dp) << endl;
		cout << "Bottom-Up: " << bottomUp(n) << endl;
	}
}