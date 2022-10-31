class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(int i = 0; i< nums.size(); i++){
            mp[nums[i]]++;
        }
        int dup = 0;
        for(auto it: mp){
            if(it.second > 1){
                dup = it.first;
                break;
            }
        }
        return dup;
    }
};


//TC : O(N)
//SC : O(N)
