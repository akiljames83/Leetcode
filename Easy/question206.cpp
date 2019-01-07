// Recursive Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        stack<int> past;
        while(head->next){
            past.push(head->val);
            head = head->next;
        }
        ListNode* front = head;
        while(!past.empty()){
            head->next = new ListNode(past.top());
            past.pop();
            head = head->next;
        }
        return front;
        
    }
};