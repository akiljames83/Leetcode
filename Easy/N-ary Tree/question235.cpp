class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!p || !q)
            return nullptr;
        if (p->val == q->val)
            return p;
        unordered_map<int,pair<int, TreeNode*>> map;
        TreeNode* findp = root;
        int count{0};
        while(findp and findp->val != p->val) {
            map[findp->val] = make_pair(count++, findp);
            if (findp->val > p->val) {
                findp = findp->left;
            } else {
                findp = findp->right;
            }
        }
        map[findp->val] = make_pair(count++, findp);
        TreeNode * findq = root;
        auto res = p;
        while(findq and findq->val != q->val) {
            if (map.find(findq->val) != map.end()) {
                res = map[findq->val].second;
                if (findq->val > q->val)
                    findq = findq->left;
                else
                    findq = findq->right;
            } else {
                break;
            }
        }
        if (map.find(findq->val) != map.end())
            return findq;
        return res;
    }
};