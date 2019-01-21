class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        auto prev = head;
        auto ret = head;
        head = head->next;
        while(head){
            if (head->val == prev->val) {
                //cout << "hit" << endl;
                prev->next = head->next;
                head = head->next;
            } else {
                //cout << "else" << endl;
                prev = prev->next;
                head = head->next;
            }
        }
        return ret;
    }
};