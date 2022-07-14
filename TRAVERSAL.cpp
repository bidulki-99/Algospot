#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> pre, in;

vector<int> slice2(const vector<int>& v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostorder(const vector<int>& pre, const vector<int>& in) {
    const int n = pre.size();

    if (n == 0)
        return;

    const int root = pre[0];
    const int l = find(in.begin(), in.end(), root) - in.begin();
    const int r = n - 1 - l;

    printPostorder(slice2(pre, 1, l + 1), slice2(in, 0, l));
    printPostorder(slice2(pre, l + 1, n), slice2(in, l + 1, n));
    cout << root << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
    for (cin >> c; c--;) {
        cin >> n;

        pre.clear();
        in.clear();

        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            pre.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
            cin >> temp;
            in.push_back(temp);
        }

        printPostorder(pre, in);
        cout << '\n';
    }
}
