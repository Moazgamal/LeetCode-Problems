class Solution {
public:
    int minNumberOperations(vector<int>& target) {

        map<int,vector<int>>mp;
        for(int i = 0; i< target.size(); i++)
        {
            mp[target[i]].push_back(i);
        }
        int ans = 0; 
        set<int>st;
        unordered_map<int,int>mp2;

        for(auto &x: mp)
        {
            int num = x.first; 
            auto &v = x.second;

            int i = 0;
            while(i < v.size())
            {
                int start = v[i];
                int end = start;

                // نجمع متواصلين في target
                while(i+1 < v.size() && v[i+1] == end+1) 
                {
                    i++;
                    end = v[i];
                }
                
                // نحسب الـ discount لهذه القطعة كقطعة واحدة
                int discount = 0;
                
                auto it = st.lower_bound(start);
                if(it != st.end())
                    discount = max(discount, mp2[*it]);
                
                if(it != st.begin()) 
                {
                    auto it2 = prev(it);
                    discount = max(discount, mp2[*it2]);
                }

                if(num - discount > 0)
                    ans += num - discount;

                // نحدّث الـ st و mp2
                for(int k = start; k <= end; k++)
                {
                    st.insert(k);
                    mp2[k] = num;
                }
                i++;
            }
        }
        return ans; 
    }
};
