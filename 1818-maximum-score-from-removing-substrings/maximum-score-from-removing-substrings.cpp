class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans=0;
        string one,two;
        int oneScore,twoScore;

        if(x>y){
            one="ab";
            oneScore=x;
            two="ba";
            twoScore=y;
        }else{
            one="ba";
            oneScore=y;
            two="ab";
            twoScore=x;
        }

        vector<char> st;
        for(char ch:s){
            if(!st.empty() && ch==one[1] && st.back()==one[0]){
                ans+=oneScore;
                st.pop_back();
            }else{
                st.push_back(ch);
            }
        }

        stack<char> newSt;
        for(char ch:st){
            if(!newSt.empty() && ch==two[1] && newSt.top()==two[0]){
                ans+=twoScore;
                newSt.pop();
            }else{
                newSt.push(ch);
            }
        }

        return ans;
    }
};