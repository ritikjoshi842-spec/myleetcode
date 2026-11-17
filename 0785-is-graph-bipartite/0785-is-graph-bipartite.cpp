class Solution {
public:
bool res = true;
void dfs(vector<vector<int>>& graph, vector<int> &color, int c, int n, int node){
    color[node] = c;
    for(int i = 0; i < graph[node].size(); i++){
        int neigh = graph[node][i];
        if(color[neigh]!=-1 and color[neigh]==color[node]){
            res = false;
        }
        else if(color[neigh]==-1){
            dfs(graph, color, 1-c, n, neigh);
        }
    }
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        int c = 0;
        for(int i = 0; i < n; i++){
            if(color[i]== -1){
                dfs(graph, color, c, n, i);
            }
        }
        return res;
    }
};