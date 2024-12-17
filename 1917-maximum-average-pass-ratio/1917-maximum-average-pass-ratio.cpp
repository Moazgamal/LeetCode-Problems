class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<pair<pair<double,int>,pair<int, int>>> pq;
        int sz = classes.size();
        int j = 0; 
        for(const auto& singleClass : classes)
        {
            double first = ((double)singleClass[0]/singleClass[1]);
            double second = ((double)(singleClass[0]+1)/(singleClass[1]+1));
            double diff = second-first;
            pq.push({{diff,j}, {singleClass[0],singleClass[1]}});
            j++;
        }
        while(extraStudents-- > 0)
        {
            auto cur = pq.top(); 
            pq.pop();
            int first = cur.second.first + 1;
            int second = cur.second.second +1;
            int idx = cur.first.second;
            int newFirst = first+1;
            int newSecond = second+1;
            double diff1 = (double)first/second;
            double diff2 = ((double)newFirst/newSecond);
            classes[idx][0]++;
            classes[idx][1]++;
            pq.push({{(diff2-diff1),idx}, {first,second}});
        }
        double ans =0;
        int m = 0; 
        while(m<classes.size())
        {
            ans += (double)(classes[m][0])/classes[m][1];
            m++;
        }return ans/sz;

        
    }
};