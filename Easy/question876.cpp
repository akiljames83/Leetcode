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


// Faster Solution -> O(N)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* cur{head};
        int count{};
        while(cur->next and cur->next->next){
            head = head->next;
            cur = cur->next->next;
            count++;
        }
        if (cur->next and !cur->next->next) 
            return head->next;
        return head;
    }
};