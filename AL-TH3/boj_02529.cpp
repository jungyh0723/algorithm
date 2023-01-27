//배열을 이용해서 쓴 숫자들을 체크하여 품

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string max_ans, min_ans;
	bool check[10];
	fill_n(check, 10, false);
	cin >> n;
	char arr[9];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for(int i = 0; i < n; i++) {
		if(arr[i] == '>') {
			for(int j = 9; j >= 0; j--) {
				if(!check[j]) {
					check[j] = true;
					max_ans += j + '0';
					break;
				}
			}
		} else {
			int cnt = 1;
			while(arr[i+cnt] == '<') cnt++;
			for(int j = 9; j >= 0; j--) {
				if(!check[j]) {
					if(cnt == 0) {
						check[j] = true;
						max_ans += j + '0';
						break;
					} else {
						cnt--;
					}
				}
			}
		}
	}
	for(int j = 9; j >= 0; j--) {
		if(!check[j]) {
			check[j] = true;
			max_ans += j + '0';
			break;
		}
	}
	fill_n(check, 10, false);
	for(int i = 0; i < n; i++) {
		if(arr[i] == '<') {
			for(int j = 0; j < 10; j++) {
				if(!check[j]) {
					check[j] = true;
					min_ans += j + '0';
					break;
				}
			}
		} else {
			int cnt = 1;
			while(arr[i+cnt] == '>') cnt++;
			for(int j = 0; j < 10; j++) {
				if(!check[j]) {
					if(cnt == 0) {
						check[j] = true;
						min_ans += j + '0';
						break;
					} else {
						cnt--;
					}
				}
			}
		}
	}
	for(int j = 0; j < 10; j++) {
		if(!check[j]) {
			check[j] = true;
			min_ans += j + '0';
			break;
		}
	}
	cout << max_ans << endl;
	cout << min_ans << endl;
}
