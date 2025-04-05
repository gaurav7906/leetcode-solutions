class Solution {
public:
int subsetexor(int index,int exor,vector<int>& nums)
{
    if(index==nums.size())
    return exor;
    int pick=subsetexor(index+1,exor^nums[index],nums);
    int notpick= subsetexor(index+1, exor,nums);
    return pick+notpick;
}
    int subsetXORSum(vector<int>& nums)
     {
        return subsetexor(0,0,nums);
    }
};