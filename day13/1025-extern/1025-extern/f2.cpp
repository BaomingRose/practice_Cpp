static int i(10);

//����ĺ���ʹ�õ�i���Ǹ��ļ���i
extern int next() {
	return i += 1;
}

extern int last() {
	return i -= 1;
}

extern int other(int i) {
	static int j(5);
	return i = j += 1;
}

