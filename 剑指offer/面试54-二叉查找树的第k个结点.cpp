//����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬 ��5��3��7��2��4��6��8��    �У��������ֵ��С˳�����С����ֵΪ4��


//�������������k 

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (pRoot == nullptr || k <= 0)
            return nullptr;
        int curNum = 0;
        TreeNode* res = nullptr;
        Inorder(pRoot, res, k, curNum);
        return res;
    }
    
    void Inorder(TreeNode* pRoot, TreeNode*& res, int k, int& curNum) {
        if (pRoot == nullptr || curNum >= k) {
            return;
        }
        Inorder(pRoot->left, res, k, curNum);
        curNum++;
        if (curNum == k)
            res = pRoot;
        Inorder(pRoot->right, res, k, curNum);
    }

    
};
