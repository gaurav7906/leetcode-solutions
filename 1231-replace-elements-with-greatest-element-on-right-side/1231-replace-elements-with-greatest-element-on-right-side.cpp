class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> greater(n, -1);
        if (n == 1) return greater;
        int lastgreatest = arr[n - 1];
        greater[n - 2] = lastgreatest;
        lastgreatest=max(lastgreatest,arr[n-2]);
        for (int i = n - 3; i >= 0; i--) {
             greater[i] = lastgreatest;
            if (arr[i] > lastgreatest) {
                lastgreatest = arr[i];
            }
           
        }
        return greater;
    }
};
