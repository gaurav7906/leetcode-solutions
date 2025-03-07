class Solution {
public:
    bool isprime(int num) {
        if (num <= 1)
         return false;
        if (num == 2 || num == 3) 
        return true;
        if (num % 2 == 0 || num % 3 == 0) 
        return false;   
        for (int i = 5; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;  
        for (int i = left; i <= right; i++) {
            if (isprime(i)) {
                primes.push_back(i);
            }
        }   
        if (primes.size() < 2) {
            return {-1, -1};
        }
        int mindiff = INT_MAX;
        vector<int> ans(2, -1);
        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < mindiff) {
                mindiff = diff;
                ans = {primes[i], primes[i + 1]};
            }
        }
        return ans;
    }
};
