#include <iostream>
using namespace std;

void MovingHanoi(int num, char from, char by, char to) //num개의 원반을 by를 거쳐서 from에서 to로 이동한다.
{
	if (num == 1)
		cout << "원반 1을 " << from << " 에서 " << to << "로 이동\n";
	else {
		MovingHanoi(num - 1, from, to, by); //n-1 개의 원반을 a에서 c를 거쳐서 b로 이동
		cout << "원반 " << num << "을 " << from << "에서 " << to << "로 이동\n";
		MovingHanoi(num-1,by,from,to);
	}
}

int main() {

	MovingHanoi(3, 'A', 'B', 'C');
}