/*����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�*/

//��ָoffer���������ù�ϣ�����Ӧ�ľ��������Ӧ��㣬���������ָ�� 	pNewNode->random = um_pNode[pNode->random];
//��������Ϊ�������裬ֱ�ӽ��½����ھɽ��ĺ��棬Ȼ��ڶ��������ָ�룬ֻҪָ��ԭ��������һ���½�㼴�ɣ������������������ 

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
