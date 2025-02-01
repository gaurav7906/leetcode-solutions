class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int fived=0,tend=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                fived++;
            }
           else if(bills[i]==10)
            {
                if(fived!=0)
                {
                    fived--;
                }
                else
                {
                    return false;
                }
                tend++;
            }
            else if (bills[i]==20)
            {
                if(tend !=0 && fived!=0)
                {
                    tend--;
                    fived--;
                }
                else if (tend==0 && fived>=3)
                {
                    fived-=3;
                }
                else 
                return false;
            }
        }
        return true;
    }
};