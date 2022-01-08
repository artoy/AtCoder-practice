#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class CHappyNewYear {
public:
    string binary(long long int bina){
        string ans = "";
        for (long long int i = 0; bina>0 ; i++)
        {
            ans = to_string(((int)(bina % 2) * 2)) + ans;
            bina = bina/2;
        }
        return ans;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        long long int K;
        cin >> K;

        cout << binary(K) << endl;
    }
};