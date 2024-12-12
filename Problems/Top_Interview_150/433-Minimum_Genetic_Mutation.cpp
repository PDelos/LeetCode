class Solution {
private:
    vector<char> mutations = {'A', 'C', 'G', 'T'};

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene) return 0;

        unordered_set<string>bankSet(bank.begin(), bank.end());
        unordered_map<string, int>dist;
        queue<string>q;
        q.push(startGene);
        dist[startGene] = 1;


        while(!q.empty()){
            string gene = q.front(); q.pop();

            for(int i = 0; i < gene.size(); i++){
                for(char m : mutations){
                    string new_gene = gene;
                    new_gene[i] = m;

                    if(dist[new_gene]) continue;
                    if(!bankSet.count(new_gene)) continue;

                    dist[new_gene] = dist[gene]+1;
                    q.push(new_gene);
                }
            }
        }

        return dist[endGene]-1;
    }
};
