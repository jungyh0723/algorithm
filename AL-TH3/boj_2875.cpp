//조건문을 이용해서값들을 비교하며 품

#include <iostream>

using namespace std;

int main()
{
	int n, m, k, ans;
	cin >> n >> m >> k;
	n /= 2;
	bool flag;
	if(n < m) {
		m -= n;
		ans = n;
		n = 0;
		flag = false;
	} else {
		n -= m;
		ans = m;
		m = 0;
		flag = true;
	}
	n *= 2;
	if(flag) {
		if(k > n) {
			k -= n;
			if(k % 3 == 0)
				ans -= k / 3;
			else
				ans -= k / 3 + 1;
		}
	} else {
		if(k > m) {
			k -= m;
			if(k % 3 == 0)
				ans -= k / 3;
			else
				ans -= k / 3 + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
6 3 2
*/
