/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        int i=1;
        while(head->next->next != NULL){
            if((head->next->val>head->val)
            &&(head->next->val>head->next->next->val)){
                ans.push_back(i);
            }
            if((head->next->val<head->val)
            &&(head->next->val<head->next->next->val)){
                ans.push_back(i);
            }
            head=head->next;
            i++;

        }
        vector<int> res;
        if(ans.size()<2){
            res.push_back(-1);
            res.push_back(-1);
        }
        else{
            int n=ans.size();
            int minVal=INT_MAX;
            for(int i=1;i<n;i++){
                minVal=min(minVal,ans[i]-ans[i-1]);
            }
            res.push_back(minVal);
            res.push_back(ans[n-1]-ans[0]);
        }

        return res;

    }
};