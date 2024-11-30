class Solution {
    struct CompareDescending {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a > b;  // Compare in descending order
    }
};

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<int, set<string>,CompareDescending>mp1;
        unordered_map<string,int> mp2;
        for(int i = 0; i< words.size(); i++)
        {
            int freq = mp2[words[i]];
            if(freq>0)
                mp1[freq].erase(words[i]);
            mp2[words[i]]++;
            mp1[freq+1].insert(words[i]);
        }
        vector<string> res;
        for(auto x: mp1)
        {
            for(auto y : x.second)
            {
                res.push_back(y);
                if(--k==0)
                    return res;
            }
        }return res;

    }
};