public class Solution {
    public int[] PlusOne(int[] digits) {

        int carry = 1; 
        for(int i = digits.Length-1; i>=0; i--)
        {
           int coll = digits[i] + carry;
           carry = coll / 10; 
           digits[i] = coll %10;
        }
        List<int>ans=new List<int>();
        if(carry > 0)
            ans.Add(carry);
        for(int i = 0; i< digits.Length; i++)
        {
            ans.Add(digits[i]);
        }
        return ans.ToArray(); 
        
    }
}