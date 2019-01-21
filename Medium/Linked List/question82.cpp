class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        
        auto front = head;
        auto cur = head->next;
        auto prev = head;
        
        while(cur){
            if (cur->val == prev->val) {
                prev->next = cur->next;
                while(cur and cur->val == prev->val) {
                    prev->next = cur->next;
                    cur = cur->next;
                }
                if (cur){
                    prev->val = cur->val;
                    prev->next = cur->next;
                    cur = cur->next;
                } else {
                    if (front->val == prev->val)
                        return NULL;
                    auto tmp = front;
                    for (;;) {
                        if(tmp->next->val == prev->val){
                            tmp->next = NULL;
                            return front;
                        }
                        tmp = tmp->next;
                    }
                }
            } else {
                cur = cur->next;
                prev = prev->next;
            }
        }
        return front;
    }
};