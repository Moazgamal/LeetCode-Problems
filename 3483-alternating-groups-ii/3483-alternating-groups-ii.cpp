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
                    cout<<j<<" j "<<i<<"\n";
                    ans++; i++;
                }
            }
            i = j+1;
            j=j+1;
        }return ans; 
    }
};