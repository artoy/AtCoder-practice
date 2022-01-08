#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class AWeirdFunction {
public:
    int f(int t) {
        return pow(t, 2) + 2 * t + 3;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int t, ans;
        cin >> t;

        ans =  f(f(f(t)+t)+f(f(t)));

        cout << ans << endl;
    }
};