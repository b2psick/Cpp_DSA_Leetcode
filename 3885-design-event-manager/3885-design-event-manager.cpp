    class EventManager {
    public:
        unordered_map<int,int> mp;
        struct cmp{
            bool operator()(pair<int,int>& a,pair<int,int>& b) {
                if (a.second==b.second)
                    return a.first>b.first;
                return a.second<b.second;
            }
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        EventManager(vector<vector<int>>& events) {
            for(auto it:events){
                mp[it[0]]=it[1];
                pq.push({it[0],it[1]});
            }
        }
        
        void updatePriority(int eventId, int newPriority) {
            pq.push({eventId,newPriority});
            mp[eventId]=newPriority;
        }
        
        int pollHighest() {
            while(!pq.empty()&&mp[pq.top().first]!=pq.top().second){
                pq.pop();
            }
            if(pq.empty()) return -1;
            int a=pq.top().first;
            mp.erase(pq.top().first);
            pq.pop();
            return a;
        }
    };

    /**
    * Your EventManager object will be instantiated and called as such:
    * EventManager* obj = new EventManager(events);
    * obj->updatePriority(eventId,newPriority);
    * int param_2 = obj->pollHighest();
    */