class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        vector<vector<char>> result(box[0].size(), vector<char>(box.size(),'.'));
        int rows = box[0].size();
        int cols = box.size();
        for(int r=0; r< box.size(); r++)
        {
            int cnt = 0; 
            for(int c = 0; c<box[0].size(); c++)
            {
                if(box[r][c]=='#')
                    cnt++;
                if(box[r][c] == '*')
                {
                    result[c][(cols-r)-1]='*';
                    int j = 1;
                    while(cnt>0)
                    {
                        result[c-j][(cols-r)-1]= '#';
                        j++; cnt--;
                    }
                }
            }
            int j =1;
            while(cnt>0)
            {
                result[rows-j][(cols-r)-1]= '#';
                j++;cnt--;
            }
        }return result;
        
    }
};