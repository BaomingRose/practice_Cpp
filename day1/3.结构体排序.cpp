//3���������Ļ����ϣ���ɶԽṹ�������ͨ�������жϴ�С�ĺ�����ʵ�֡�

#include<iostream>
using namespace std;

struct Poker {
	char type;
	int point;
};

enum {
	SPADES,		//���� 
	HEARTS,		//���� 
	CLUBS,		//÷�� 
	DIAMONDS,	//���� 
	JOKER		//�� 
};


void inputpoker(Poker * pk) {
	scanf("%c%d", &pk->type, &pk->point);
	pk->type -= 'a';
	if (pk->type == JOKER) {
		pk->point += 13;
	}
	while (getchar() != '\n');
}

void outputpoker(Poker k) {
	char *type[5] = { "����", "����", "÷��", "��Ƭ", "" };
	char *point[16] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "С��", "����" };

	printf("%s%s\n", type[k.type], point[k.point]);
}

bool cmp1(Poker a, Poker b) {
	return (a.point < b.point) ||
		   (a.point == b.point && a.type > b.type);
}

//������˳�� 
bool cmp2(Poker a, Poker b) {
	if (a.point <= 2) {
		a.point += 11;
	}
	else if (a.point <= 13) {
		a.point -= 2;
	}
	if (b.point <= 2) {
		b.point += 11;
	} else if (b.point <= 13) {
		b.point -= 2;
	}
	return (a.point > b.point) ||
		(a.point == b.point && a.type < b.type);
}

void InsertSort(Poker *src, int n, bool (*cmp)(Poker, Poker) = cmp1) {
	Poker tmp;
	for(int i = 1; i < n; ++i) {
		tmp = src[i];
		int j;
		for(j = i; j > 0 && cmp(tmp, src[j - 1]); --j) {
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}

int main() {
	Poker p[5];
	for (int i = 0; i < 5; i++) {
		inputpoker(p + i);
	}
	InsertSort(p, 5, cmp1);
	for (int i = 0; i < 5; i++) {
		outputpoker(p[i]);
	}

	return 0;
}
