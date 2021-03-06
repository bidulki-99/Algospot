#include <bits/stdc++.h>
using namespace std;

int n;
map<vector<int>, int> toSort;
vector<int> perm;

void precalc(int n) {
    vector<int> perm(n);

    for (int i = 0; i < n; i++)
        perm[i] = i;

    queue<vector<int>> q;
    q.push(perm);
    toSort[perm] = 0;

    while (!q.empty()) {
        vector<int> here = q.front();
        q.pop();
        int cost = toSort[here];

        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j <= n; j++) {
                reverse(here.begin() + i, here.begin() + j);

                if (toSort.count(here) == 0) {
                    toSort[here] = cost + 1;
                    q.push(here);
                }

                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
}

int solve(const vector<int>& perm) {
    int n = perm.size();
    vector<int> fixed(n);

    for (int i = 0; i < n; i++) {
        int smaller = 0;
        
        for (int j = 0; j < n; j++)
            if (perm[j] < perm[i])
                smaller++;

        fixed[i] = smaller;
    }
    
    return toSort[fixed];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 1; i <= 8; i++)
        precalc(i);

	int c;
    for (cin >> c; c--;) {
        cin >> n;

        perm.clear();
        perm.resize(n);
        for (int i = 0; i < n; i++)
            cin >> perm[i];

        cout << solve(perm) << '\n';
    }
}
