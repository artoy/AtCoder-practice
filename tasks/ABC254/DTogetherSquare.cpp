#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class DTogetherSquare {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        int ans = N;

        for (int i = 1; i < sqrt(N); i++) {
            for (int j = 1; j < sqrt(N); j++) {
                if (sqrt(i * i * j * j) == int(sqrt(i * i * j * j)) && sqrt(i * i * j * j) <= N) {
                    ans++;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (i * i * i <= N && i > 1) {
                ans++;
            }
        }

        cout << ans << endl;
    }
};