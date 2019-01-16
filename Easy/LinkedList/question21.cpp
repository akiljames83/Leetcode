class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        ListNode * front = l1;
        while(l2) {
            if (l2->val <= l1->val) {
                ListNode * n = new ListNode(l1->val);
                l1->val = l2->val;
                n->next = l1->next;
                l1->next = n;
                l2 = l2->next;
            } else {
                if (!l1->next) {
                    l1->next = l2;
                    break;
                }
                l1 = l1->next;
            }      
        }
        return front;
    }
};