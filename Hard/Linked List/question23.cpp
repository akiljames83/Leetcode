// Better with priority queue
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size())
            return nullptr;
        priority_queue<int> q;
        for (int i = 0; i < lists.size(); i++) {
            auto tmp = lists[i];
            while(tmp) {
                q.push(tmp->val);
                tmp = tmp->next;
            }
        }
        ListNode* front = NULL;
        while (!q.empty()) {
            auto tmp = new ListNode(q.top());
            tmp->next = front;
            front = tmp;
            q.pop();
        }
        return front;
    }
};

// Bad Solution
class Solution {
public:
    ListNode * merge(ListNode * a, ListNode* b) {
        if (!a) return b;
        if (!b) return a;
        auto preva = a;
        auto p = a;
        while (a and b) {
            if (a->val < b->val) {
                if (a->next){
                    if (b->val < a->next->val) {
                        auto tmp = new ListNode(b->val);
                        tmp->next = a->next;
                        a->next = tmp;
                        b = b->next;
                        p = a;
                        a = a->next;
                    } else {
                        p = a;
                        a = a->next;
                    }
                } else {
                    a->next = b;
                    break;
                }
            } else {
                // a is greater
                if (b->next) {
                    if (a->val < b->next->val) {
                        auto tmp = new ListNode(a->val);
                        tmp->next = a->next;
                        a->val = b->val;
                        a->next = tmp;
                        p = a->next;
                        a = a->next->next;
                        b = b->next;
                    } else {
                        auto tmp = new ListNode(a->val);
                        tmp->next = a->next;
                        a->val = b->val;
                        p = a;
                        a->next = tmp;
                        b = b->next;
                        a = a->next;
                    }
                } else {
                    auto tmp = new ListNode(a->val);
                    tmp->next = a->next;
                    a->next = tmp;
                    a->val = b->val;
                    break;
                }
            }
        }
        if (!a) {
            p->next = b;
        }
        return preva;
    }
    void print(ListNode * front) {
        auto tmp = front;
        while(tmp) {
            cout << tmp->val << "->";
            tmp = tmp->next;
        }
        cout << endl;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size())
            return nullptr;
        auto front = lists[0];
        for (int i = 1; i < lists.size(); i++)
            front = merge(front, lists[i]);
        return front;
    }
};