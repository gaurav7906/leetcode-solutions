
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int count = 0;

        while (!pq.empty()) {
            long long smallest = pq.top();
            pq.pop();

            if (smallest >= k) {
                break;
            }

            if (pq.empty()) {
                return count; // If only one element is left and it's < k, we cannot proceed
            }

            long long secondSmallest = pq.top();
            pq.pop();

            long long newValue = 2 * smallest + secondSmallest;
            pq.push(newValue);
            count++;
        }

        return count;
    }
};