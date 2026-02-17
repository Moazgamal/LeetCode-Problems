class Solution {
    void fn(string partOne, int sz2 , vector<string>&ans)
    {
        if(sz2 >= 6)
            return;
        if(sz2 == 0)
        {
            ans.push_back(partOne+"00");
            return;
        }
        else if(sz2 == 1)
        {
            ans.push_back(partOne+"01");
            cout<<partOne+"01"<<"\n";
            ans.push_back(partOne+"02");
            cout<<partOne+"02"<<"\n";
            ans.push_back(partOne+"04");
            cout<<partOne+"04"<<"\n";
            ans.push_back(partOne+"08");
            cout<<partOne+"08"<<"\n";
            ans.push_back(partOne+"16");
            cout<<partOne+"16"<<"\n";
            ans.push_back(partOne+"32");
            cout<<partOne+"32"<<"\n";
            cout<<" fffff\n";
        }
        else if(sz2 == 2)
        {
            for(int i = 0; i<=4; i++)
            {
                int num1 = (1<<i);
                for(int j = i+1; j<= 5; j++)
                {
                    int num2 = (1<<j);
                    if(num1+num2<=59)
                    {
                        string x = to_string(num1+num2);
                        if(x.size() == 1)
                            ans.push_back(partOne+"0"+x);
                        else
                            ans.push_back(partOne+x);
                    }
                }
            }
        }
        else if(sz2 == 3)
        {
            for(int i = 0; i<=4; i++)
            {
                int num1 = (1<<i);
                for(int j = i+1; j<= 4; j++)
                {
                    int num2 = (1<<j);
                    for(int k = j+1; k<=5; k++)
                    {
                        int num3 = (1<<k);
                        if(num1+num2+num3<=59)
                        {
                            string x = to_string(num1+num2+num3);
                            if(x.size() == 1)
                                ans.push_back(partOne+"0"+x);
                            else
                                ans.push_back(partOne+x);
                        }
                    }
                }
            }
        }
        else if(sz2 == 4)
        {
            for(int i = 0; i<=2; i++)
            {
                int num1 = (1<<i);
                for(int j = i+1; j<= 3; j++)
                {
                    int num2 = (1<<j);
                    for(int k = j+1; k<=4; k++)
                    {
                        int num3 = (1<<k);
                        for(int u = k+1; u <= 5; u++)
                        {
                            int num4 = (1<<u);
                            if(num1+num2+num3+num4<=59)
                            {
                                string x = to_string(num1+num2+num3+num4);
                                if(x.size() == 1)
                                    ans.push_back(partOne+"0"+x);
                                else
                                    ans.push_back(partOne+x);
                            }
                        }
                    }
                }
            }
        }
        else if(sz2 == 5)
        {
            for(int i = 0; i<=1; i++)
            {
                int num1 = (1<<i);
                for(int j = i+1; j<= 2; j++)
                {
                    int num2 = (1<<j);
                    for(int k = j+1; k<=3; k++)
                    {
                        int num3 = (1<<k);
                        for(int u = k+1; u <= 4; u++)
                        {
                            int num4 = (1<<u);
                            for(int y = u+1; y<=5; y++)
                            {
                                int num5 = (1<<y);
                                if(num1+num2+num3+num4+num5<=59)
                                {
                                    string x = to_string(num1+num2+num3+num4+num5);
                                    if(x.size() == 1)
                                        ans.push_back(partOne+"0"+x);
                                    else
                                        ans.push_back(partOne+x);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        int i = 0;
        vector<string>ans;
        while(i<=turnedOn)
        {
            int sz1 = i; 
            int sz2 = turnedOn-i;
            
            if(sz1 == 0)
                fn("0:", sz2, ans); 
            else
            {
                if(sz1 == 1)
                {
                    fn("1:", sz2, ans);
                    fn("2:", sz2, ans);
                    fn("4:", sz2, ans);
                    fn("8:", sz2, ans);
                }
                else if(sz1 == 2)
                {
                    fn("3:", sz2,ans); fn("6:", sz2, ans);
                    fn("5:", sz2, ans); fn("10:", sz2, ans);
                    fn("9:", sz2, ans); 
                } 
                else if(sz1 == 3)
                {
                    fn("7:", sz2, ans);
                    fn("11:", sz2, ans);
                }
                
            }
            i++;
        }
        return ans; 
    }
};