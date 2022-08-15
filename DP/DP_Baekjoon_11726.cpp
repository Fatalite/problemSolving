#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0;

int arr[1000] = { 0 };

int main() {
	//입출력 향상
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	//n을 입력
	cin >> n;

	//2 x n에 타일 채우는 경우의 수
	int i = 3;
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	while (i <= n) {
		arr[i] = arr[i - 1] + arr[i - 2];
		//문제상에서 아예 arr[i]값을 10007까지로 한정해둔듯
		//그래서 하면서 %하는 것이랑 결과에만 %하는 것이 달라서 문제가 일어났었음
		arr[i] %= 10007;
		i++;
	}
	cout << arr[n] % 10007 << endl;
	//바텀업 - 탑다운 차이점
	//함수 호출 오버헤드, if문 하나 없음
}

