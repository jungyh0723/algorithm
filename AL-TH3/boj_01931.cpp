//회의가 빨리 끝나는 순서대로 정렬하여 품

#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> l, pair<int, int> r)
{
	bool ret = l.second < r.second;
	if(l.second == r.second)
		ret = l.first < r.first;
	return ret;
}


int main()
{
	int n;
	cin >> n;
	pair<int, int> p[100001];
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p[i] = make_pair(a, b);
	}
	sort(p, p+n, cmp);
	int c = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(c <= p[i].first) {
			c = p[i].second;
			cnt++;
		}
	}
	cout << cnt << endl;
}
