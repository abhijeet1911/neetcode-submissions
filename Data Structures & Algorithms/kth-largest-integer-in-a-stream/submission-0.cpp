class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k_limit;

public:
    KthLargest(int k, vector<int>& nums) {
        k_limit = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        
        if (min_heap.size() > k_limit) {
            min_heap.pop();
        }
        
        return min_heap.top();
    }
};
