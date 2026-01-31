class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int start = 0; int end = letters.size()-1;
        int mid = -1; int pos = -1;
        while(start <= end)
        {
            mid = start + (end - start)/2;
            if(letters[mid] <= target)
                start = mid + 1;
            else
            {
                pos = mid;
                end = mid - 1; 
            }
        }
        if(pos == -1)
            return letters[0];
        return letters[pos];
    }
};