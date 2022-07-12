#include <bits/stdc++.h>
using namespace std;

int n, d, p, t, q[51];
double cache[51][101];
int connected[51][51], deg[51];

double search(int here, int days, int dest) {
    if (days == d)
        return (here == dest ? 1.0 : 0.0);

    double& ret = cache[here][days];
    if (ret > -0.5)
        return ret;

    ret = 0.0;
    for (int there = 0; there < n; there++)
        if (connected[here][there])
            ret += search(there, days + 1, dest) / deg[here];

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
    for (cin >> c; c--;) {
        cin >> n >> d >> p;

        memset(deg, 0, sizeof(deg));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> connected[i][j];
                deg[i] += (connected[i][j] ? 1 : 0);
            }

        cin >> t;
        for (int i = 0; i < t; i++)
            cin >> q[i];

        cout.precision(8);

        for (int i = 0; i < t; i++) {
            for (int j = 0; j < n; j++)
                for (int k = 0; k < d; k++)
                    cache[j][k] = -1;

            cout << search(p, 0, q[i]) << ' ';
        }

        cout << '\n';
    }
}
