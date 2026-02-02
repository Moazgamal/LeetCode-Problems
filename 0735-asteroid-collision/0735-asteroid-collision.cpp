class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int>st;
        for(int i = 0; i< asteroids.size(); i++)
        {
            if(st.empty() || asteroids[i]>0)
                st.push_back(asteroids[i]);
            else if(asteroids[i]<0)
            {
                while(st.size()>0 && st[st.size()-1]>0 &&
                abs(asteroids[i])>st[st.size()-1])
                    st.pop_back();

                if(st.size() == 0 || st[st.size()-1] < 0)
                    st.push_back(asteroids[i]);
                else if(st[st.size()-1] == abs(asteroids[i]))
                    st.pop_back();
            }
        }
        return st; 
    }
};