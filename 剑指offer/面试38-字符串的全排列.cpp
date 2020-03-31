/*����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring> 
using namespace std;
void PermutaCore(char* pstr, char* pBegin, vector<string>& vs);
#include <algorithm>
//���״��������Ӧ����algorithm��ʹ����sort��unique��swap 

vector<string> Permutation(string str) {
    vector<string> res;
    if (str.empty())
        return res;
    char* pstr = new char[str.length() + 1];
    memset(pstr, 0, str.length() + 1);
    strcpy(pstr, str.c_str());
    PermutaCore(pstr, pstr, res);
    
    //�������������������Ҫ��uniqueunique������һ��ȥ�غ�����ȥ�������е��ظ�Ԫ�أ�ֻ��һ������
	//���У���ؼ����ǣ�������ɾ�������ǰ��ظ���Ԫ��ɾ��������ȫ���ŵ�����ĺ��档 
	//unique()�������ظ���Ԫ�طŵ�vector��β�� Ȼ�󷵻�ָ���һ���ظ�Ԫ�صĵ����� 
	//����erase�������������Ԫ�ص����Ԫ�ص����е�Ԫ��
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    
    return res;
}

//����ݹ�Ҳ�ǹؼ��� ʹ���˻��ݣ�ÿ�ν�������ַ����һ���ַ����� 
void PermutaCore(char* pstr, char* pBegin, vector<string>& vs) {
    if (*pBegin == '\0')
        vs.push_back(pstr);
    else
        for (char* pch = pBegin; *pch != '\0'; ++pch) {
            swap(*pch, *pBegin);
            PermutaCore(pstr, pBegin + 1, vs);
            swap(*pch, *pBegin);
        }
}

int main() {
	string str;
	while (cin >> str) {
		vector<string> vs = Permutation(str);
		for (int i = 0; i < vs.size(); ++i) {
			cout << vs[i] << endl;
		}
	}
	
	return 0;
}

