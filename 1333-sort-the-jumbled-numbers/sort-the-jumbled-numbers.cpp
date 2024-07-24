class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;
        vector<pair<int,int>> storePairs;
        int i=0;
        for(int num: nums){
            string s= to_string(num);
            string formed="";
            for(int i=0;i<s.length();i++){
                formed+=(to_string(mapping[s[i]-'0']));
            }
            int val= stoi(formed);
            storePairs.push_back({val,i});
            i++;
        }

        sort(storePairs.begin(),storePairs.end());
        for(auto pair:storePairs){
            ans.push_back(nums[pair.second]);
        }
        return ans;
    }
};