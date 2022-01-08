#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class DPrefixKThMax {
public:
    vector<int> push(vector<int> sorted, int n) {
        for (int i = 0; i < sorted.size(); ++i) {
            if (sorted.at(i) < n) {
                for (int j = sorted.size() - 1; j > i; --j) {
                    sorted.at(j) = sorted.at(j - 1);
                }
                sorted.at(i) = n;
                break;
            }
        }

        return sorted;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;

        vector<int> P (N);
        for (int i = 0; i < N; ++i) {
            cin >> P.at(i);
        }

        vector<int> sorted (K);
        for (int i = 0; i < K; ++i) {
            sorted.at(i) = P.at(i);
        }

        sort(sorted.begin(),sorted.end(),greater<int>());
        cout << sorted.at(K - 1) << endl;

        for (int i = K; i < N; ++i) {
            if (sorted.at(K - 1) < P.at(i)) {
                sorted = push(sorted, P.at(i));
            }

            cout << sorted.at(K - 1) << endl;
        }
    }
};