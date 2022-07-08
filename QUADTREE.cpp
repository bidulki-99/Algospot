#include <bits/stdc++.h>
using namespace std;

string reverse(string::iterator& it) {
	char head = *(it++);

	if (head == 'b' or head == 'w')
		return string(1, head);

	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
	string str, ans;
	for (cin >> c; c--;) {
		cin >> str;
		string::iterator it = str.begin();
		cout << reverse(it) << '\n';
	}
}
