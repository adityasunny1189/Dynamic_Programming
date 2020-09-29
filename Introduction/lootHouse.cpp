#include <bits/stdc++.h>
using namespace std;

int max(int *dp, int j, int n) {
    int ans = 0;
    for(int i = j; i < n; i++) {
        if(ans < dp[i]) {
            ans = dp[i];
        }
    }
    return ans;
}

int helper(int *arr, int n, int *dp) {
    dp[n - 1] = arr[n - 1];
    dp[n - 2] = arr[n - 2];
    for(int i = n - 3; i >= 0; i--) {
        dp[i] = arr[i] + max(dp, i + 2, n);
    }
    return max(dp, 0, n);
}


int getMaxMoney(int arr[], int n){
    int *dp = new int[n];
    for(int i = 0; i < n; i++) {
        dp[i] = 0;
    }
    return helper(arr, n, dp);
}

int main() {
    // Will Add later
}