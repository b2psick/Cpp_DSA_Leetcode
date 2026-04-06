class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        struct hash_pair {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
        };
        int a=1;
        int x=0;
        int y=0;
        int ans=0;
        unordered_set<pair<int,int>,hash_pair> set;
        for(auto it:obstacles) set.insert({it[0],it[1]});
        int prevx=0;
        int prevy=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                a--;
                if(a==4||a==-4) a=0;
            }else if(commands[i]==-2){
                a++;
                if(a==4||a==-4) a=0;
            }else{
                for(int j=0;j<commands[i];j++){
                    prevx=x;
                    prevy=y;
                    if(a==1||a==-3){
                        y++;
                    }else if(a==0){
                        x++;
                    }else if(a==2||a==-2){
                        x--;
                    }else{
                        y--;
                    }
                    if(set.find({x,y})!=set.end()){
                        x=prevx;
                        y=prevy;
                        break;
                    }
                    ans=max(ans,x*x+y*y);
                }
            }
        }
        return ans;
    }
};