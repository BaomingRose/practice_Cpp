/*输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）*/

//剑指offer方法二：用哈希表保存对应的旧新链表对应结点，方便找随机指针 	pNewNode->random = um_pNode[pNode->random];
//方法三分为三个步骤，直接将新结点接在旧结点的后面，然后第二步找随机指针，只要指向原来结点的下一个新结点即可，第三步拆分两个链表 

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }
        unordered_map<RandomListNode*, RandomListNode*> um_pNode;
        RandomListNode* pNode = pHead;
        RandomListNode* pNewHead = new RandomListNode(pHead->label);
        um_pNode.insert(make_pair(pHead, pNewHead));
        RandomListNode* pNewNode = pNewHead;
        RandomListNode* pre = nullptr;
        pNode = pNode->next;
        while (pNode) {
            pre = pNewNode;
            pNewNode = new RandomListNode(pNode->label);
            pre->next = pNewNode;
            um_pNode.insert(make_pair(pNode, pNewNode));
            pNode = pNode->next;
        }
        
        for (pNode = pHead, pNewNode = pNewHead; pNode != nullptr && pNewNode != nullptr; pNode = pNode->next, pNewNode = pNewNode->next) {
            pNewNode->random = um_pNode[pNode->random];
        }
        
        return pNewHead;
    }
};
