#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    vector<TreeNode*> children;
};

int n, x[100], y[100], radius[100];

int sqr(int x) {
    return x * x;
}

int sqrdist(int a, int b) {
    return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

bool encloses(int a, int b) {
    return radius[a] > radius[b] and sqrdist(a, b) < sqr(radius[a] - radius[b]);
}

bool isChild(int parent, int child) {
    if (!encloses(parent, child))
        return false;

    for (int i = 0; i < n; i++)
        if (i != parent and i != child and encloses(parent, i) and encloses(i, child))
            return false;

    return true;
}

TreeNode* getTree(int root) {
    TreeNode* ret = new TreeNode();

    for (int ch = 0; ch < n; ch++)
        if (isChild(root, ch))
            ret->children.push_back(getTree(ch));

    return ret;
}

int longest;

int height(TreeNode* root) {
    vector<int> heights;

    for (int i = 0; i < root->children.size(); i++)
        heights.push_back(height(root->children[i]));

    if (heights.empty())
        return 0;

    sort(heights.begin(), heights.end());

    if (heights.size() >= 2)
        longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);

    return heights.back() + 1;
}

int solve(TreeNode* root) {
    longest = 0;
    int h = height(root);
    return max(longest, h);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
    for (cin >> c; c--;) {
        cin >> n;

        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        memset(radius, 0, sizeof(radius));

        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i] >> radius[i];

        cout << solve(getTree(0)) << '\n';
    }
}
