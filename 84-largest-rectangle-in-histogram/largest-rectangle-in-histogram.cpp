class Solution {
public:
    vector<int> nextSmaller(vector<int>& heights,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmaller(vector<int>& heights,int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int  n=heights.size();

        vector<int> next(n);
        next=nextSmaller(heights,n);

        vector<int> prev(n);
        prev=prevSmaller(heights,n);

        int area=INT_MIN;

        for(int i=0;i<n;i++){
            if(next[i]==-1){
                next[i]=n;
            }
            
            int breadth=next[i]-prev[i]-1;
            int length=heights[i];

            int temp_area=length*breadth;
            area=max(area,temp_area);
        }

        return area;
    }
};