#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n = 0;

int arr[1000] = { 0 };

int main() {
	//우선순위 큐
	priority_queue<int, vector<int>, greater<int>> pq;

	//입출력 향상
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	//n을 입력
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		//0이 입력 될 경우 
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}

}
