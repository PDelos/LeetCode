class Solution {
private:
    unordered_map<string, unordered_map<string, double>> adjList;
    unordered_map<string, bool>visited;
    vector<double>ans;

    void dfs(string node, string end, double &ans, double temp){
        if(visited[node] == true) return;
        visited[node] = true;

        if(node == end){
            ans = temp;
            return;
        }

        for(auto q: adjList[node]){
            dfs(q.first, end, ans, temp*q.second);
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(size_t i = 0; i < equations.size(); i++){
            string a = equations[i][0], b=equations[i][1];

            adjList[a][b] = values[i];
            adjList[b][a] = 1.0 / values[i];
        }

        for(auto query:queries){
            string str = query[0];
            string end = query[1];
            if(adjList.find(str) == adjList.end() || adjList.find(end) == adjList.end()){
                ans.push_back(-1.0);
            }
            else{
                visited.clear();
                double calc = -1.0, temp=1.0;
                dfs(str, end, calc, temp);
                ans.push_back(calc);
            }
        }

        return ans;
    }
};
