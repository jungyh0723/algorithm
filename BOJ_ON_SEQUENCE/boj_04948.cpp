//에라토스테네스의 체를 이용하여 품

#include <iostream>
#include <string>

using namespace std;

bool arr[123456 * 2];

int main()
{
    arr[1] = true;
    for(int i = 2; i*i <= 123456*2; i++) {
        if(arr[i] == false){
            for(int j = i * 2; j <= 123456*2; j += i) {
                arr[j] = true;
            }
        }
    }
    while(1) {
        int n;
        cin >> n;
        if(n == 0)
            break;
        int cnt = 0;
        for(int i = n+1; i <= 2 * n; i++) {
            if(arr[i] == false) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
