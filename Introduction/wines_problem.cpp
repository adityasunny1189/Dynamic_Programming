#include<bits/stdc++.h>
using namespace std;

int winesPrice(int *arr, int n, int year) {
	if(n == 1) {
		return (year * arr[0]);
	}
	int op1 = winesPrice(arr + 1, n - 1, year + 1) + (year * arr[0]);
	int op2 = winesPrice(arr, n - 1, year + 1) + (year * arr[n - 1]);
	int ans = max(op1, op2);
	return ans;
}

int main() {
	// freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int arr[] = {2, 3, 5, 1, 4};
	int price = winesPrice(arr, 5, 1);
	cout << price << endl;
}