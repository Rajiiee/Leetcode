class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>sorted_heights=heights;
        sort(sorted_heights.begin(),sorted_heights.end());

        int n=heights.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(heights[i]!=sorted_heights[i]){
                ans++;
            }
        }

        return ans;
    }
};