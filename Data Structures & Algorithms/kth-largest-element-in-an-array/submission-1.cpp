class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target_index = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, target_index);
    }
private:
    int quickSelect(vector<int>& nums, int left, int right, int target_index) {
        int pivot = nums[right];
        int p = left;
        
        for (int i = left; i < right; i++) {
            if (nums[i] <= pivot) {
                swap(nums[p], nums[i]);
                p++;
            }
        }
     
        swap(nums[p], nums[right]);
        
        if (p == target_index) {
            return nums[p];
        } else if (p < target_index) {
            return quickSelect(nums, p + 1, right, target_index);
        } else {
            return quickSelect(nums, left, p - 1, target_index);
        }
    }
};
