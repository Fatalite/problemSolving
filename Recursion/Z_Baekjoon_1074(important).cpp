#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

int n = 0;
int r = 0;
int c = 0;

int counts = 0;

int main() {
    cin >> n >> r >> c;
    //i = 0, 1
    //n = 3
    deque<int> tmp;
    int nt = n - 1;
    int count = 0;
    // 3 7 7
    // n = 3
    // 16가 경계선
    // 
    // 16 = 2^4
    
    int nowSize = pow(4, n);
    while (nowSize != 1) {
        cout << r << " " << c << " " << endl;
        nowSize = nowSize / 4;
        cout << nowSize << endl;
        if (r >= sqrt(nowSize) && c >= sqrt(nowSize)) {
            tmp.push_back(4);
            r = r - sqrt(nowSize);
            c = c - sqrt(nowSize);
            continue;
        }
        if (r < sqrt(nowSize) && c >= sqrt(nowSize)) {
            tmp.push_back(2);
            c = c - sqrt(nowSize);
            continue;
        }
        if (r < sqrt(nowSize) && c < sqrt(nowSize)) {
            cout << "이게 왜";
            tmp.push_back(1);
            continue;
        }
        if (r >= sqrt(nowSize) && c < sqrt(nowSize)) {
            tmp.push_back(3);
            r = r - sqrt(nowSize);
            continue;
        }
    }
    // 4 7 7
    // 1 4 4
    cout << endl;
    // 1 * 
    int a = 1;
    while (!tmp.empty()) {
        count = count + (tmp.back() - 1) * a;
        a = a * 4;
        //cout << tmp.front() << " " << endl;
        tmp.pop_back();
    }
    cout << endl;
    cout << count;
}

