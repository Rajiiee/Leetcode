class Solution {
public:
    int minimumPushes(string word) {
        int freq[26]={0};
        for(char c: word){
            freq[c-'a']++;
        }
        sort(freq,freq+26,greater<int>());

        int count=0,cost=1;
        int totalCost=0;

        for(int i=0;i<26 && freq[i]!=0;i++){
            count++;
            if(count>8){
                count=count%8;
                cost++;
            }
            totalCost+=(freq[i]*cost);
        }

        return totalCost;
    }
};