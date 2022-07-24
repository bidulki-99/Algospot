#include <bits/stdc++.h>
using namespace std;

double n;
int m;
double p;

double balance(double amount, int duration, double rates, double monthlyPayment) {
	double balance = amount;

	for (int i = 0; i < duration; i++) {
		balance *= (1.0 + (rates / 12.0) / 100.0);
		balance -= monthlyPayment;
	}

	return balance;
}

double payment(double amount, int duration, double rates) {
	double lo = 0, hi = amount * (1.0 + (rates / 12.0) / 100.0);
	
	for (int iter = 0; iter < 100; iter++) {
		double mid = (lo + hi) / 2.0;

		if (balance(amount, duration, rates, mid) <= 0)
			hi = mid;
		else
			lo = mid;
	}

	return hi;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int c;
	for (cin >> c; c--;) {
		cin >> n >> m >> p;

		cout << fixed;
		cout.precision(10);

		cout << payment(n, m, p) << '\n';
	}
}
