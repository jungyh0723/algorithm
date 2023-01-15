//스택을 사용하여 큰 단위부터 하나씩 나눠가며 품

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n, k, ans = 0;
	cin >> n >> k;
	stack<int> s;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.push(a);
	}
	while(!s.empty()) {
		ans += k / s.top();
		k %= s.top();
		s.pop();
	}
	cout << ans << endl;
}
