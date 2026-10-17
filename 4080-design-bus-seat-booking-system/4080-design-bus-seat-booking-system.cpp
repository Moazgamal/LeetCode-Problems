class BusBooking {
public:
int total = 0; int mini = 0; 
vector<vector<int>>v;
    BusBooking(int n) 
    {
        vector<vector<int>>x(n+1, vector<int>(4, 0));
        v = x;
    }
    
    void toggle(string seat) 
    {
        
        int x = stoi(seat.substr(1, seat.size()-1));
        // cout<<x<<" x\n";
        int i = seat[0]-'A';
        // cout<<seat<<" "<<i<<" i\n";
        if(v[x][i] == 0)
        {
            mini++;
            if(i == 1 || i == 2)
            {
                v[x][i]++;total++;
            }
            else if(i == 0)
            {
                if(v[x][1] >0)
                {
                    v[x][0] = 3; total+=3;
                }
                else
                {
                    v[x][0] = 1; total++;
                }
            }
            else if(i == 3)
            {
                if(v[x][2] > 0)
                {
                    v[x][3] = 3; total+=3;
                }
                else
                {
                    v[x][3]++; total++;
                }
            }
        }
        else
        {
            if(i == 1 || i == 2)
            {
                total--; v[x][i] = 0;
            }
            else
            {
                total -= v[x][i]; v[x][i] = 0; 
            }
            mini--;
        }
        // cout<<total<<" total\n";
        // v[x][i] = v[x][i] == true ? v[x][i] = false: v[x][i] = true;
    }
    
    int getTotalTime() {
        return total;
    }
    
    int getMinTime() {
        return mini;
    }
    
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */