class Solution {
    class node{
        public:
        int idx;
        long long val;
        node* next{};
        node* prev{};
    };  
public:
    int minimumPairRemoval(vector<int>& nums) {
        unordered_map<int,long long>sumOfindex;
        unordered_map<int,node*>nodeOfIndex;
        map<long long, set<int>>indicesOfSum;
        unordered_map<int,bool>mp;
        node* prev = nullptr;
        for(int i = 0; i< nums.size()-1; i++)
        {
            sumOfindex[i] = nums[i] + nums[i+1];
            indicesOfSum[nums[i] + nums[i+1]].insert(i);
            node* cur = new node();
            cur->idx = i; cur->val = nums[i]; cur->prev = prev;
            if(prev)
                prev->next = cur; 
            nodeOfIndex[i] = cur;
            prev = cur;
            if(nums[i]>nums[i+1])
                mp[i]=true;
        }
        node* cur = new node();
        cur->idx = nums.size()-1;
        cur->prev = prev;
        cur->val = nums[nums.size()-1];
        if(prev)
            prev->next = cur;
        nodeOfIndex[nums.size()-1]=cur;
        if(mp.size() == 0)
            return 0; 
        int cnt = 0; 
        while(!indicesOfSum.empty() && !mp.empty())
        {
            auto it = indicesOfSum.begin(); 
            int j = *(it->second.begin());   
            long long curSum = it->first;
            
            node* curPtr = nodeOfIndex[j];

            curSum = sumOfindex[j];

            indicesOfSum[curSum].erase(j);
            if(indicesOfSum[curSum].empty())
                indicesOfSum.erase(curSum);

            if(curPtr->prev)
            {
                int prevIdx = curPtr->prev->idx;
                long long oldSum = sumOfindex[prevIdx];
                indicesOfSum[oldSum].erase(prevIdx);
                if(indicesOfSum[oldSum].empty())
                    indicesOfSum.erase(oldSum);
                if(curPtr->prev->val > curSum)
                    mp[prevIdx] = true;
                else
                {
                    if(mp.count(prevIdx) >0)
                        mp.erase(prevIdx);
                }
                long long newSum = curSum + curPtr->prev->val;
                indicesOfSum[newSum].insert(prevIdx);
                sumOfindex[prevIdx] = newSum;
            }
            node* nextNode = curPtr->next;
           
            node* nextNext = nextNode->next;
            long long nextSum = sumOfindex[nextNode->idx];
            if(mp.count(nextNode->idx)>0)
                mp.erase(nextNode->idx);

            indicesOfSum[nextSum].erase(nextNode->idx);
            if(indicesOfSum[nextSum].empty())
                indicesOfSum.erase(nextSum);

            curPtr->val = curSum;
            curPtr->next = nextNext;
            if(curPtr->next)
            {
                if(curSum > curPtr->next->val)
                    mp[curPtr->idx]=true;
                else
                {
                    if(mp.count(curPtr->idx)>0)
                        mp.erase(curPtr->idx);
                }
                
                indicesOfSum[curSum+curPtr->next->val].insert(curPtr->idx);
                sumOfindex[curPtr->idx] = curSum+curPtr->next->val;
                curPtr->next->prev = curPtr;
            }
            else
            {
                if(mp.count(curPtr->idx) > 0)
                    mp.erase(curPtr->idx);
                
                sumOfindex[curPtr->idx] = curSum;
            }
            cnt++;
        }
        return cnt; 
    }
};