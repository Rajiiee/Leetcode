class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> remMap;
        int cumSum=0;

        remMap[0]=-1;

        for(int i=0;i<n;i++){
            cumSum+=nums[i];
            int rem= k==0? cumSum:cumSum%k;

            if(remMap.count(rem)){
                if(i-remMap[rem]>1){
                    return true;
                }
            }
            else{
                remMap[rem]=i;
            }
        }

        return false;
    }
};