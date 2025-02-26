class Solution {
public:
    typedef pair<int,int>p;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<p, vector<p>, greater<p>> pq;
        for(auto&it:nums){
            mp[it]++;
        }
        for(auto&it:mp){
            int freq=it.second;
            int val=it.first;
            pq.push({freq,val});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            int element=pq.top().second;
            ans.push_back(element);
            pq.pop();
        }
        return ans;
    }
};