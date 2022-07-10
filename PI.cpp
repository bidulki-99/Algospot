#include <bits/stdc++.h>
using namespace std;

int dp[10001];
string str;

int case3(const string& s) {
	if (s[0] == s[1] and s[1] == s[2])
		return 1;
	if ((s[1] - s[0] == 1 and s[2] - s[1] == 1) or (s[0] - s[1] == 1 and s[1] - s[2] == 1))
		return 2;
	if (s[0] == s[2])
		return 4;
	if (s[1] - s[0] == s[2] - s[1])
		return 5;
	return 10;
}

int case4(const string& s) {
	if (s[0] == s[1] and s[1] == s[2] and s[2] == s[3])
		return 1;
	if ((s[1] - s[0] == 1 and s[2] - s[1] == 1 and s[3] - s[2] == 1) or (s[0] - s[1] == 1 and s[1] - s[2] == 1 and s[2] - s[3] == 1))
		return 2;
	if (s[0] == s[2] and s[1] == s[3])
		return 4;
	if (s[1] - s[0] == s[2] - s[1] and s[2] - s[1] == s[3] - s[2])
		return 5;
	return 10;
}

int case5(const string& s) {
	if (s[0] == s[1] and s[1] == s[2] and s[2] == s[3] and s[3] == s[4])
		return 1;
	if ((s[1] - s[0] == 1 and s[2] - s[1] == 1 and s[3] - s[2] == 1 and s[4] - s[3] == 1) or (s[0] - s[1] == 1 and s[1] - s[2] == 1 and s[2] - s[3] == 1 and s[3] - s[4] == 1))
		return 2;
	if (s[0] == s[2] and s[1] == s[3] and s[2] == s[4])
		return 4;
	if (s[1] - s[0] == s[2] - s[1] and s[2] - s[1] == s[3] - s[2] and s[4] - s[3] == s[3] - s[2])
		return 5;
	return 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
	for (cin >> c; c--;) {
		memset(dp, 0, sizeof(dp));
		cin >> str;

		dp[3] = case3(str.substr(0, 3));
		dp[4] = case4(str.substr(0, 4));
		dp[5] = case5(str.substr(0, 5));
		dp[6] = case3(str.substr(0, 3)) + case3(str.substr(3, 3));
		dp[7] = min(case3(str.substr(0, 3)) + case4(str.substr(3, 4)), case4(str.substr(0, 4)) + case3(str.substr(4, 3)));
		dp[8] = min({case3(str.substr(0, 3)) + case5(str.substr(3, 5)), case4(str.substr(0, 4)) + case4(str.substr(4, 4)), case5(str.substr(0, 5)) + case3(str.substr(5, 3))});

		for (int i = 9; i <= str.size(); i++) {
			dp[i] = dp[i - 3] + case3(str.substr(i - 3, 3));
			dp[i] = min(dp[i], dp[i - 4] + case4(str.substr(i - 4, 4)));
			dp[i] = min(dp[i], dp[i - 5] + case5(str.substr(i - 5, 5)));
		}

		cout << dp[str.length()] << '\n';
	}
}
