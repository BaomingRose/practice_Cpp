#include <iostream>
#include <stack>
using namespace std;

/*�����ӡ����*/ 

struct ListNode {
	int data;
	ListNode* m_pNext;
}; 

//��ջ�洢��㣬���δ�ӡ��� 
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

//ÿ���ʵ�һ������ʱ���ȵݹ����������Ľ�� 
void PrintListReversingly_Recursively(ListNode* pHead) {
	if (pHead != nullptr) {
		if (pHead->m_pNext != nullptr) {
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		
		cout << pHead->data << "\t";
	}
}
