// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         if (n == 0) return 0; 

//         vector<int> lefty(n, 1);  
//         vector<int> righty(n, 1); 
//         int candi = 0;
//         for (int i = 1; i < n; i++) {
//             if (ratings[i] > ratings[i - 1]) {
//                 lefty[i] = lefty[i - 1] + 1;
//             }
//         }

//         for (int i = n - 2; i >= 0; i--) {
//             if (ratings[i] > ratings[i + 1]) {
//                 righty[i] = righty[i + 1] + 1;
//             }
//         }

//         // Compute the final result
//         for (int i = 0; i < n; i++) {
//             candi += max(lefty[i], righty[i]);
//         }

//         return candi;
//     }
// };
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1;
        int sum=1;
        while(i<n) {
            if(ratings[i]==ratings[i-1]) {
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]) {
                peak+=1;
                i++;
                sum+=peak;
            }
            int down=0;
            while(i<n && ratings[i]<ratings[i-1]) {
                down+=1;
                i++;
                sum+=down;
            }
            down++;
            if(down>peak) {
                sum+=down-peak;
            }
        }
        return sum;
    }
};