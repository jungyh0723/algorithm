//arr배열에 입력받고 dfs사용해서 사이클의 개수를 구함

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int arr[1001];
bool checkdfs[1001];

void dfs(int a) {
	checkdfs[a] = true;

	int next = arr[a];
	if(checkdfs[next] == false)
		dfs(next);
}

int main() {
	int n;
	cin >> n;
	vector<int> ans;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		for(int j = 1; j <= a; j++) {
			int b;
			cin >> b;
			arr[j] = b;
		}
		int cnt = 0;
		for(int j = 1; j <= a; j++) {
			if(checkdfs[j] == false) {
				dfs(j);
				cnt++;
			}
		}
		ans.push_back(cnt);
		fill_n(arr, a+1, 0);
		fill_n(checkdfs, a+1, false);
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
}
