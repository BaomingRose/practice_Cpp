static int i(10);

//下面的函数使用的i都是该文件的i
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

