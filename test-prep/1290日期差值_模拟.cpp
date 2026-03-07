#include <iostream>
#include <string>

using namespace std;

int month[13] = {0, 
	31, 28, 31, 
	30, 31, 30,
	31, 31, 30, 
	31, 30, 31};
int prefix[13]{};

struct date{
	int yy, mm, dd;
    static bool isLeap(int yy);
    bool operator< (const date& other) const;
    date& operator++();
	
};
bool date::isLeap(int yy) {
    if (yy % 400 == 0) return true;
    if (yy % 4 == 0 && yy % 100 != 0) return true;
    return false;
}
bool date::operator< (const date& other) const {
    if(yy != other.yy) return yy < other.yy;
    if(mm != other.mm) return mm < other.mm;
    return dd < other.dd;
}
date& date::operator++() {
    dd++;
    int md = month[mm];
    if (mm == 2 && isLeap(yy)) md = 29;
    if (dd > md) {
        dd = 1;
        mm++;
        if (mm > 12) {
            mm = 1;
            yy++;
        }
    }
    return *this;
}
void cal_pref() {
	for (int i = 1; i <= 12; i++) {
		prefix[i] = prefix[i - 1] + month[i - 1];
	}
}
void to_num(string s, date& d) {
	d.yy = stoi(s.substr(0, 4));
	d.mm = stoi(s.substr(4, 2));
	d.dd = stoi(s.substr(6, 2));
}
int dif(string s1, string s2) {
	date d1, d2;
	to_num(s1, d1);
	to_num(s2, d2);
	if (d2 < d1) swap(d1, d2);
	int cnt = 1;
	while (d1 < d2) {
		++d1;
		cnt++;
	}
	return cnt;
}
int main() {
	cal_pref();
	string s1, s2;
	while (cin >> s1 >> s2) {
		cout << dif(s1, s2) << '\n';
	}
	
	return 0;
}