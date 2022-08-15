#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int k = 0;

vector<int> nCases(12,0);

void getNumCases(int x) {
	if (x == k) nCases[k]++;

	if (x > k) {
		
	}
	else {
		getNumCases(x + 1);
		getNumCases(x + 2);
		getNumCases(x + 3);
	}
	
}

int main() {
	//입출력 향상
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	//테스트 케이스 입력
	int n = 0;
	cin >> n;

	
	vector<int> tmp;
	//테스트 케이스 별 정수 k 입력 후 
	//결과값 출력
	for (int i = 0; i < n; i++) {
		cin >> k;
		getNumCases(0);
		tmp.push_back(nCases[k]);
		nCases = vector<int>(12, 0);
	}

	for (int u : tmp) {
		cout << u << "\n";
	}
	
}