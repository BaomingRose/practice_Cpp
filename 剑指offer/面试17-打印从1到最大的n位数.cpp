#include <iostream>
#include <cstring> 
using namespace std;

bool increasement(char* s) {
	bool res = false;
	int sumBit = 0;
	int takeOver = 0;
	int nLength = strlen(s);
	for (int i = nLength - 1; i >= 0; --i) {
		int sumBit = s[i] - '0' + takeOver;
		if (i == nLength - 1)
			++sumBit;
		if (sumBit >= 10) {
			if (i == 0)
				res = true;
			takeOver = 1;
			s[i] = sumBit - 10 + '0';
		} else {
			takeOver = 0;
			s[i] = sumBit + '0';
		}
	}
	return res;
}

void PrintNum(char* s) {
	if (s == NULL)
		return;
	char* ptr = s;
	while (*ptr == '0')
		++ptr;
	printf("%s\t", ptr);
}

void print1ToMaxOfNDigits(int n) {
	if (n <= 0) 
		return;
		
	char* s = new char[n + 1];
	memset(s, '0', n);
	s[n] = '\0';
	while (!increasement(s)) {
		PrintNum(s);
	}
	
	delete[] s;
}

int main() {
	print1ToMaxOfNDigits(1);
	
	return 0;
}
