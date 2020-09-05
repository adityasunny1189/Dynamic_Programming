#include<bits/stdc++.h>
using namespace std;

// Top-Down
int topDown(int n, int *dp) {
	if(n <= 1) {
		return 0;
	}
	if(dp[n] != 0) {
		return dp[n];
	}
	int x, y = INT_MAX, z = INT_MAX;
	x = topDown(n - 1, dp);
	if(n % 2 == 0) {
		y = topDown(n / 2, dp);
	}
	if(n % 3 == 0) {
		z = topDown(n / 3, dp);
	}
	dp[n] = min(x, min(y, z)) + 1;
	return dp[n];
}

// Bottom-Up
int bottomUp(int n) {
	int *dp = new int[100];
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for(int i = 4; i <= n; i++) {
		int x = dp[i - 1];
		int y = INT_MAX;
		if(i % 2 == 0) {
			y = dp[i / 2];
		}
		int z = INT_MAX;
		if(i % 3 == 0) {
			z = dp[i / 3];
		}
		dp[i] = min(x, min(y, z)) + 1;
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