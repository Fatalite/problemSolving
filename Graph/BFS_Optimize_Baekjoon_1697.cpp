#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int n = 0;
int m = 0;

int timeG = 0;

int main() {
    
    cin >> n;
    cin >> m;

    queue<int> q;
    vector<bool> checked(100005, false);
    q.push(n);

    while (!q.empty()) {

        int qs = q.size();
        
        for (int i = 0; i < qs; i++) {

           

            if (q.front() == m) {
                cout << timeG;
                return 0;
            }

            if (q.front() < 0 || q.front() > 100001) {
                q.pop();
                continue;
            }
            else {
                //m을 넘어간 경우에
                if (q.front() > m) {
                    if (checked[q.front()] != true && q.front() < 100001) {
                        checked[q.front()] = true;
                        q.push(q.front() - 1);
                    }

                }
                else {
                    if (checked[q.front()] != true && q.front() < 100001) {
                        checked[q.front()] = true;
                        q.push(2 * q.front());
                        q.push(q.front() - 1);
                        q.push(q.front() + 1);
                    }
                }
                q.pop();

            }

           
        }
       

        timeG++;
    }

}
