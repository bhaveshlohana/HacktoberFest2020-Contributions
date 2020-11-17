/*
Combination Sum II
https://leetcode.com/problems/combination-sum-ii/
*/

void helper(vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans, int index, int target) {
        if (target == 0) {
            ans.emplace_back(cur);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            if (nums[i] > target) {
                break;
            }
            if (index < i && nums[i-1] == nums[i]) {
                continue;
            }
            cur.emplace_back(nums[i]);
            helper(nums, cur, ans, i + 1, target - nums[i]);
            cur.pop_back();
        }
    }
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> cur;
    sort(begin(candidates), end(candidates));
    helper(candidates, cur, ans, 0, target);
    return ans;
}
