class State {
    vector<State> getAdjacent() const;
    bool operator < (const State& rhs) const;
    bool operator == (const State& rhs) const;
};
int best;

void dfs(State here, const State& finish, int steps) {
    if (steps >= best) // if (steps + here.estimate())
        return;

    if (here == finish) {
        best = steps;
        return;
    }

    vector<State> adjacent = here.getAdjacent();
    for (int i = 0; i < adjacent.size(); i++)
        dfs(adjacent[i], finish, steps + 1);
}

int ids(State start, State finish, int growthStep) {
    for (int limit = 4; ; limit += growthStep) {
        best = limit + 1;
        dfs(start, finish, 0);

        if (best <= limit)
            return best;
    }

    return -1;
}
