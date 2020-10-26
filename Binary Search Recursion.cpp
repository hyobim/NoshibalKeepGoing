#include <iostream>
using namespace std;

int BSearch(int arr[],int first, int last, int target) {
	int mid;
	mid = (first + last) / 2;
	if (first > last)
		return -1;
	
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
		return BSearch(arr, first, mid - 1, target);
	else if (arr[mid] < target)
		return BSearch(arr, mid + 1, last, target);
	
}

int main() {

	int arr[] = { 1,3,5,7,9,11 };
	int idx = BSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 3);
	if (idx == -1)
		cout << "Å½»ö ½ÇÆĞ!\n";
	else
		cout << "Å½»ö ¼º°ø! : " << idx << "\n";

	idx = BSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 9);
	if (idx == -1)
		cout << "Å½»ö ½ÇÆĞ!\n";
	else
		cout << "Å½»ö ¼º°ø! : " << idx << "\n";

	idx = BSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 9);
	if (idx == -1)
		cout << "Å½»ö ½ÇÆĞ!\n";
	else
		cout << "Å½»ö ¼º°ø! : " << idx << "\n";

	idx = BSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 14);
	if (idx == -1)
		cout << "Å½»ö ½ÇÆĞ!\n";
	else
		cout << "Å½»ö ¼º°ø! : " << idx << "\n";
}