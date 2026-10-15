class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        vector<string> route;
        dfs("JFK", graph, route);
        reverse(route.begin(), route.end());
        return route;
    }
private:
    void dfs(string airport,
             unordered_map<string, multiset<string>>& graph,
             vector<string>& route) {
        while (!graph[airport].empty()) {
            string next = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(next, graph, route);
        }
        route.push_back(airport);
    }
};