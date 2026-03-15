class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans="";
        path+='/';
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(ans==".."&&!st.empty()) st.pop();
                else if(ans!=""&&ans!=".."&&ans!=".") st.push(ans);
                ans="";
            }else{
                ans+=path[i];
            }
        }
        stack<string> st1;
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        while(!st1.empty()){
            ans+='/';
            ans+=st1.top();
            st1.pop();
        }
        if(ans=="") ans="/";
        return ans;
    }
};