// Problem Link
// https://leetcode.com/problems/middle-of-the-linked-list/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        count=count/2 +1;
        while(--count)
        {
            head=head->next;
        }
        return head;
    }
};
