/*输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

void findPathCore(TreeNode* root, int& curSum, int expectNumber, vector<vector<int>>& vv, vector<int>& tmp); 

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }
    int curSum  = 0;
    vector<int> tmp;
    findPathCore(root, curSum, expectNumber, res, tmp);
    return res;
}

void findPathCore(TreeNode* root, int& curSum, int expectNumber, vector<vector<int>>& vv, vector<int>& tmp) {
    if (root == nullptr) {
        return;
    }
    bool isLeaf = (root->left == nullptr && root->right == nullptr);
    curSum += root->val;
    tmp.push_back(root->val);
    if (curSum == expectNumber && isLeaf) {
        vv.push_back(tmp);
    }
    
    if (root->left != nullptr)
        findPathCore(root->left, curSum, expectNumber, vv, tmp);
    if (root->right != nullptr)
        findPathCore(root->right, curSum, expectNumber, vv, tmp);
    
    curSum -= root->val;
    tmp.pop_back();        
}

