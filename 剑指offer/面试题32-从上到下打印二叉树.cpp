//层序遍历二叉树 

vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> q;
    
    if (root == nullptr)
        return res;
    q.push(root);
    while (!q.empty()) {
        TreeNode* tmp = q.front();
        res.push_back(tmp->val);
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
        q.pop();
    }
    
    return res;
}

//拓展：分层打印
//多使用两个变量，一个是当前行需要打印的结点个数，一个是下一行要打印的个数 
void PrintFromTopToBottom(TreeNode* root) {
    queue<TreeNode*> q;
    
    if (root == nullptr)
        return res;
    q.push(root);
    
    int curToPrint = 1;
	int nextToPrint = 0; 
    
    while (!q.empty()) {
        TreeNode* tmp = q.front();
        
        cout << tmp->val << "\t";
        
        if (tmp->left) {
            q.push(tmp->left);
            ++nextToPrint;
        }
        if (tmp->right) {
            q.push(tmp->right);
            ++nextToPrint;
        }
        
        q.pop();
        --curToPrint;
        
        if (curToPrint == 0) {
        	cout << endl;
        	curToPrint = nextToPrint;
        	nextToPrint = 0;
		}
    }
}
