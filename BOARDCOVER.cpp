#include <bits/stdc++.h>
using namespace std;

const int coverType[4][3][2] = {
	{ {0, 0}, {1, 0}, {0, 1} },
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, -1} }
};

bool setting(vector<vector<int>>& board, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}

	return ok;
}

int cover(vector<vector<int>>& board) {
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}

		if (y != -1)
			break;
	}

	if (y == -1)
		return 1;
	
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (setting(board, y, x, type, 1))
			ret += cover(board);
		setting(board, y, x, type, -1);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	cin >> c;

	while (c--) {
		int h, w;
		cin >> h >> w;

		vector<vector<int>> board(h);
		string temp;
		for (int i = 0; i < h; i++) {
			cin >> temp;

			for (int j = 0; j < w; j++) {
				if (temp[j] == '#')
					board[i].push_back(1);
				else
					board[i].push_back(0);
			}
		}

		cout << cover(board) << '\n';
	}
}
