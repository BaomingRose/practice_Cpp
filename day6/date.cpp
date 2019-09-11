/*
设计一个日期类，包含以下功能：
1、只能通过传入年月日初始化。
2、可以加上一个数字n，返回一个该日期后推n天之后的日期。
*/

#include<iostream>
#include<cstdlib>
using namespace std;
typedef unsigned int uint;

static uint getMonthDay(int y, uint m) {
	if (m > 12 || m == 0) {
		return 0;
	}

	if (m == 4 || m == 6 || m == 9 || m == 11) {
		return 30;
	} else if (m == 2) {
		return 28 + (y % 400 == 0 || (y % 4 == 0 && y % 100));
	} else {
		return 31;
	}
}

int getLeapNum(int sy, int ey) {
	int tmp = sy % 4;
	if (tmp) {
		sy += (4 - tmp);
	}
	return (ey - sy) / 4 + 1;
}

class Date {
	int m_year;
	uint m_month;
	uint m_day;
	
	uint getDayOfYear();
public:
	Date(int y, uint m, uint d) :
		m_year(y),
		m_month(m),
		m_day(d)
	{}

	~Date() {
		//cout << "123" << endl;
	}

	Date operator +(uint delay) const {
		Date res = *this;
		uint tmp;
		#if 0
		int numy = delay / 365;
		int numd = delay % 365;
		int flag = 0;
	
		if (res.m_month > 2) {
			flag = 1;
		}
		int leapnum = getLeapNum(res.m_year + flag, res.m_year + numy);
		while (numd < leapnum) {
			numy--;
			leapnum = getLeapNum(res.m_year + flag, res.m_year + numy);
			numd += 365;
		}
		numd -= leapnum;
		
		res.m_year += numy;
		delay = numd;
		#endif
	
		tmp = getMonthDay(res.m_year, res.m_month);
		while (delay >= tmp) { 
			delay -= tmp;
			res.m_month++;
			if (res.m_month > 12) {
				res.m_month = 1;
				res.m_year++;
			}
			tmp = getMonthDay(res.m_year, res.m_month);
		}
	
		res.m_day += delay;
		if (res.m_day > tmp) {
			res.m_month++;
			if (res.m_month > 12) {
				res.m_month = 1;
				res.m_year++;
			}
			res.m_day -= tmp;
		}
		return res;
	}

	bool operator <(const Date & d) const {
		if (m_year < d.m_year) {
			return true;
		}
		if (m_year == d.m_year && m_month < d.m_month) {
			return true;
		} else if (m_year == d.m_year &&
			     m_month == d.m_month && 
			     m_day < d.m_day) {
				return true;
		}
		return false;
	} 
	
	bool operator >(const Date & d) const {
		if (m_year > d.m_year) {
			return true;
		}
	
		if (m_year == d.m_year && m_month > d.m_month) {
			return true;
		} else if (m_year == d.m_year &&
			m_month == d.m_month &&
			m_day > d.m_day) {
			return true;
		}
		return false;
	}
	
	bool operator <=(const Date & d) const {
		return !(*this > d);
	}
	
	bool operator >=(const Date & d) const {
		return !(*this < d);
	}
	
	bool operator ==(const Date & d) const {
		if (m_year == d.m_year &&
		m_month == d.m_month &&
		m_day == d.m_day) {
			return true;
		}
		return false;
	}
	
	bool operator !=(const Date & d) const {
		return !(*this == d);
	}

	Date operator - (uint delay) const; 
	int operator - (const Date & d) const;
	friend ostream &operator << (ostream & os, const Date & d);
	
	//前置 
	Date operator ++ () {
		*this = *this + 1;
		return *this;
	} 
	
	//后置 		后置需要传一个int 
	Date operator ++ (int) {
		Date tmp = *this;
		*this = *this + 1;
		return tmp;
	}
	
	int add_1(int src) {
		int tmp = src;
		src += 1;
		return tmp;
	} 
	Date& operator -- () {
		*this = *this - 1;
		return *this;
	}
	
	Date operator --(int) {
		Date tmp = *this;
		*this = *this - 1;
		return tmp;
	}
};

uint Date::getDayOfYear()
{
	int i;
	uint days = 0;

	for (i = 1; i < m_month; i++)
	{
		days += getMonthDay(m_year, i);
	}

	return days + m_day;
}

Date Date::operator - (uint delay) const {
	Date res = *this;
	uint tmp;

	if (res.m_month == 0) {
		res.m_year--;
		res.m_month = 12;
	} else {
		res.m_month--;
	}
	tmp = getMonthDay(res.m_year, res.m_month);
	while (delay >= tmp) {
		delay -= tmp;
		res.m_month--;
		if (res.m_month == 0) {
			res.m_month = 12;
			res.m_year--;
		}
		tmp = getMonthDay(res.m_year, res.m_month);
	}

	int tmpday = res.m_day;
	tmpday = res.m_day - delay;
	if (tmpday <= 0) {
		tmpday += tmp;
	} else {
		res.m_month++;
		if (res.m_month > 12) {
			res.m_month = 1;
			res.m_year++;
		}
	}

	res.m_day = tmpday;
	return res;
}

int Date::operator - (const Date & d) const {
	Date bigger = *this;
	Date smaller = d;
	int flag = 1;
	if (*this < d) {
		bigger = d;
		smaller = *this;
		flag = -1;
	}
	int years = bigger.m_year - smaller.m_year;
	int days = years * 365 + getLeapNum(smaller.m_year, bigger.m_year - 1);

	days = days - smaller.getDayOfYear() + bigger.getDayOfYear();

	return days * flag;
}


ostream & operator << (ostream & os, const Date & d) {
	os << d.m_year << '-' << d.m_month << '-' << d.m_day;
	return os;
}

int main() {
	/*Date * pd1 = (Date *)malloc(sizeof(Date));
	//只是分配空间
	Date * pd2 = (Date *)operator new(sizeof(Date));
	//分配空间，失败会调用处理方式或者抛异常
	Date * pd3 = new Date(1999, 12, 20);
	//在operator new的基础上调用了构造函数
	Date * pd = new Date[3]{Date(1999, 12, 20), Date(2000, 12, 20), Date(2001, 12, 20)};
	cout << pd[0] << endl;
	cout << pd[2] << endl;
	delete[] pd;*/

#if 0
	char * pa = (char *)malloc(1024);
	size_t size = 0;

	Date * pd = new(pa + size)Date(2015, 2, 22);

	size += sizeof(Date);

	Date * pd2 = new(pa + size)Date(2015, 2, 22);

	cout << (void *)pa << endl << pd << endl << pd2;
#endif

	Date d(2019, 9, 10);
	++d;
	cout << d--;
	return 0;
}

