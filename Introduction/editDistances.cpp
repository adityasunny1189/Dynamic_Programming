#include <bits/stdc++.h>
using namespace std;
int editDistance(string s, string t) {
	if(s.size() == 0) {
		return t.size();
	}
    if(t.size() == 0) {
        return s.size();
    }
	if(s[0] == t[0]) {
		return editDistance(s.substr(1), t.substr(1));
	}
	else {
		int insert = editDistance(s.substr(1), t) + 1;
		int remove = editDistance(s, t.substr(1)) + 1;
		int replace = editDistance(s.substr(1), t.substr(1)) + 1;
		return min(insert, min(remove, replace));
	}
}	