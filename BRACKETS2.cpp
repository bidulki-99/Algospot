#include <bits/stdc++.h>
using namespace std;

bool wellMatched(const string& formula) {
    const string opening("({[");
    const string closing(")}]");

    stack<char> openStack;
    for (auto i : formula) {
        if (opening.find(i) != -1)
            openStack.push(i);
        
        else {
            if (openStack.empty())
                return false;
            if (opening.find(openStack.top()) != closing.find(i))
                return false;
            openStack.pop();
        }
    }

    return openStack.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
    for (cin >> c; c--;) {
        string s;
        cin >> s;

        cout << (wellMatched(s) ? "YES\n" : "NO\n");
    }
}
