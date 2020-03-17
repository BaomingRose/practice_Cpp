/*�ҵ����ǵ��ص㣺�����ڵ����Ľ����ȫ��ͬ��������ͬ�����Խ����н��ֱ�ѹ������ջ��Ȼ��ֱ�Ƚ����ǵ�ջ�������γ�ջ*/
/*���ҵ��ϳ�������Ȼ�������ߵ��ȶ����������Ĳ��֣�Ȼ����������һ������ȥ���ҵ���ͬ��Ϊֹ*/
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


//������ջ�ķ���
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


