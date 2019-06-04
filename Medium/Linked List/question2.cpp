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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry{}, cur{};
        ListNode* root = new ListNode(-1);
        auto tmp = root;
        while(l1 || l2 || carry) {
            if (l1)
            { cur += l1->val; l1 = l1->next;}
            if (l2)
            { cur += l2->val; l2 = l2->next; }
            
            if (carry) cur += carry;
            
            carry = (cur >= 10) ? 1 : 0;
            cur %= 10;
            tmp->next = new ListNode(cur);
            tmp = tmp->next;
            cur = 0;
        }
        return root->next;
        
    }
};

auto fast_io =[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();