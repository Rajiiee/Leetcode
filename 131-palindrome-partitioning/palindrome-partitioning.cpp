class Solution {
 private:
    bool isPalindrome(string& s) {
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            if (s.at(l) != s.at(r))
                return false;
            l++, r--;
        }
        return true;
    }
    void helper(string s, vector<string> step, vector<vector<string>>& res) {
        if (s == "" or s.length() == 0) {
            res.push_back(step);
            return;
        }
        for (int i = 1; i <= s.length(); i++) {
            string temp = s.substr(0, i);
            if (!isPalindrome(temp))
                continue;
            step.push_back(temp);
            helper(s.substr(i, s.length()), step, res);
            step.pop_back();
        }
        return;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        helper(s, {}, res);
        return res;
    }
};