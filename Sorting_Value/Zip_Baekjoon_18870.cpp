#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;
int n = 0;


bool compare(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {

    return a.first.second < b.first.second;
}

int main() {
    
    cin >> n;

    vector<pair<pair<int, int>, int>> numAndIndex;

    vector<int> zipNum;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        //((값, 원래인덱스),압축값);
        numAndIndex.push_back(pair<pair<int,int>,int>(pair<int, int>(a, i),-1));

    }

    //값에 따라서 정렬하기
    sort(numAndIndex.begin(), numAndIndex.end());

    int idx = 0;
    numAndIndex[0].second = 0;
    for (int i = 1; i < n ; i++ ) {
        idx++;
        //만약 이전꺼랑 다르면
        if (numAndIndex[i - 1].first.first != numAndIndex[i].first.first) {
            numAndIndex[i].second = idx;
        }
        else {
            idx--;
            numAndIndex[i].second = idx;
        }
    }
    //다시 인덱스에 따라서 정렬하기
    sort(numAndIndex.begin(), numAndIndex.end(), compare);

    for (pair<pair<int, int>, int> ppp : numAndIndex) {
        cout << ppp.second << " ";
    }



}
