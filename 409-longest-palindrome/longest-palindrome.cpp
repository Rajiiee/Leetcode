class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        set<char> st;
        for(char c:s){
            if(st.find(c)!=st.end()){
                st.erase(c);
                ans+=2;
            }
            else{
                st.insert(c);
            }
        }

        if(!st.empty()){
            ans+=1;
        }

        return ans;
        
    }
};