class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string, vector<string>> mp;
        unordered_set<string> set;

        for(int i = 0; i < wordList.size(); i++) {
            for(int j = i + 1; j < wordList.size(); j++) {
                int diff = 0;
                for(int k = 0; k < beginWord.length(); k++) {
                    if(wordList[i][k] != wordList[j][k]) {
                        diff++;
                    }
                    if(diff > 1) break;
                }
                if(diff == 1) {
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
            int beginDiff = 0;
            for(int j = 0; j < beginWord.length(); j++) {
                if(wordList[i][j] != beginWord[j]) beginDiff++;
            }
            if(beginDiff == 1) {
                mp[beginWord].push_back(wordList[i]);
                mp[wordList[i]].push_back(beginWord);
            }
        }

        queue<string> q;

        int ans = 1;

        q.push(beginWord);
        set.insert(beginWord);

        while(!q.empty()) {
            ans++;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                string front = q.front();
                q.pop();
                for(auto it : mp[front]) {
                    if(it == endWord) return ans;
                    if(set.find(it) == set.end()) {
                        set.insert(it);
                        q.push(it);
                    }
                }
            }
        }
        return 0;
    }
};