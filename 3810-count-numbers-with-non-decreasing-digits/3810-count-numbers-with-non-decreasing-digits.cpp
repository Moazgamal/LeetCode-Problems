using ll = long long;
const int MOD=1e9+7;
ll dp[333][2][10];
class Solution {
    
    string subtractOne(string l)
    {
        
        int i = l.size()-1;
        while(i>=0)
        {
            if(l[i]-'0' > 0)
            {
                l[i]--;
                break;
            }
            l[i] = '9';
            i--;
        }
        if(l[0] == '0' && l.size()>1)
        {
            l.erase(0,l.find_first_not_of('0'));
        }
        return l;
        
    }
    ll f(const string &num, int pos, int tight, int base, int prev_digit) {
        if (pos == (int)num.size()) return 1;
        ll &res = dp[pos][tight][prev_digit];
        if (res != -1) return res;
        res = 0;
        int ub = tight ? (num[pos] - '0') : (base - 1);
        for (int d = prev_digit; d <= ub; d++) {
            res += f(num, pos + 1, tight && (d == ub), base, d);
        }
        return res;
    }

    string divmodString(const string &num, int base, int &rem_out) {
        string quotient;
        quotient.reserve(num.size());
        int carry = 0;
        for (char c : num) {
            int d = c - '0';
            int cur = carry * 10 + d;
            int q = cur / base;
            carry = cur % base;
            if (!quotient.empty() || q != 0)
                quotient.push_back(char('0' + q));
        }
        rem_out = carry;
        return quotient.empty() ? "0" : quotient;
    }

    string convertToBaseX(const string &decimalStr, int base) {
        if (decimalStr == "0") return "0";
        static const char *digits = "0123456789";
        string n = decimalStr;
        string result;
        while (n != "0") {
            int rem;
            n = divmodString(n, base, rem);
            result.push_back(digits[rem]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
public:

    int countNumbers(string l, string r, int b) {
         string l1 = (l == "0" ? "0" : subtractOne(l));
        string lb = convertToBaseX(l1, b);
        string rb = convertToBaseX(r, b);

        memset(dp, -1, sizeof dp);
        ll cntR = f(rb, 0, 1, b, 0);

        memset(dp, -1, sizeof dp);
        ll cntL = f(lb, 0, 1, b, 0);
        ll ans = (cntR - cntL + MOD) % MOD;
        return int(ans);

        
    }
};