#include <bits/stdc++.h>
using namespace std;

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			c[i + j] += a[i] * b[j];
	return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k) {
	int originalSize = a.size();
	if (a.size() < b.size() + k)
		a.resize(b.size() + k);
	a.push_back(0);

	for (int i = originalSize; i < a.size(); i++)
		a[i] = 0;
	
	for (int i = 0; i < b.size(); i++)
		a[i + k] += b[i];
}

void subFrom(vector<int>& a, const vector<int>& b) {
	for (int i = 0; i < b.size(); i++)
		a[i] -= b[i];
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	if (an < bn)
		return karatsuba(b, a);

	if (an == 0 or bn == 0)
		return vector<int>();

	if (an <= 50)
		return multiply(a, b);

	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);

	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);

	return ret;
}

int hugs(const string& members, const string& fans) {
	int n = members.size(), m = fans.size();

	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++)
		a[i] = (members[i] == 'M');
	for (int i = 0; i < m; i++)
		b[m - i - 1] = (fans[i] == 'M');

	vector<int> c = karatsuba(a, b);
	int allHugs = 0;

	for (int i = n - 1; i < m; i++)
		if (c[i] == 0)
			allHugs++;

	return allHugs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
	string a, b;
	for (cin >> c; c--;) {
		cin >> a;
		cin >> b;
		cout << hugs(a, b) << '\n';
	}
}
