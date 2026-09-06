class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> set;
        unordered_set<string> words;

        for(auto it : wordList) words.insert(it);

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
                for(int j = 0; j < beginWord.size(); j++) {
                    for(int k = 0; k < 26; k++) {
                        string a = front;
                        a[j] = 'a' + k;
                        if(words.find(a) != words.end()) {
                            if(a == endWord) return ans;
                            if(set.find(a) == set.end()) {
                                set.insert(a);
                                q.push(a);
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};