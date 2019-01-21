class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head or !head->next or !head->next->next)
            return head;
        
        auto fodd = head;
        auto odd = head;
        auto feven = head->next;
        auto even = feven;
        
        while(odd and even and odd->next and even->next) {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        
        odd->next = feven;
        return fodd;
        
    }
};