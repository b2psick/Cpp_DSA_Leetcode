class Solution {
public:
    bool checkStrings(string s1, string s2) {
        // string a="";
        // string b="";
        // string c="";
        // string d="";
        // for(int i=0;i<s1.length();i++){
        //     if(i%2==0){
        //         a+=s1[i];
        //         b+=s2[i];
        //     }else{
        //         c+=s1[i];
        //         d+=s2[i];
        //     }
        // }
        // sort(a.begin(),a.end());
        // sort(b.begin(),b.end());
        // sort(c.begin(),c.end());
        // sort(d.begin(),d.end());
        // return a==b&&c==d;

        //a little more optimal 
        
        int arr1[26];
        int arr2[26];
        for(int i=0;i<s1.length();i++){
            if(i%2==0){
                arr1[s1[i]-'a']++;
                arr1[s2[i]-'a']--;
            }else{
                arr2[s1[i]-'a']++;
                arr2[s2[i]-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            if(arr1[i]!=0||arr2[i]!=0) return false;
        }
        return true;
    }
};