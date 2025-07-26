class Solution {
    static constexpr double EPS = 1e-6;

    bool tryCalc(vector<int>& v) 
    {
        vector<double> nums(v.begin(), v.end());
        return eval(nums);
    }

    bool eval(vector<double>& nums) 
    {
        if (nums.size() == 1)
            return fabs(nums[0] - 24.0) < EPS;

        for (int i = 0; i < nums.size(); ++i) 
        {
            for (int j = 0; j < nums.size(); ++j) 
            {
                if (i == j) continue;

                vector<double> next;
                for (int k = 0; k < nums.size(); ++k)
                    if (k != i && k != j)
                        next.push_back(nums[k]);

                double a = nums[i], b = nums[j];

                next.push_back(a + b);
                if (eval(next)) return true;
                next.pop_back();

                next.push_back(a - b);
                if (eval(next)) return true;
                next.pop_back();

                next.push_back(a * b);
                if (eval(next)) return true;
                next.pop_back();

                if (fabs(b) > EPS) 
                {
                    next.push_back(a / b);
                    if (eval(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    bool fn(vector<int>& cards, vector<bool>& vis, vector<int>& v) {
        if (v.size() == 4) 
        {
            return tryCalc(v);
        }

        for (int i = 0; i < 4; ++i) 
        {
            if (!vis[i]) 
            {
                vis[i] = true;
                v.push_back(cards[i]);
                if (fn(cards, vis, v)) return true;
                v.pop_back();
                vis[i] = false;
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<bool> vis(4, false);
        vector<int> v;
        return fn(cards, vis, v);
    }
};
