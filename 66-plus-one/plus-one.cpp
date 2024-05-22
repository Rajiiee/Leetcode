class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry=1,n=digits.size()-1;
        for(int i=n;i>=0;i--){
            digits[i]=digits[i]+carry;
            carry--;
            if(digits[i]>=10){
                carry=digits[i]/10;
                digits[i]=digits[i]%10;
            }
            if(carry==0){
                break;
            }
        }
        if(carry!=0){
            ans.push_back(carry);
        }
        for(int i=0;i<=n;i++){
            ans.push_back(digits[i]);
        }

        return ans;
    }
};