class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int>st;
        vector<int>result(nums1.size());
        unordered_map<int,int>mp;
        for(int i = 0; i< nums2.size(); i++)
        {
            mp[nums2[i]]= i;
            if(st.empty())
            {
                st.push(i); continue;
            }
            while(!st.empty() && nums2[i] > nums2[st.top()])
            {
                nums2[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            nums2[st.top()] = -1; st.pop();
        }
        for(int i = 0; i< nums1.size(); i++)
        {
            result[i] = nums2[mp[nums1[i]]];
        }return result;

        
    }
};