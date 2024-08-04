class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod = 1e9+7;
        
        vector<int> totalSum;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                totalSum.push_back(sum);
            }
        }

        sort(totalSum.begin(),totalSum.end());
        long long ans=0;
        for(int i=left-1;i<right;i++){
            ans=(ans+totalSum[i])%mod ;
        }

        return ans;
    }
};