//������������� 

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

//��չ���ֲ��ӡ
//��ʹ������������һ���ǵ�ǰ����Ҫ��ӡ�Ľ�������һ������һ��Ҫ��ӡ�ĸ��� 
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
