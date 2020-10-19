#include<iostream>
#include<string>
using namespace std;

class Birth {
public:
	int year;
	int month;
	int day;
	char gender;

	Birth() {
		year = 0;
		month = 0;
		day = 0;
		gender = ' ';
	}
	void yearc(int i, int j) {
		year = i * 10 + j;
	}
	void monthc(int i, int j) {
		month = i * 10 + j;
	}
	void dayc(int i, int j) {
		day = i * 10 + j;
	}
	void genderc(int y) {
		if (y == 1) {
			gender = 'M';
			year = year + 1900;
		}
		else if (y == 3)
		{
			gender = 'M';
			year = year + 2000;

		}
		else if (y == 2) {
			gender = 'F';
			year = year + 1900;
		}
		else if (y == 4) {
			gender = 'F';
			year = year + 2000;
		}
	}
	void Print() {
		cout << year << "/";
		cout.width(2);
		cout.fill('0');
		cout << month; 
		cout << "/"; 
		cout.width(2);
		cout.fill('0');
		cout << day;
		cout<< " " << gender << "\n";
	}
};

int main() {
	Birth b;
	string br;
	cin >> br;

	b.yearc(br[0] - '0', br[1] - '0');
	b.monthc(br[2] - '0', br[3] - '0');
	b.dayc(br[4] - '0', br[5] - '0');
	b.genderc(br[7] - '0');
	b.Print();
}