#include <iostream>

using namespace std;

int parent[1000001];

int Find(int x)
{
	if(parent[x] == x)
		return x;
	else
		return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	parent[y] = x;
}

int main()
{ 
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 0)
			Union(b, c);
		else {
			cout << ((Find(b) == Find(c)) ? "yes\n" : "no\n");
		}
	}
	return 0;
}
/*
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

*/
