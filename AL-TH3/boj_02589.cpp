//2차원 배열과 bfs로 배열에 1씩 더하는 방법을 사용하여 품

#include <iostream>
#include <queue>

using namespace std;

int arr[51][51], map[51][51], check[51][51];
	int n, m;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int bfs(pair<int, int> start) {
	queue<pair<int, int> > q;
	check[start.first][start.second] = true;
	q.push(start);
	int maxv = -1;

	while(!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			pair<int, int> next = node;
			next.first += dy[i];
			next.second += dx[i];
			int nx = next.first;
			int ny = next.second;
			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if(check[nx][ny] == false && arr[nx][ny] == 1) {
				q.push(next);
				check[nx][ny] = true;
				map[nx][ny] = map[node.first][node.second] + 1;
				maxv = max(map[nx][ny], maxv);
			}
		}
	}
	return maxv;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char a;
			cin >> a;
			if(a == 'W') {
				map[i][j] = 0;
				arr[i][j] = 0;
			} else {
				map[i][j] = 1;
				arr[i][j] = 1;
			}
		}
	}
	int prt = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == 1) {
				int b = bfs(make_pair(i, j));
				prt = max(prt, b);
			}
			for(int k = 0; k < n; k++) {
				for(int l = 0; l < m; l++) {
					map[k][l] = arr[k][l];
					check[k][l] = false;
				}
			}
		}
	}
	cout << prt-1 << endl;
}
