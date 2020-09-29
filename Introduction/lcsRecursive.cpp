#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t, int ** dp) {
	if(s.size() == 0 || t.size() == 0) {
		return 0;
	}
	if(s[0] == t[0]) {
		int ans = 1 + lcs(s.substr(1), t.substr(1), dp);
		dp[0][0] = ans;
		return ans;
	}
	if(dp[s.size()][t.size()]) {
		return dp[s.size()][t.size()];
	}
	else {
		int a = lcs(s, t.substr(1), dp);
		int b = lcs(s.substr(1), t, dp);
		int c = lcs(s.substr(1), t.substr(1), dp);
		int ans = max(max(a, b), c);
		dp[s.size()][t.size()] = ans;
		return ans;
	}
}

int main() {
	string s, t;
	cin >> s >> t;
	int **dp = new int*[s.size() + 1];
	for(int i = 0; i < s; i++) {
		dp[i] = new int[t.size() + 1];
		for(int j = 0; j < t; j++) {
			dp[i][j] = 0;
		}
	}
	cout << lcs(s, t, dp) << endl;
}