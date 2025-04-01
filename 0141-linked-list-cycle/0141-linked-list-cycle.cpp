/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head)
     {
        ListNode*cur=head;
        ListNode*negst=head;
        while(negst!=NULL && negst->next!=NULL)
        {
            negst=negst->next->next;
            cur=cur->next;
    if(cur==negst)
    return true;
        }
        return false;
    }
};