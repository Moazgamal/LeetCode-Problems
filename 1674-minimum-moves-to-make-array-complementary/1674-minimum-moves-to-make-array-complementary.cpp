#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ordered_multiset = tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

class Solution {
    void fn1(vector<int>&v, ordered_multiset &minis1, ordered_multiset &minis2, 
    ordered_multiset &minis3, ordered_multiset &minis4, int &i, int &limit,
    unordered_map<int,int> &CountMinis1,
    unordered_map<int,int> &CountMinis2,
    unordered_map<int,int> &CountMinis3,
    unordered_map<int,int> &CountMinis4)
    {
        for(auto &x: v)
        {
            if(i < limit)
            {
                auto it = minis1.find({x, CountMinis1[x]});
                if (it != minis1.end())
                    minis1.erase(it);
                CountMinis1[x]--;
            }
            else if(i == limit)
            {
                auto it = minis2.find({x, CountMinis2[x]});
                if (it != minis2.end())
                    minis2.erase(it);
                CountMinis2[x]--;
            }
            else if(i > limit && i != 2*limit)
            {
                auto it = minis3.find({x, CountMinis3[x]});
                if (it != minis3.end())
                {
                    minis3.erase(it);
                }
                CountMinis3[x]--;
            }
            else
            {
                auto it = minis4.find({x, CountMinis4[x]});
                if (it != minis4.end())
                    minis4.erase(it);
                CountMinis4[x]--;
            }
        }
    }
    void fn2(vector<int>&v, ordered_multiset &maxis1, ordered_multiset &maxis2, 
    ordered_multiset &maxis3, ordered_multiset &maxis4, int &i, int &limit,
    unordered_map<int,int> &CountMaxis1,
    unordered_map<int,int> &CountMaxis2,
    unordered_map<int,int> &CountMaxis3,
    unordered_map<int,int> &CountMaxis4)
    {
        for(auto &x: v)
        {
            if(i < limit)
            {
                CountMaxis1[x]++;
                maxis1.insert({x, CountMaxis1[x]});
            }
            else if(i == limit)
            {
                CountMaxis2[x]++;
                maxis2.insert({x, CountMaxis2[x]});
            }
            else if(i > limit && i != 2*limit)
            {
                CountMaxis3[x]++;
                maxis3.insert({x, CountMaxis3[x]});
            }
            else
            {
                CountMaxis4[x]++;
                maxis4.insert({x, CountMaxis4[x]});
            }
        }
    }
public:
    int minMoves(vector<int>& nums, int limit) {

        unordered_map<int,bool>mp;

        ordered_multiset maxis1; ordered_multiset minis1;
        ordered_multiset maxis2; ordered_multiset minis2;
        ordered_multiset maxis3; ordered_multiset minis3;
        ordered_multiset maxis4; ordered_multiset minis4;

        unordered_map<int,int>CountMinis1; unordered_map<int,int>CountMaxis1;
        unordered_map<int,int>CountMinis2; unordered_map<int,int>CountMaxis2;
        unordered_map<int,int>CountMinis3; unordered_map<int,int>CountMaxis3;
        unordered_map<int,int>CountMinis4; unordered_map<int,int>CountMaxis4;

        unordered_map<int,vector<int>>maxiis;
        unordered_map<int,vector<int>>miniis;

        int CountTwoLimits = 0;
        int CountTwoLimits2 = 0; 

        for(int i = 0; i< nums.size()/2; i++)
        {
            int curSum = nums[i]+nums[nums.size()-1-i];

            mp[curSum]=true;

            int maxi = max(nums[i],nums[nums.size()-1-i]);
            int mini = min(nums[i],nums[nums.size()-1-i]);

            if(curSum < limit)
            {
                CountMinis1[mini]++;
                minis1.insert({mini, CountMinis1[mini]});
            }
            else if(curSum == limit)
            {
                CountMinis2[mini]++;
                minis2.insert({mini, CountMinis2[mini]});
            }
            else if(curSum > limit && curSum != 2*limit)
            {
                CountMinis3[mini]++;
                minis3.insert({mini, CountMinis3[mini]});
                if(maxi == limit)
                    CountTwoLimits2++;
            }
            else
            {
                CountMinis4[mini]++;
                minis4.insert({mini, CountMinis4[mini]});
                if(maxi == limit)
                    CountTwoLimits++;
            }

            maxiis[curSum].push_back(maxi);
            miniis[curSum].push_back(mini);
        }

        int ans = INT_MAX;

        vector<int>sums;

        for(int i = 2; i<=2*limit; i++)
        {
            
            if(mp.count(i) != 0)
            {
                fn1(miniis[i], minis1, minis2, minis3, minis4, i, limit,
                CountMinis1, CountMinis2, CountMinis3, CountMinis4);
                if(i < limit)
                {
                    int less1 = minis1.order_of_key({i,-1});        // عدد العناصر < x
                    int greater_equal1 = minis1.size() - less1; // عدد العناصر ≥ x

                    int less2 = minis2.order_of_key({i,-1});
                    int greater_equal2 = minis2.size()- less2;

                    int less3 = minis3.order_of_key({i,-1});
                    int greater_equal3 = minis3.size()-less3;

                    int less4 = minis4.order_of_key({i,-1});
                    int greater_equal4 = minis4.size()-less4;

                    int collect = maxis1.size() + less1 + less2 + less3 + less4
                    +(2*greater_equal1) + (2*greater_equal2) + (2*greater_equal3)
                    +(2*greater_equal4);
                    ans = min(ans, collect);
                }
                else if(i == limit)
                {
                    int collect = maxis1.size() + minis3.size() + (int)minis4.size()*2;
                    ans = min(ans, collect);
                   
                }
                else if(i > limit && i != 2*limit)
                {
                    int less1 = maxis1.order_of_key({i-limit,-1});        // عدد العناصر < x
                    int greater_equal1 = maxis1.size() - less1; // عدد العناصر ≥ x

                    int less2 = maxis2.order_of_key({i-limit,-1});
                    int greater_equal2 = maxis2.size()- less2;

                    int less3 = maxis3.order_of_key({i-limit,-1});
                    int greater_equal3 = maxis3.size()-less3;

                    int x = (int)minis4.size()-CountTwoLimits;

                    int collect = greater_equal1 + greater_equal2 + greater_equal3
                    +(2*less1)+(2*less2)+(2*less3) + minis3.size()+ CountTwoLimits + 
                    (2*x);

                    ans = min(ans, collect);
                }
                else
                {
                    int x = (int)maxis3.size()-CountTwoLimits2;
                    int collect = maxis1.size()*2 + maxis2.size()*2 + CountTwoLimits2 + (2*x);
                    ans = min(ans, collect);
                }
                fn2(maxiis[i], maxis1, maxis2, maxis3, maxis4, i, limit,
                CountMaxis1, CountMaxis2, CountMaxis3, CountMaxis4);
            }
            else
            {
                if(i < limit)
                {
                    int less1 = minis1.order_of_key({i,-1});        // عدد العناصر < x
                    int greater_equal1 = minis1.size() - less1; // عدد العناصر ≥ x

                    int less2 = minis2.order_of_key({i,-1});
                    int greater_equal2 = minis2.size()- less2;

                    int less3 = minis3.order_of_key({i,-1});
                    int greater_equal3 = minis3.size()-less3;

                    int less4 = minis4.order_of_key({i,-1});
                    int greater_equal4 = minis4.size()-less4;

                    int collect = maxis1.size() + less1 + less2 + less3 + less4
                    +(2*greater_equal1) + (2*greater_equal2) + (2*greater_equal3)
                    +(2*greater_equal4);
                    ans = min(ans, collect);
                }
                else if(i == limit)
                {
                    int collect = maxis1.size() + minis3.size() + minis4.size();
                    ans = min(ans, collect);
                }
                else if(i > limit && i != 2*limit)
                {
                    int less1 = maxis1.order_of_key({i-limit,-1});        // عدد العناصر < x
                    int greater_equal1 = maxis1.size() - less1; // عدد العناصر ≥ x

                    int less2 = maxis2.order_of_key({i-limit,-1});
                    int greater_equal2 = maxis2.size()- less2;

                    int less3 = maxis3.order_of_key({i-limit,-1});
                    int greater_equal3 = maxis3.size()-less3;

                    int x = (int)minis4.size()-CountTwoLimits;

                    int collect = greater_equal1 + greater_equal2 + greater_equal3
                    +(2*less1)+(2*less2)+(2*less3) + minis3.size()+ CountTwoLimits + 
                    (2*x);
                    ans = min(ans, collect);
                }
                else
                {
                    int x = (int)maxis3.size()-CountTwoLimits2;
                    int collect = maxis1.size()*2 + maxis2.size()*2 + CountTwoLimits2 + (2*x);
                    ans = min(ans, collect);
                }
            }
        }   
        return ans; 
    }
};