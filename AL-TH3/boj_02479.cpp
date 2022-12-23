//두 이진수의 차이가 1인 것들의 간선이 연결된 그래프로 배열에 저장해서 dfs를 사용하여 품

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<int> v[1001], arr[1001], path[1001];
bool checkdfs[1001];

void dfs(int a) {
	checkdfs[a] = true;
	path[a].push_back(a);

	for(int i = 0; i < arr[a].size(); i++) {
		int next = arr[a][i];
		if(!checkdfs[next]) {
			for(int j = 0; j < path[a].size(); j++) {
				path[next].push_back(path[a][j]);
			}
			dfs(next);
		}
	}
}


int main() {
	vector<int> ans;
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < k; j++) {
			int a;
			scanf("%1d", &a);
			v[i].push_back(a);
		}
	}
	int a, b;
	scanf("%d %d", &a, &b);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			int cnt = 0;
			for(int l = 0; l < k; l++) {
				if(v[i][l] != v[j][l])
					cnt++;
			}
			if(cnt == 1)
				arr[i].push_back(j);
		}
	}
	dfs(a);
	if(path[b].size() == 0) {
		printf("-1\n");
		return 0;
	}
	if(path[b][path[b].size()-1] != b) {
		printf("-1\n");
		return 0;
	}
	for(int i = 0; i < path[b].size(); i++) {
		printf("%d ", path[b][i]);
	}
	printf("\n");
}

/*
5 3
000
111
010
110
001
1 2
*/
