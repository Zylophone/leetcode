class Solution {
    
    int kthSmallest(vector<int>& arr, int l, int r, int k)
    {

        if (k > 0 && k <= r - l + 1)
        {
            int pos = randomPartition(arr, l, r);
        
            if (pos-l == k-1)
                return arr[pos];
            else if(pos-l > k-1)
                return kthSmallest(arr, l, pos-1, k);
            else
                return kthSmallest(arr, pos+1, r, k-pos+l-1);
        }
        return INT_MAX;
    }

    int partition(vector<int>& arr, int l, int r)
    {
        int x = arr[r], i = l;
        for(int j = l; j <= r - 1; j++)
        {
            if (arr[j] <= x)
            {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[r]);
        return i;
    }

    int randomPartition(vector<int>& arr, int l, int r)
    {
        int n = r-l+1;
        int pivot = rand() % n;
        swap(arr[l + pivot], arr[r]);
        return partition(arr, l, r);
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        return kthSmallest(nums, 0, nums.size()-1, nums.size()-k+1);
    }
};