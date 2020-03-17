/*找到他们的特点：公共节点后面的结点完全相同，个数相同，可以将所有结点分别压入两个栈，然后分别比较他们的栈顶，依次出栈*/
/*先找到较长的链表，然后长链表走到比短链表多出来的部分，然后两个链表一起走下去，找到相同的为止*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == nullptr || pHead2 == nullptr)
        return nullptr;
    
    int lengthOf1 = lengthOfList(pHead1);
    int lengthOf2 = lengthOfList(pHead2);
    int lenMore = abs(lengthOf1 - lengthOf2);
    
    ListNode* cur1;
    ListNode* cur2;
    if (lengthOf1 - lengthOf2 > 0) {
        cur1 = pHead1;
        cur2 = pHead2;
    } else {
        cur1 = pHead2;
        cur2 = pHead1;
    }
    
    for (int i = 0; i < lenMore; ++i) {
        cur1 = cur1->next;
    }
    
    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1 == cur2)
            return cur1;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return nullptr;
}

int lengthOfList(ListNode* pHead) {
    ListNode* cur = pHead;
    int res = 0;
    while (cur != nullptr) {
        ++res;
        cur = cur->next;
    }
    return res;
}


//用两个栈的方法
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == nullptr || pHead2 == nullptr)
        return nullptr;
    stack<ListNode*> st1;
    stack<ListNode*> st2;
    for (ListNode* cur = pHead1; cur != nullptr; cur = cur->next) {
        st1.push(cur);
    }
    for (ListNode* cur = pHead2; cur != nullptr; cur = cur->next) {
        st2.push(cur);
    }
    ListNode* res = nullptr;
    while (!st1.empty() && !st2.empty() && st1.top() == st2.top()) {
        res = st1.top();
        st1.pop();
        st2.pop();
    }
    return res;
}


