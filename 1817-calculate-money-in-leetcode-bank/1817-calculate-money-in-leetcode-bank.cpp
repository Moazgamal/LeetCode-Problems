class Solution {
public:
    int totalMoney(int n) {

        if(n <= 7)
        {
            return n *(1+n)/2;
        }
        int sum =0;
        int loops = n/7;
        int reminder = n - 7*loops;
        int a1 = 1;
        int a2 = 7;
        int value = 7 *(1 + 7)/2;
        int v = loops-1;
        sum += (loops*value) + 7*v*(v+1)/2;
        /*while(loops--)
        {
          sum += 7 *(a1++ + a2++)/2;
        }
        */
        a1 = loops + 1;
        a2 = a1 + reminder -1;
        sum += reminder *(a1 + a2)/2;
        return sum;

        
    }
};