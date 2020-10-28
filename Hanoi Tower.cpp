#include <iostream>
using namespace std;

void MovingHanoi(int num, char from, char by, char to) //num���� ������ by�� ���ļ� from���� to�� �̵��Ѵ�.
{
	if (num == 1)
		cout << "���� 1�� " << from << " ���� " << to << "�� �̵�\n";
	else {
		MovingHanoi(num - 1, from, to, by); //n-1 ���� ������ a���� c�� ���ļ� b�� �̵�
		cout << "���� " << num << "�� " << from << "���� " << to << "�� �̵�\n";
		MovingHanoi(num-1,by,from,to);
	}
}

int main() {

	MovingHanoi(3, 'A', 'B', 'C');
}