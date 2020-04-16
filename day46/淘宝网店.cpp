#if 0
// write your code here cpp
#include <iostream>
#include <set>
using namespace std;

bool isLeap(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int main() {
	int monthPrime[13] = { 0, 2, 1, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2 };
	int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int yearSum = 0;
	for (int i = 1; i <= 12; ++i) {
		yearSum += (monthPrime[i] * monthDay[i]);
	}
	int b_year, b_month, b_day;
	int e_year, e_month, e_day;
	int sum = 0;
	while (cin >> b_year >> b_month >> b_day >> e_year >> e_month >> e_day) {
		if (b_year == e_year) {
			if (b_month == e_month) {
				sum += monthPrime[b_month] * (e_day - b_day + 1);
				cout << sum << endl;
			}
			else {
				for (int i = b_month + 1; i < e_month; ++i) {
					sum += monthDay[i] * monthPrime[i];
				}
				sum += monthPrime[b_month] * (monthDay[b_month] - b_day + 1);
				sum += monthPrime[e_month] * e_day;
				if (isLeap(e_year) && e_month > 2 && b_month <= 2)
					sum += 1;
				cout << sum << endl;
			}
		}
		else {
			for (int i = b_year + 1; i < e_year; ++i) {
				isLeap(i) ? sum += (yearSum + 1) : sum += yearSum;
			}
			for (int i = b_month + 1; i <= 12; ++i) {
				sum += monthDay[i] * monthPrime[i];
			}
			sum += monthPrime[b_month] * (monthDay[b_month] - b_day + 1);
			if (isLeap(b_year) && b_month <= 2)
				sum += 1;
			for (int i = 1; i < e_month; ++i)
				sum += monthPrime[i] * monthDay[i];
			sum += monthPrime[e_month] * e_day;
			if (isLeap(e_year) && e_month > 2)
				sum += 1;
			cout << sum << endl;
		}
		sum = 0;
	}
}
#endif