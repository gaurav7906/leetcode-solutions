class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int right=1;
        int left=0;
        int result=0;
        int n=colors.size();
        while(right<colors.size()){
            if(colors[right]==colors[right-1]){
                left=right;
                right++;
                continue;
            }
            else if(right-left+1==k){
                result+=1;
                left+=1;
            }
            right+=1;
        }
        return result;
    }
};