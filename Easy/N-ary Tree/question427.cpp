class Solution {
public:
    Node* traverse(vector<vector<int>>& grid, int top_left, int top_right,int row, Node* node) {
        int distance = (top_right - top_left)/2;
        bool seg = grid[row][top_left];
        bool leaf = true;
        for (int h = row; h < row+2*distance; h++){
            for (int w = top_left; w < top_right; w++){
                if (grid[h][w] != seg){
                    leaf = false;
                    break;
                }
            }
        }
        if (leaf){
            return new Node(seg, true, nullptr, nullptr, nullptr, nullptr);
        } else{
            node->topLeft = traverse(grid, top_left, top_left + distance, row, new Node());
            node->topRight = traverse(grid, top_left+distance, top_right, row, new Node());
            node->bottomLeft = traverse(grid, top_left, top_left + distance, row+distance, new Node());
            node->bottomRight = traverse(grid, top_left+distance, top_right, row + distance, new Node());
            node->val = true;
            node->isLeaf = false;
            return node;
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        Node * root  = traverse(grid, 0, grid[0].size(), 0, new Node());
        return root;
        
    }
};