#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class BigInteger {
    string digits;
public:
    BigInteger(unsigned long long int a) {
        do {
            digits.push_back(a % 10);
            a /= 10;
        } while (a);
    }
    friend BigInteger& operator*=(BigInteger&, const BigInteger&);
    BigInteger& operator=(const BigInteger&);

    BigInteger addBigInteger(BigInteger& a, BigInteger& b) {
        int n = a.digits.length();
        int m = b.digits.length();
        if (a.digits.length() < b.digits.length()) {
            b.digits.append(m - n, 0);
            //EX : 000123456 , 123456789
        }
        n = a.digits.length();
        int t = 0;
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (i < m) {
                s = (a.digits[i] + b.digits[i] + t);
            }
            else {
                s = (a.digits[i] + t);
            }
            t = s / 10;
            a.digits[i] = s % 10;
        }

        if (t) {
            a.digits.push_back(t);
        }
        return a;

    }

    void print() {
        for (int  a = digits.size() - 1; a >= 0; a--) {
            cout << int(digits[a]);
        }
    }

    BigInteger multiplyBigInteger (BigInteger& a, const BigInteger& b) {
        int n = a.digits.size(), m = b.digits.size();
        vector<int> v(n + m, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                v[i + j] += (a.digits[i]) * (b.digits[j]);
            }
        n += m;
        a.digits.resize(v.size());
        for (int s, i = 0, t = 0; i < n; i++)
        {
            s = t + v[i];
            v[i] = s % 10;
            t = s / 10;
            a.digits[i] = v[i];
        }
        for (int i = n - 1; i >= 1 && !v[i]; i--)
            a.digits.pop_back();
        return a;
    }

};

vector<unsigned long long> divide(unsigned long long a) {
    vector<unsigned long long> re;
    bool finished = false;
    if (a == 1) {
        re.push_back(1);
        return re;
    }
    while (!finished) {
        for (int i = 2; i <= a; i++) {
            if (i == a) {
                finished = true;
            }
            if (a % i == 0) {
                re.push_back(i);
                a = a / i;
                break;
            }
        }
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    int m = 0;
    vector<unsigned long long> a;
    vector<unsigned long long> b;
    BigInteger result(1);
    cin >> n >> m;

    //소인수 분해
    for (int i = n; i > n - m; i--) {
        vector<unsigned long long> tmp = divide(i);
        for (unsigned long long u : tmp) {
            a.push_back(u);
            //cout << u << " ";
        }
        
    }
    cout << endl;
    for (int i = 1; i <= m; i++) {
        vector<unsigned long long> tmp = divide(i);
        for (unsigned long long u : tmp) {
            b.push_back(u);
            //cout << u << " ";
        }
    }
    cout << endl;
    //소인수 분해 끝

    int lengthA = a.size();
    int lengthB = b.size();
    for (int i = 0; i < lengthB; i++) {
        for (int k = 0; k < lengthA; k++) {
            if (b[i] == a[k]) {
                a[k] = 1;
                b[i] = 1;
                break;
            }
        }
    }
    vector<unsigned long long int> tmp;
    for (unsigned long long u : a) {
        result.multiplyBigInteger(result, BigInteger(u));
        
    }
    cout << endl;
    for (unsigned long long j : b) {
        result.multiplyBigInteger(result, BigInteger(j));
        //cout << j << endl;
    }

    result.print();
}
    

