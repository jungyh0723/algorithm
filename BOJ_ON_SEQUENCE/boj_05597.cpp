//1차원 배열로 제출한 사람을 확인해서 품

#include <iostream>

using namespace std;

bool check[31];

int main() {
	
	for(int i = 0; i < 28; i++) {
		int a;
		cin >> a;
		check[a] = true;
	}
	for(int i = 1; i <= 30; i++) {
		if(check[i] == false) {
			cout << i << endl;
		}
	}
	return 0;
}
