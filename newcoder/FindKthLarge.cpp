class Solution {
public:
    int getIdx(vector<int>& a, int lh, int rh){
        int idx = lh, tmp = a[lh];
        while(lh<rh){
            while(lh<rh && a[rh]<=tmp){rh--;}
            a[lh] = a[rh];
            while(lh<rh && a[lh]>=tmp){lh++;}
            a[rh] = a[lh];
        }
        a[lh] = tmp;
        return lh;
    }
    
    // 快速排序思路，每次选一个基准点，把数组分成左边小于基准，右边大于，然后把index和K比较，对左或者右继续分
    int findKth(vector<int> a, int n, int K) {
        int lh=0, rh=n-1, idx=getIdx(a, lh, rh), tmp;
        while(lh<rh && idx-lh+1 != K){
            if(idx-lh+1>K){
                rh = idx - 1;
                idx = getIdx(a, lh, rh);
            }
            else{
                K -= idx - lh + 1;
                lh = idx + 1;
                idx = getIdx(a, lh, rh);
            }
        }
        return a[idx];
    }
};