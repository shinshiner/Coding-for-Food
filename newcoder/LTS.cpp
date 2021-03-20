#include<algorithm>
using namespace std;

class Solution {
public:
    /**
     * retrun the longest increasing subsequence
     * @param arr int整型vector the array
     * @return int整型vector
     */
    vector<int> LIS(vector<int>& arr) {
        // write code here
        int n = arr.size(), pos;
        vector<int> dp, idxs(n, 0);
        dp.push_back(arr[0]);
        
        // get dp array and index array by bisect
        for(int i=1;i<n;i++){
            if(arr[i] > dp.back()){
                idxs[i] = dp.size();
                dp.push_back(arr[i]);
            }
            else{
                pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin(); // bisect: first element larger than arr[i]
                dp[pos] = arr[i];
                idxs[i] = pos;
            }
        }
        
        // traverse the two array to get the sequence (from tail to head)
        int length = dp.size(), start = n-1;
        vector<int> ans(length, 0);
        for(int i=n-1, j=length-1; i>=0; i--){
            if(idxs[i] == j){ans[j] = arr[i]; j--;}
        }
        
        return ans;
    }
};