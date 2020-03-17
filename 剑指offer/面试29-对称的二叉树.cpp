/*首先根节点以及其左右子树，左子树的左子树和右子树的右子树相同
左子树的右子树和右子树的左子树相同即可，采用递归*/

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
