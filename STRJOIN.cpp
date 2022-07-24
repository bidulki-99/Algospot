#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define REP(i, a, b) for (int i = a; i <= b; i++)

int n;
priority_queue<int, vector<int>, greater<int>> len;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	for (cin >> c; c--;) {
		len = priority_queue<int, vector<int>, greater<int>>();

		cin >> n;

		int temp;
		rep(i, 0, n) {
			cin >> temp;
			len.push(temp);
		}

		int ans = 0;
		while (true) {
			temp = len.top();
			len.pop();
			temp += len.top();
			len.pop();
			ans += temp;

			if (len.empty())
				break;

			len.push(temp);
		}

		cout << ans << '\n';
	}
}
