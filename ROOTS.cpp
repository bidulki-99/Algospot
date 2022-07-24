#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define REP(i, a, b) for (int i = a; i <= b; i++)

int n;
vector<double> poly;
const double L = 10;

vector<double> differentiate(const vector<double>& poly) {
	int n = poly.size() - 1;
	vector<double> ret;

	rep(i, 0, n)
		ret.push_back((n - i) * poly[i]);

	return ret;
}

vector<double> solveNaive(const vector<double>& poly) {
	int n = poly.size() - 1;
	vector<double> ret;

	switch (n) {
		case 1:
			ret.push_back(-poly[1] / poly[0]);
			break;
		case 2:
			double a = poly[0], b = poly[1], c = poly[2];
			ret.push_back((-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
			ret.push_back((-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
			break;
	}

	sort(ret.begin(), ret.end());

	return ret;
}

double evaluate(const vector<double>& poly, double x0) {
	int n = poly.size() - 1;
	double ret = 0;

	REP(i, 0, n)
		ret += pow(x0, n - i) * poly[i];

	return ret;
}

vector<double> solve(const vector<double>& poly) {
	int n = poly.size() - 1;

	if (n <= 2)
		return solveNaive(poly);

	vector<double> derivative = differentiate(poly);
	vector<double> sols = solve(derivative);

	sols.insert(sols.begin(), -L - 1);
	sols.insert(sols.end(), L + 1);
	vector<double> ret;

	rep(i, 0, sols.size() - 1) {
		double x1 = sols[i], x2 = sols[i + 1];
		double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);

		if (y1 * y2 > 0)
			continue;

		if (y1 > y2) {
			swap(y1, y2);
			swap(x1, x2);
		}

		rep(iter, 0, 100) {
			double mx = (x1 + x2) / 2;
			double my = evaluate(poly, mx);

			if (y1 * my > 0) {
				y1 = my;
				x1 = mx;
			}
			else {
				y2 = my;
				x2 = mx;
			}
		}

		ret.push_back((x1 + x2) / 2);
	}

	sort(ret.begin(), ret.end());

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	for (cin >> c; c--;) {
		poly.clear();

		cin >> n;

		double temp;
		REP(i, 0, n) {
			cin >> temp;
			poly.push_back(temp);
		}

		cout << fixed;
		cout.precision(12);

		vector<double> ans = solve(poly);
		for (auto i : ans)
			cout << i << ' ';
		cout << '\n';
	}
}
