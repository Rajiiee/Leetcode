class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_ind=0,t_ind=0;
        while(s_ind<s.length() && t_ind<t.length()){
            if(s[s_ind]==t[t_ind]){
                t_ind++;
            }
            s_ind++;
        }

        return t.length() - t_ind;
    }
};