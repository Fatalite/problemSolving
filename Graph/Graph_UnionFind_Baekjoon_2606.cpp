#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool ab[100];

vector<int> root;

int find(int x) {
	if (root[x] == x) {
		return x;
	}
	else {
		return find(root[x]);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n = 0;
	cin >> n;
	int k = 0;
	cin >> k;
	vector<pair<int, int>> edges;
	int max = 0;

	for (int i = 0; i < k; i++) {
		int a;
		int b;
		cin >> a >> b;
		
		edges.push_back(pair<int, int>(a - 1, b - 1));
		
		if (max < a-1) max = a-1;
		if (max < b-1) max = b-1;
		
	}

	// union root init
	for (int a = 0; a <= max; a++) {
		root.push_back(a);
	}

	//union points using edges
	for (pair<int, int> edge : edges) {
		int rx = edge.first;
		
		int ry = edge.second;
		
		rx = find(rx);
		ry = find(ry);
		//0을 저장
		int tmp = ry;
		//root[i] == tmp면, 걔도 rx로 바꿔줘야함
		for (int u = 0; u < root.size(); u++) {
			if (root[u] == tmp) {
				root[u] = rx;
			}
		}
		
	}
	int counts = 0;
	for (int a : root) {
		//cout << a << " ";
		if (a == root[0]) {
			counts++;
		}
	}
	//cout << endl;
	cout << counts - 1;

}