vector<vector<int>> adj;
vector<int> sccId;
vector<int> discovered;
stack<int> st;
int sccCounter, vectexCounter;

int scc(int here) {
    int ret = discovered[here] = vectexCounter++;
    st.push(here);

    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];

        if (discovered[there] == -1)
            ret = min(ret, scc(there));
        else if (sccId[there] == -1)
            ret = min(ret, discovered[there]);
    }

    if (ret == discovered[here]) {
        while (true) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if (t == here)
                break;
        }

        sccCounter++;
    }

    return ret;
}

vector<int> tarjanSCC() {
    sccId = discovered = vector<int>(adj.size(), -1);
    sccCounter = vectexCounter = 0;

    for (int i = 0; i < adj.size(); i++)
        if (discovered[i] == -1)
            scc(i);

    return sccId;
}
