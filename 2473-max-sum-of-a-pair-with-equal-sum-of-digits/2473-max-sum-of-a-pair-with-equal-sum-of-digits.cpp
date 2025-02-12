class Solution {
public:
    int getsum(int digit) {
        int sum = 0;
        while (digit != 0) {
            sum += digit % 10;  // Extract last digit and add to sum
            digit /= 10;        // Remove last digit
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1; // Edge case: If there's only one number, no pair exists.

        unordered_map<int, int> sumMap; // Map to store max value for each digit sum
        int maxPairSum = -1;

        for (int i = 0; i < n; i++) {
            int sum = getsum(nums[i]);

            if (sumMap.find(sum) != sumMap.end()) {
                // If a number with the same sum of digits exists, update maxPairSum
                maxPairSum = max(maxPairSum, nums[i] + sumMap[sum]);
            }
            
            // Store the maximum number for this digit sum
            sumMap[sum] = max(sumMap[sum], nums[i]);
        }

        return maxPairSum;
    }
};
