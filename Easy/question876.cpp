// Question 876
// Slower inital solution O(n)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* cur{head};
        bool flip = true;
        while(cur->next){
            if (flip) head = head->next;
            flip = !flip;
            cur = cur->next;
        }
        return head;
    }
};


