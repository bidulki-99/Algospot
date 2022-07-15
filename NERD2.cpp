#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> coords;

bool isDominated(int x, int y) {
    map<int, int>::iterator it = coords.lower_bound(x);

    if (it == coords.end())
        return false;

    return y < it->second;
}

void removeDomianated(int x, int y) {
    map<int, int>::iterator it = coords.lower_bound(x);

    if (it == coords.begin())
        return;

    --it;
    while (true) {
        if (it->second > y)
            break;

        if (it == coords.begin()) {
            coords.erase(it);
            break;
        }

        else {
            map<int, int>::iterator jt = it;
            --jt;
            coords.erase(it);
            it = jt;
        }
    }
}

int registered(int x, int y) {
    if (isDominated(x, y))
        return coords.size();

    removeDomianated(x, y);
    coords[x] = y;

    return coords.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
    for (cin >> c; c--;) {
        cin >> n;

        coords.clear();

        int x, y;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            ans += registered(x, y);
        }

        cout << ans << '\n';
    }
}
