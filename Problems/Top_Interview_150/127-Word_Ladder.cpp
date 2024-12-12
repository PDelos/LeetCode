class Solution {
private:
    string letters = "abcdefghijklmnopqrstuvwxyz";
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        unordered_set<string>wordSet(wordList.begin(), wordList.end());
        unordered_map<string, int>dist;

        dist[beginWord] = 1;
        q.push(beginWord);
        while(!q.empty()){
            string word = q.front(); q.pop();
            for(int i = 0; i < beginWord.size(); i++){
                for(char let : letters){
                    string new_word = word; new_word[i] = let;

                    if(dist[new_word]) continue;
                    if(!wordSet.count(new_word)) continue;
                    dist[new_word] = dist[word]+1;
                    q.push(new_word);

                }
            }
        }

        return dist[endWord];
    }
};
