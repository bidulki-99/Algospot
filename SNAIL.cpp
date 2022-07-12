#include <bits/stdc++.h>
using namespace std;

int n, m;
double cache[1000][2001];

double climb(int days, int climbed) {
    if (days == m)
        return climbed >= n ? 1 : 0;

    double& ret = cache[days][climbed];
    if (ret != -1)
        return ret;

    return ret = 0.25 * climb(days + 1, climbed + 1) + 0.75 * climb(days + 1, climbed + 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
    for (cin >> c; c--;) {
        for (int i = 0; i < 1000; i++)
            for (int j = 0; j < 2001; j++)
                cache[i][j] = -1;

        cin >> n >> m;
        
        cout.precision(11);
        cout << climb(0, 0) << '\n';
    }
}
