//3차원 배열과 bfs를 사용해고 배열에 1씩 더하는 방법을 사용하여 품

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

struct pos {
    int x, y, z;
};

using namespace std;
int n, m, h;
int map[101][101][101], check[101][101][101];
queue<pos> q;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int bfs()
{
    int ret = 1;
    while(!q.empty()) {
        pos p = q.front();
        q.pop();
        for(int i = 0; i < 6; i++) {
            pos next = {p.x+dx[i], p.y+dy[i], p.z+dz[i]};
            int nx = next.x;
            int ny = next.y;
            int nz = next.z;
            if(nx >= 0 && ny >= 0 && nz >= 0 && nx < h && ny < m && nz < n) {
                if(check[nx][ny][nz] == false && map[nx][ny][nz] == 0) {
                    check[nx][ny][nz] = true;
                    map[nx][ny][nz] = map[p.x][p.y][p.z] + 1;
                    q.push(next);
                    ret = max(ret, map[nx][ny][nz]);
                }
            }
        }
    }
    return ret;
}


int main()
{
    cin >> n >> m >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                int a;
                cin >> a;
                map[i][j][k] = a;
                if(a == 1) {
										struct pos b;
										b.x = i;
										b.y = j;
										b.z = k;
                    q.push(b); 
                    check[i][j][k] = true;
                }
            }
        }
    }
    int ans = bfs();
    bool flag = true;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                if(map[i][j][k] == 0)
                    flag = false;
            }
        }
    }
    if(!flag)
        cout << "-1" << endl;
    else
        cout << ans-1 << endl;
}
