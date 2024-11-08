public class Solution {
    public int LargestCombination(int[] candidates) {

        int maxi = 0;
        for(int i = 1; i<= 8388608; i*=2)
        {
            int cnt = 0; 
            for(int j =0; j< candidates.Length; j++)
            {
                if(((candidates[j])&(i)) >0)
                    cnt++;
            }
            maxi = int.Max(cnt, maxi);
        }return maxi;

        
    }
}