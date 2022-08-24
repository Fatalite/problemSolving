#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n = 0;
int m = 0;

vector<int> tmp;
vector<vector<int>> lists;

void getCombination(int a, vector<int> v) {
    if (a == 0) {
        lists.push_back(v);
    }
    else {
        for (auto i : tmp) {
            vector<int> tt;
            tt = v;
            if (find(tt.begin(), tt.end(), i) == tt.end()) {
                tt.push_back(i);
                getCombination(a - 1, tt);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    //1 to n
    for (int i = 1; i <= n; i++) {
        int a = 0;
        cin >> a;
        tmp.push_back(a);
    }
    sort(tmp.begin(),tmp.end());

    getCombination(m, vector<int>());

    //print
    for (auto a : lists) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << "\n";
    }
}
    

