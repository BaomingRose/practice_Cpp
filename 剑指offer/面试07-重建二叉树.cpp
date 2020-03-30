/*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        if(pre.size() == 0 || pre.size() != in.size()) {
            return nullptr;
        }
        
        int value = pre[0];
        TreeNode* root = new TreeNode(value);
        if(pre.size() == 1) {
            return root;
        }
        
        //在中序遍历中找出根节点所在位置
        auto pos = find(in.begin(), in.end(), value);
        //如果没找到，则返回NULL
        if(pos == in.end()) {
            return nullptr;
        }
        
        int leftSize = pos - in.begin();
        int rightSize = in.end() - pos - 1;
        root->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + 1 + leftSize), 
                                           vector<int>(in.begin(), in.begin() + leftSize));
        root->right = reConstructBinaryTree(vector<int>(pre.begin() + 1 + leftSize, pre.end()), 
                                            vector<int>(in.begin() + leftSize + 1, in.end()));
        return root;  
    }
};
