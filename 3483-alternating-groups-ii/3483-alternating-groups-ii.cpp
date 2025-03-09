class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i = 0; 
        int j = 0; 
        int ans = 0 ;
        int sz = colors.size();
        for( ; i < sz; )
        {
            while(i < sz && colors[j%sz]!=colors[(j+1)%sz])
            {
                j++;
                if(j-i+1 == k)
                {
                    ans++; i++;
                }
            }
            j++;
            i = j;
        }return ans; 
    }
};