// timeout code
const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

bool hasWord(int y, int x, const string& word) {
	if (!inRange(y, x))
		return false;
	if (board[y][x] != word[0])
		return false;
	if (word.size() == 1)
		return true;
	
	for (int dir = 0; dir < 8; dir++) {
		int nextY = y + dy[dir];
		int nextX = x + dx[dir];

		if (hasWord(nextY, nextX, word.substr(1)))
			return true;
	}

	return false;
}
