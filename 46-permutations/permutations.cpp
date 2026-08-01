class Solution {
public:
    vector<vector<int>> solution;
    void solve(vector<int>& nums, vector<int>& output, int vis[100]) {
        
        if (output.size() == nums.size()) {
            solution.push_back(output);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (vis[i] == 1)
                continue;

            vis[i] = 1;

            output.push_back(nums[i]);
            solve(nums, output, vis);
            output.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) { 
        vector<int> output;
        int vis[6] = {};
        solve(nums, output, vis);

        return solution;
     }
};