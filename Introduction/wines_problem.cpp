#include<bits/stdc++.h>
using namespace std;

// Brute Force
int winesPrice(int *arr, int i, int j, int year) {
	if(j == i) {
		return (year * arr[i]);
	}
	int op1 = winesPrice(arr, i + 1, j, year + 1) + (year * arr[i]);
	int op2 = winesPrice(arr, i, j - 1, year + 1) + (year * arr[j]);
	int ans = max(op1, op2);
	return ans;
}

// Bottom Up (Memo)
int winesPriceMemo(int *arr, int i, int j, int year, int **dp) {
	if(j == i) {
		return (year * arr[i]);
	}
	if(dp[i][j] != 0) {
		return dp[i][j];
	}
	int op1 = winesPrice(arr, i + 1, j, year + 1) + (year * arr[i]);
	int op2 = winesPrice(arr, i, j - 1, year + 1) + (year * arr[j]);
	int ans = max(op1, op2);
	dp[i][j] = ans;
 	return ans;
}

int main() {
	// freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int arr[] = {2, 4, 5, 6, 3, 1};
	int **dp = new int*[6];
	for(int i = 0; i < 6; i++) {
		dp[i] = new int[6];
		for(int j = 0; j < 6; j++) {
			dp[i][j] = 0;
		}
	}
	int price = winesPrice(arr, 0, 5, 1);
	int priceMemo = winesPriceMemo(arr, 0, 5, 1, dp);
	cout << price << " " << priceMemo << endl;
}