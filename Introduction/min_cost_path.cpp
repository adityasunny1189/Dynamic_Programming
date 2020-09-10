#include<bits/stdc++.h>
using namespace std;

// Brute Force
int minCostRec(int **arr, int sm, int sn, int m, int n) {
	if(sm == m && sn == n) {
		return arr[sm][sn];
	}

	int op1, op2, op3;
	op1 = op2 = op3 = INT_MAX;
	if(sm < m && sn < n) {
		op1 = minCostRec(arr, sm + 1, sn + 1, m, n);
		op2 = minCostRec(arr, sm + 1, sn, m, n);
		op3 = minCostRec(arr, sm, sn + 1, m, n);
	}
	else if(sm < m) {
		op1 = minCostRec(arr, sm + 1, sn, m, n);
	}
	else if(sn < n) {
		op1 = minCostRec(arr, sm, sn + 1, m, n);
	}
	int ans = arr[sm][sn] + min(min(op1, op2), op3);
	return ans;
}

// Memoization
int minCostMemo(int **arr, int sm, int sn, int m, int n, int **dp) {
	if(sm == m && sn == n) {
		return arr[sm][sn];
	}
	if(sm > m || sn > n) {
		return INT_MAX;
	}
	if(dp[sm][sn] != 0) {
		return dp[sm][sn];
	}
	int op1, op2, op3;
	op1 = op2 = op3 = INT_MAX;
	op1 = minCostMemo(arr, sm + 1, sn + 1, m, n, dp);
	op2 = minCostMemo(arr, sm + 1, sn, m, n, dp);
	op3 = minCostMemo(arr, sm, sn + 1, m, n, dp);
	int ans = arr[sm][sn] + min(min(op1, op2), op3);
	dp[sm][sn] = ans;
	return ans;
}

// Dynamic Programming
int minCostDP(int **arr, int sm, int sn, int m, int n) {
	int **dp = new int*[m + 1];
	for(int i = 0; i <= m; i++) {
		dp[i] = new int[n + 1];
		for(int j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}

	dp[m][n] = arr[m][n];

	// Last Row
	int i = m;
	for(int j = n - 1; j >= 0; j--) {
		dp[i][j] = arr[i][j] + dp[i][j + 1];
	}

	// Last Column
	i = n;
	for(int j = m - 1; j >= 0; j--) {
		dp[j][i] = arr[j][i] + dp[j + 1][i];
	}

	for(int i = m - 1; i >= 0; i--) {
		for(int j = n - 1; j >= 0; j--) {
			dp[i][j] = min(min(dp[i + 1][j + 1], dp[i + 1][j]), dp[i][j + 1]) + arr[i][j];
		}
	}
	return dp[0][0];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m, n;
	cin >> m >> n;
	int **arr = new int*[m];
	for(int i = 0; i < m; i++) {
		arr[i] = new int[n];
		for(int j = 0; j < n; j++) {
			int ele;
			cin >> ele;
			arr[i][j] = ele;
		}
	}
	int **dp = new int*[m];
	for(int i = 0; i < m; i++) {
		dp[i] = new int[n];
		for(int j = 0; j < n; j++) {
			dp[i][j] = 0;
		}
	}

	int minCostPath = minCostMemo(arr, 0, 0, m - 1, n - 1, dp);
	cout << minCostPath << endl;

	cout << minCostDP(arr, 0, 0, m - 1, n - 1) << endl;
}