class Solution {
public:
    pair<ListNode *,ListNode *> reverse(ListNode* lower, ListNode* head, ListNode * upper) {
        auto cur = head;
        auto next = cur->next;
        auto prev = upper;
        while (next != upper) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        if (lower)
            lower->next = cur;
        return make_pair(cur, head);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * front = nullptr;
        ListNode * lower = nullptr;
        bool noflip = true;
        while (true) {
            auto start = head;
            int i;
            for (i = 0; i < k; i++) {
                if (!head) {
                    if (noflip) return start;
                    break;
                }
                head = head->next;
            }
            if((k-i) and !head) 
                break;
            auto p = reverse(lower, start, head);
            noflip = false;
            if (!front)
                front = p.first;
            lower = p.second;
            head = lower->next;
        }
        return front;
    }
};