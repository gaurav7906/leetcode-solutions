class Solution {
public:
    bool canAliceWin(int n) {
        int remove =10;
        bool isalice = true;
        while(n>=remove){
            n-=remove;
            remove--;
            isalice=!isalice;
        }
        return !isalice;
    }
};