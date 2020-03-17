/*���ȸ��ڵ��Լ���������������������������������������������ͬ
��������������������������������ͬ���ɣ����õݹ�*/

bool isSymmetrical(TreeNode* pRoot) {
    return isSymmetricalCore(pRoot, pRoot);
}

bool isSymmetricalCore(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    if (root1->val != root2->val)
        return false;
    return isSymmetricalCore(root1->left, root2->right) &&
        isSymmetricalCore(root1->right, root2->left);
}
