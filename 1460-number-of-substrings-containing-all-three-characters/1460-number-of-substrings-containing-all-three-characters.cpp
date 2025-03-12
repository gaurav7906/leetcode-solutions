class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.length();
        int lastseen[3] = {-1, -1, -1};  
        int count = 0;

        for (int i = 0; i < n; i++) 
        {
            if (s[i] == 'a') 
                lastseen[0] = i;
            else if (s[i] == 'b') 
                lastseen[1] = i;
            else if (s[i] == 'c') 
                lastseen[2] = i;
            if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) 
            {
                count += 1 + min(lastseen[0], min(lastseen[1], lastseen[2]));
            }
        }

        return count;
    }
};
