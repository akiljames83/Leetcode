class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        
        // 1. Find the length of the list O(N)
        int len{0};
        auto cur = head;
        while(cur) 
            cur = cur->next + 0*(len++);
        
        // 2. Determine if the sequence has an odd length
        bool odd{len%2 == 1};
        
        // 3. Determine the *pos* of the midpoint
        len>>=1;
        
        // 4. Setup for reverse
        int count{1};
        cur = head;
        ListNode* prev = NULL;
        auto next = cur->next;
        auto forward = prev;
        
        // 5. Reverse until the midpoint;
        while(cur) {
            cur->next = prev;
            if (count < len) {
                prev = cur;
                cur = next;
                count++;
            }
            else {
                forward = (odd) ? next->next : next;
                break;
            }
            next = next->next; 
        }
        
        // 6. Check if the flipped are equal
        while(forward) {
            if (forward->val != cur->val)
                return false;
            cur = cur->next;
            forward = forward->next;
        }
        
        return true;
            
    }
};