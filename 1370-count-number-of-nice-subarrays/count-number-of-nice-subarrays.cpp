class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
            nums[i] %= 2;
        }
        
        vector<int> prefixCount(nums.size() + 1);
        prefixCount[0] = 1;
        int s = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            s += nums[i];
            ans += (s >= k) ? prefixCount[s - k] : 0;
            prefixCount[s]++;
        }
        return ans;

    }
};