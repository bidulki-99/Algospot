#include <bits/stdc++.h>
using namespace std;

const char linked[10][17] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks) {
	for (int i : clocks)
		if (i != 12)
			return false;
	return true;
}

void push(vector<int>& clocks, int swtch) {
	for (int i = 0; i < 16; i++) {
		if (linked[swtch][i] == 'x') {
			clocks[i] += 3;
			if (clocks[i] == 15)
				clocks[i] = 3;
		}
	}
}

int solve(vector<int>& clocks, int swtch) {
	if (swtch == 10)
		return areAligned(clocks) ? 0 : 9999;

	int ret = 9999;
	for (int i = 0; i < 4; i++) {
		ret = min(ret, i + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	for (cin >> c; c--;) {
		vector<int> clocks(16);
		for (int i = 0; i < 16; i++)
			cin >> clocks[i];

		int ans = solve(clocks, 0);
		cout << (ans == 9999 ? -1 : ans) << '\n';
	}
}
