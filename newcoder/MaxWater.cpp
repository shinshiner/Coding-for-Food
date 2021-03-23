class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int>& arr) {
        int lh=0, rh=1, n=arr.size(), max_idx;
        long long ans=0, tmp;
        if(n<3) {return 0;}
        // 双指针。先从左往右扫
        while(rh<n && lh<rh){
            tmp = 0;
            while(rh<n && arr[lh]>arr[rh]){
                tmp += arr[lh] - arr[rh];
                rh++;
            }
            if(rh<n){
                ans += tmp;
                lh = rh;
                rh++;
            }
        }
        // 找出最高点以后从右往左扫
        max_idx = lh;
        rh = n - 1;
        lh = rh - 1;
        while(lh>=max_idx){
            tmp = 0;
            while(lh>=max_idx && arr[rh] > arr[lh]){
                tmp += arr[rh] - arr[lh];
                lh--;
            }
            if(lh>=max_idx){
                ans += tmp;
                rh = lh;
                lh--;
            }
        }
        return ans;
    }
};