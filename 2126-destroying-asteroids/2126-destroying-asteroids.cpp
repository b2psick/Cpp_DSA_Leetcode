class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long ok=mass;
        for(int i=0;i<asteroids.size();i++){
            if(ok<asteroids[i]) return false;
            ok+=asteroids[i];
        }
        return true;
    }
};