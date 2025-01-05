class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        map<int,int>mp;
        for(int i = 0; i< shifts.size(); i++)
        {
            int start = shifts[i][0];
            int end = shifts[i][1];
            if(shifts[i][2] == 0)
            {
                mp[start]--;
                mp[end+1]++;
            }
            else
            {
                mp[start]++;
                mp[end+1]--;
            }
        }
        int prefix =0;
        for(int i =0; i< s.size(); i++)
        {
            prefix = (prefix + mp[i]) %
                             26;  // Update cumulative shifts, keeping within
                                  // the alphabet range.
            
            if (prefix < 0)
                prefix +=
                    26;  // Ensure `numberOfShifts` is non-negative.
            cout<<prefix<<" "<<s[i]-'a'<<"\n";
            s[i] = 'a' + (s[i] - 'a' + prefix) % 26;
        }return s;
    }
};