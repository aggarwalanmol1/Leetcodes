class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
        vector<int> newParent(n, -1);
        vector<int> last(26, -1);
        function<void(int)> dfs1 = [&](int node) {
            int c = s[node] - 'a';
            int previous = last[c];
            newParent[node] = (previous == -1) ? parent[node] : previous;
            last[c] = node;
            for (int child : children[node]) {
                dfs1(child);
            }
            last[c] = previous;
        };
        dfs1(0);
        vector<vector<int>> modified(n);
        for (int i = 1; i < n; i++) {
            modified[newParent[i]].push_back(i);
        }
        vector<int> ans(n, 1);
        function<void(int)> dfs2 = [&](int node) {
            for (int child : modified[node]) {
                dfs2(child);
                ans[node] += ans[child];
            }
        };
        dfs2(0);
        return ans;
    }
};