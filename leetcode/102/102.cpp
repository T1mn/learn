// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

//  

// 示例 1：


// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[9,20],[15,7]]
// 示例 2：

// 输入：root = [1]
// 输出：[[1]]
// 示例 3：

// 输入：root = []
// 输出：[]

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        get(root, 0, res);
        return res;
    }
    void get(TreeNode* root, int i,vector<vector<int>> &res)
    {
        if (root == nullptr)
            return;
        if (res.size() > i)
            res[i].push_back(root->val);
        else{
            res.push_back(vector<int>(root->val));
        }
        get(root->left, i + 1, res);
        get(root->right, i + 1, res);
    }
};