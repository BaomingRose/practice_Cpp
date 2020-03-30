/*����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�*/

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
        
        //������������ҳ����ڵ�����λ��
        auto pos = find(in.begin(), in.end(), value);
        //���û�ҵ����򷵻�NULL
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
