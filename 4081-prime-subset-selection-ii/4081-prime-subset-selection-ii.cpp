
class Solution {

    vector<int> getPrimes(int N) {
        vector<bool> isPrime(N, true);
        vector<int> primes;

        if (N > 0) isPrime[0] = false;
        if (N > 1) isPrime[1] = false;

        for (int i = 2; i * i < N; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < N; j += i)
                    isPrime[j] = false;
            }
        }

        for (int i = 2; i < N; ++i) {
            if (isPrime[i])
                primes.push_back(i);
        }

        return primes;
    }

    // {maximum sum, minimum count}
    using State = pair<int, int>;

    State fn(int IDX, vector<int>& primes, int s,
             vector<vector<State>>& dp,
             vector<vector<bool>>& visited,
             vector<vector<bool>>& take,
             int curSum) {

        if (IDX >= (int)primes.size() || curSum == s)
            return {curSum, 0};

        if (visited[IDX][curSum])
            return dp[IDX][curSum];

        visited[IDX][curSum] = true;

        // Leave
        State leave = fn(IDX + 1, primes, s,
                         dp, visited, take, curSum);

        // Pick
        State pick = {-1, INT_MAX};

        if (curSum + primes[IDX] <= s) {
            pick = fn(IDX + 1, primes, s,
                      dp, visited, take,
                      curSum + primes[IDX]);

            pick.second++;
        }

        // Compare sums first, then number of primes.
        // If both tie, Pick is lexicographically smaller.
        if (pick.first > leave.first ||
            (pick.first == leave.first &&
             pick.second < leave.second) ||
            (pick.first == leave.first &&
             pick.second == leave.second &&
             pick.first != -1)) {

            take[IDX][curSum] = true;
            return dp[IDX][curSum] = pick;
        }

        take[IDX][curSum] = false;
        return dp[IDX][curSum] = leave;
    }

public:
    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> primes = getPrimes(n + 1);
        int m = primes.size();

        vector<vector<State>> dp(
            m, vector<State>(s + 1, {-1, 0})
        );

        vector<vector<bool>> visited(
            m, vector<bool>(s + 1, false)
        );

        vector<vector<bool>> take(
            m, vector<bool>(s + 1, false)
        );

        fn(0, primes, s, dp, visited, take, 0);

        vector<int> answer;
        int curSum = 0;

        for (int i = 0; i < m && curSum < s; ++i) {
            if (take[i][curSum]) {
                answer.push_back(primes[i]);
                curSum += primes[i];
            }
        }

        return answer;
    }
};

