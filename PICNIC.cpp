#include <bits/stdc++.h>
using namespace std;

int n, m;
bool areFriends[10][10];
bool taken[10];

int countPairings(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1)
		return 1;

	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if(!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	cin >> c;

	while (c--) {
		cin >> n >> m;

		int temp1, temp2;
		memset(areFriends, false, sizeof(areFriends));
		for (int i = 0; i < m; i++) {
			cin >> temp1 >> temp2;
			areFriends[temp1][temp2] = areFriends[temp2][temp1] = true;
		}

		memset(taken, false, sizeof(taken));

		cout << countPairings(taken) << '\n';
	}
}
