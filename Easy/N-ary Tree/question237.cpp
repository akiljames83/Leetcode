class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node->next){
            if (node->next->next){
                node->val = node->next->val;
                node->next = node->next->next;
                return;
            } else {
                node->val = node->next->val;
                node->next = NULL;
                return;
            }
        }
    }
};