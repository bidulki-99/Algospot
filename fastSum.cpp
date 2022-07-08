int fastSum(int n) {
	if (n == 1)
		return 1;
	if (n % 2)
		return fastSum(n - 1) + n;
	return 2 * fastSum(n / 2) + (n / 2) * (n / 2);
}
