class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        vector<char> ans;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(ans.size());
            }
            else if(s[i]==')'){
                int ind=st.top();
                st.pop();
                reverse(ans.begin()+ind,ans.end());
            }
            else{
                ans.push_back(s[i]);
            }
        }

        return string(ans.begin(),ans.end());

    }
};