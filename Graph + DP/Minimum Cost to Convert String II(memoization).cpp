class Solution {
public:
    static constexpr long long INF = LLONG_MAX;

    // Dijkstra to compute shortest paths from src
    void dijkstra(int src, vector<vector<pair<int,int>>>& adj,
                  vector<vector<long long>>& dist) {

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<>> pq;

        dist[src][src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[src][u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[src][v] > d + w) {
                    dist[src][v] = d + w;
                    pq.push({dist[src][v], v});
                }
            }
        }
    }

    // Top-down memoization
    long long solve(int i, int n, string &source, string &target,
                    unordered_map<string,int> &id,
                    vector<vector<long long>> &cheapest_cost,
                    vector<long long> &memo,
                    unordered_set<int> &lens) {

        if (i == n) return 0;
        if (memo[i] != -1) return memo[i];

        long long res = INF;

        // Case 1: no operation
        if (source[i] == target[i]) {
            res = solve(i + 1, n, source, target, id, cheapest_cost, memo, lens);
        }

        // Case 2: substring conversions (only valid lengths)
        for (int len : lens) {
            int j = i + len - 1;
            if (j >= n) continue;

            string from = source.substr(i, len);
            string to   = target.substr(i, len);

            if (!id.count(from) || !id.count(to)) continue;

            int u = id[from];
            int v = id[to];

            long long c = cheapest_cost[u][v];
            if (c == INF) continue;

            long long temp = solve(j + 1, n, source, target, id, cheapest_cost, memo, lens);
            if (temp != INF) res = min(res, c + temp);
        }

        return memo[i] = res;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        // ---- Map strings to ids ----
        unordered_map<string,int> id;
        int idx = 0;
        auto getId = [&](const string &s) {
            if (!id.count(s)) id[s] = idx++;
            return id[s];
        };

        for (int i = 0; i < original.size(); i++) {
            getId(original[i]);
            getId(changed[i]);
        }

        int N = idx;

        // ---- Build graph ----
        vector<vector<pair<int,int>>> adj(N);
        for (int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            adj[u].push_back({v, cost[i]});
        }

        // ---- All-pairs shortest paths ----
        vector<vector<long long>> cheapest_cost(N, vector<long long>(N, INF));
        for (int i = 0; i < N; i++) {
            dijkstra(i, adj, cheapest_cost);
        }

        // ---- Precompute valid substring lengths ----
        unordered_set<int> lens;
        for (auto &s : original) lens.insert(s.size());

        // ---- Memoization DP ----
        int n = source.size();
        vector<long long> memo(n, -1);

        long long ans = solve(0, n, source, target, id, cheapest_cost, memo, lens);
        return ans == INF ? -1 : ans;
    }
};
