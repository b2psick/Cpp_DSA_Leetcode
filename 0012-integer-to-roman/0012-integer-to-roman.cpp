class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>> roman;
        roman.push_back({"M", 1000});
        roman.push_back({"CM", 900});
        roman.push_back({"D", 500});
        roman.push_back({"CD", 400});
        roman.push_back({"C", 100});
        roman.push_back({"XC", 90});
        roman.push_back({"L", 50});
        roman.push_back({"XL", 40});
        roman.push_back({"X", 10});
        roman.push_back({"IX", 9});
        roman.push_back({"V", 5});
        roman.push_back({"IV", 4});
        roman.push_back({"I", 1});
        string ans="";
        for(int i=0;i<roman.size();i++){
            while(roman[i].second<=num){
                ans+=roman[i].first;
                num-=roman[i].second;
            }
        }
        return ans;
    }
};