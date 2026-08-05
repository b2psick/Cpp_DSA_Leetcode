class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_set<int> set;
        vector<vector<int>> edges(n);
        vector<int> vis(n);
        queue<int> q;

        for(int i = 0; i < invocations.size(); i++) {
            edges[invocations[i][0]].push_back(invocations[i][1]);
        }

        q.push(k);
        set.insert(k);
        vis[k] = 1;

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            set.insert(front);
            for(int i = 0; i < edges[front].size(); i++) {
                if(!vis[edges[front][i]]) {
                    q.push(edges[front][i]);
                    vis[edges[front][i]] = 1;
                }
            }
        }

        bool canRemove = true;
        
        for(int i = 0; i < vis.size(); i++) vis[i] = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i] && set.find(i) == set.end()) {
                q.push(i);
            }
            while(!q.empty()) {
                int front = q.front();
                q.pop();
                for(int i = 0; i < edges[front].size(); i++) {
                    if(!vis[edges[front][i]] && set.find(edges[front][i]) == set.end()) {
                        q.push(edges[front][i]);
                        vis[edges[front][i]] = 1;
                    }else if(set.find(edges[front][i]) != set.end()) {
                        canRemove = false;
                        break;
                    }
                }
                if(!canRemove) break;
            }
            if(!canRemove) break;
        }

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(!canRemove) ans.push_back(i);
            else if(set.find(i) == set.end()) ans.push_back(i); 
        }

        return ans;

    }
};