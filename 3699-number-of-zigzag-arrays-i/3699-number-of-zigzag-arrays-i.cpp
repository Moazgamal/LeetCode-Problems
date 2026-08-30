class Solution {
    int dp[2001][2001];
    const int MOD = 1e9 + 7;

public:
    int zigZagArrays(int n, int l, int r) {

        int countOfNums = r - l + 1;
        int N = countOfNums - 1;

        memset(dp, 0, sizeof(dp));

        // Base case:
        // fn(curNumber, n) = curNumber
        for (int curNumber = 1; curNumber <= N; curNumber++) {
            dp[curNumber][n] = curNumber;
        }

        /*
            We calculate the same states as your fn(),
            but bottom-up to avoid the huge number of calls.
        */

        for (int stage = n - 1; stage >= 3; stage--) {

            // This represents the while loop when curNumber == N:
            //
            // fn(N, stage+1)
            // + fn(N-1, stage+1)
            // + ...
            // + fn(1, stage+1)

            long long sum = 0;

            for (int x = 1; x <= N; x++) {
                sum += dp[x][stage + 1];

                if (sum >= MOD)
                    sum -= MOD;
            }

            dp[N][stage] = (int)sum;

            /*
                Your original:

                if(curNumber+1 <= N)
                    dp[curNumber][stage] =
                        dp[curNumber+1][stage]
                        - dp[N-curNumber][stage+1];
            */

            for (int curNumber = N - 1; curNumber >= 1; curNumber--) {

                int value =
                    dp[curNumber + 1][stage]
                    - dp[N - curNumber][stage + 1];

                if (value < 0)
                    value += MOD;

                dp[curNumber][stage] = value;
            }
        }

        // -------------------------
        // Same code as your answer
        // -------------------------

        long long ans = 0;
        long long firstVal = 0;

        firstVal = dp[N][3];

        for (int i = 1; i < N; i++) {
            firstVal += dp[N - i][3];

            if (firstVal >= MOD)
                firstVal -= MOD;
        }

        for (int i = 0; i < countOfNums / 2; i++) {

            ans = (ans + 2LL * firstVal) % MOD;

            firstVal -= dp[i + 1][3];

            if (firstVal < 0)
                firstVal += MOD;

            firstVal += dp[N - i][3];

            if (firstVal >= MOD)
                firstVal -= MOD;
        }

        if (countOfNums % 2 != 0) {
            ans += firstVal;

            if (ans >= MOD)
                ans -= MOD;
        }

        return (int)ans;
    }
};