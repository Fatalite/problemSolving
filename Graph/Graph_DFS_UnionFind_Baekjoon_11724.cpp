#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;
//dfs => 시간이 빠르다.
//union find => 저장메모리가 적다.
int n = 0;
int m = 0;

int arr[1009];
int findRoot(int x) {
    if (arr[x] == x) {
        return x;
    }
    else {
        return findRoot(arr[x]);
    }
}

int main() {
    cin >> n >> m;

    fill_n(arr, 1000, -1);

    for (int i = 0; i < n; i++) {
        arr[i + 1] = i + 1;
    }


    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int u = arr[y];
        int v = arr[x];
        for (int k = 1; k <= n; k++) {
            if (arr[k] == u) {
                arr[k] = findRoot(v);
            }
        }

    }
    vector<int> tmp;
    int counts = 0;
    for (int i = 1; i <= n; i++) {
        bool isUnique = true;
        for (int k : tmp) {
            if (k == arr[i]) {
                isUnique = false;
            }
        }
        if (isUnique) {
            tmp.push_back(arr[i]);
            counts++;
        }
    }
    cout << counts;

}

