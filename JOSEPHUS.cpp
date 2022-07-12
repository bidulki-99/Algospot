#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
    for (cin >> c; c--;) {
        int n, k;
        cin >> n >> k;

        deque<int> q, temp;
        for (int i = 1; i <= n; i++)
            q.push_back(i);

        int count = 0;
        int remain = n;

        while (remain > 2) {
            if (count % k == 0) {
                remain--;
                q.pop_front();

                if (remain == 2)
                    break;
            }
            else {
                temp.push_back(q.front());
                q.pop_front();
            }

            count++;

            if (q.size() == 0) {
                for (int i : temp)
                    q.push_back(i);
                temp.clear();
            }
        }

        if (temp.size() == 2)
            if (temp[0] > temp[1])
                cout << temp[1] << ' ' << temp[0] << '\n';
            else
                cout << temp[0] << ' ' << temp[1] << '\n';

        else if (temp.size() == 1)
            if (temp[0] > q[0])
                cout << q[0] << ' ' << temp[0] << '\n';
            else
                cout << temp[0] << ' ' << q[0] << '\n';

        else
            if (q[0] > q[1])
                cout << q[1] << ' ' << q[0] << '\n';
            else
                cout << q[0] << ' ' << q[1] << '\n';
    }
}
