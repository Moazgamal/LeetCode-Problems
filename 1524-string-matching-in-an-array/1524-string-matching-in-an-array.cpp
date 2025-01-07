class Solution {
    vector<int> computePrefix(string &pattern)
{
    vector<int> lps(pattern.size());
	int m = pattern.length();
    int length = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;     // LPS[0] is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
    bool KMP(string &text, string &pattern, vector<int> &lps)
{
	int n = text.length();
    int m = pattern.length();

    // Create LPS array for the pattern
    int i = 0; // Index for text
    int j = 0; // Index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            return true;
            j = lps[j - 1]; // Move to the next possible match
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
return false;
}
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        vector<vector<int>> p (words.size());
        for(int i = 0; i< words.size(); i++)
        {
            p[i] = computePrefix(words[i]);
        }
        for(int i = 0; i< words.size(); i++)
        {
            for(int j = 0; j< words.size(); j++)
            {
                if(j == i)
                    continue;
                
                if(KMP(words[j], words[i], p[j]))
                {
                    ans.push_back(words[i]); break;
                }
            }
        }return ans;
    }
};