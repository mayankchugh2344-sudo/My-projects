class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int index) {

        // Base case
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            swap(nums[index], nums[i]);

            solve(nums, index + 1);

            // Backtrack
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        solve(nums, 0);

        return ans;
    }
};