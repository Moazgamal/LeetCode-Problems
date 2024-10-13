class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        map<int,set<int,greater<int>>, greater<int>> mp;
        unordered_map<int,int>mp2;
        int j = 0;
        vector<int>ans;
        for(int end = 0; end< nums.size() && j<=nums.size()-k; end++)
        {
            int freq = ++mp2[nums[end]];
            if(freq == 1)
            {
                mp[freq].insert(nums[end]);
            }
            else
            {
                mp[freq].insert(nums[end]);
                mp[freq-1].erase(nums[end]); 
                if(mp[freq-1].size()==0)
                {
                    mp.erase(freq-1);
                }
            }
            if(end-j+1 == k)
            {
                int sum = 0;
                if(mp.size()>=x)
                {
                    int cnt = 0;
                    for(auto f : mp)
                    {
                        int c = f.first;
                        for(auto p : f.second)
                        {
                            if(cnt == x)
                                break;
                            sum+=(p*c);
                            cnt++;
                        }
                    }
                    cout<<sum<<" ";
                    ans.push_back(sum);
                }
                else
                {
                    int cnt = 0;
                    for(auto f: mp)
                    {
                        int c = f.first;
                        for(auto p : f.second)
                        {
                            if(cnt==x)
                                break;
                            sum+=(p*c);
                            cnt++;

                        }
                    }
                    cout<<sum<<" **";
                    ans.push_back(sum);
                }
                int u = nums[j];
                int freq2 = mp2[u];
                mp[freq2].erase(u);
                if(mp[freq2].size()==0)
                    mp.erase(freq2);
                mp2[u]--;
                if(mp2[u] >0)
                    mp[mp2[u]].insert(u);
                sum=0;
                j++;
                
            }



        }
        return ans;
        
    }
};