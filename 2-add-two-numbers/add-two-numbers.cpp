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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;

        while(l1!=NULL || l2!=NULL || carry !=0){
            int digit1=(l1!=NULL)?l1->val:0;
            int digit2=(l2!=NULL)?l2->val:0;

            int sum=digit1+digit2+carry;
            carry=sum/10;

            ListNode* curr=new ListNode(sum%10);
            tail->next=curr;
            tail=curr;

           l1 = (l1 != nullptr) ? l1->next : nullptr;
           l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        return dummy->next;
    }
};