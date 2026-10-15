class Solution {
public:
    bool threeFibonacciSum(int n) {
        int i = 0;
	   int j = 1;
//	   int acc = i+j;
	   int cnt = 0;
	   int temp = j;
       long long curVal = 0;
	   while(j <= 1e9)
	   {
//		   acc = i+j;

		   j = i+j;
           curVal = (long long)j+i+temp;
		   i = temp;
           if(curVal == n)
            return true;
		   temp =j;
		   cnt++;
	   }

       return false;
        
    }
};