/*����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)*/

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

