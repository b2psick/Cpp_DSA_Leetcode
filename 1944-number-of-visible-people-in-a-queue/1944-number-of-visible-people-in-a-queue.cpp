class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        vector<int> ok(heights.size());
        for(int i=heights.size()-1;i>=0;i--){
            bool flag=false;
            while(st.size()>0){
                if(!flag){
                    if(heights[st.top()]>heights[i]){
                        ok[i]++;
                        break;
                    }else{
                        ok[i]=st.top()-i;
                        flag=true;
                        st.pop();
                    }
                }else{
                    if(heights[st.top()]>heights[i]){
                        ok[i]++;
                        break;
                    }
                    else{
                        ok[i]++;
                        st.pop();
                    }
                }
            }
            st.push(i);
        }
        return ok;
    }
};