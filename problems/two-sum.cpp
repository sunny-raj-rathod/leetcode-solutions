class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        map<int, int> hashMap;
        for(int i=0;i<nums.size();++i)
        {
            if(hashMap.find(nums[i]) != hashMap.end())
            {
                solution.push_back(hashMap[nums[i]]);
                solution.push_back(i);
                return solution;
            }
            else
            {
                hashMap[target - nums[i]] = i;
            }
        }
        return solution;
    }
};
