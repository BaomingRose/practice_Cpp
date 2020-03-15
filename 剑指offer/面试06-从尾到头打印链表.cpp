#include <iostream>
#include <stack>
using namespace std;

/*逆序打印链表*/ 

struct ListNode {
	int data;
	ListNode* m_pNext;
}; 

//用栈存储结点，依次打印结点 
void PrintListRversingly_Iteratively(ListNode* pHead) {
	stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	
	while (!nodes.empty()) {
		pNode = nodes.top();
		cout << pNode->m_pNext << "\t";
		nodes.pop(); 
	}
}

//每访问到一个结点的时候，先递归输出它后面的结点 
void PrintListReversingly_Recursively(ListNode* pHead) {
	if (pHead != nullptr) {
		if (pHead->m_pNext != nullptr) {
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		
		cout << pHead->data << "\t";
	}
}
