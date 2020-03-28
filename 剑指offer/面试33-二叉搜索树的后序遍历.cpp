/*输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。*/

#include <vector>
#include <iostream>
using namespace std;

bool VerifySquenceOfBSTCore(const vector<int>& sequence, int l, int r); 

bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.empty())
        return false;
    size_t len = sequence.size();
    return VerifySquenceOfBSTCore(sequence, 0, len);
}

bool VerifySquenceOfBSTCore(const vector<int>& sequence, int l, int r) {
    int root = sequence[r - 1];
    int i = 0;
    for (; i < r - l - 1; ++i) {
        if (sequence[i] > root)
            break;
    }
    int j = i;
    for (; j < r - l - 1; ++j) {
        if (sequence[j] < root)
            return false;
    }
    
    bool left = true;
    if (i > r)
        left = VerifySquenceOfBSTCore(sequence, l, i - 1);
    bool right = true;
    if (j < l - r - 1)
        VerifySquenceOfBSTCore(sequence, i, r - 1);
    
    return left && right;
}
