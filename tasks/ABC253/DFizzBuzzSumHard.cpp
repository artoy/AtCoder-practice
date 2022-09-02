#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class DFizzBuzzSumHard {
public:
    long long gcd(long long a, long long b){
        if(a%b == 0){
            return b;
        }else{
            return gcd(b, a%b);
        }
    }

    long long lcm(long long a, long long b){
        return a*b / gcd(a, b);
    }

    void solve(std::istream& cin, std::ostream& cout) {
        long long N, A, B;
        cin >> N >> A >> B;

        long long ans = N * (N + 1) / 2;
        ans -= A * (N / A) * (N / A + 1) / 2;
        ans -= B * (N / B) * (N / B + 1) / 2;

        ans += lcm(A, B) * (N / lcm(A, B)) * (N / lcm(A, B) + 1) / 2;

        cout << ans << endl;
    }
};