//1차원 배열로 각 수마다 개수를 저장해서 품

#include <iostream>

using namespace std;

int check[201];

int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		check[a+100]++;
	}
	int b;
	cin >> b;
	cout << check[b+100] << endl;
	return 0;
}
