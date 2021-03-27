class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    void quickSort(vector<int> &arr, int lh, int rh){
        if(lh>=rh) {return;}
        int tmp=arr[lh], l=lh, r=rh;
        while(lh<rh){
            while(lh<rh && arr[rh]>=tmp) {rh--;}
            if(lh<rh){
                arr[lh] = arr[rh];
                lh++;
            }
            while(lh<rh && arr[lh]<=tmp) {lh++;}
            if(lh<rh){
                arr[rh] = arr[lh];
                rh--;
            }
        }
        arr[lh] = tmp;
        quickSort(arr, l, lh-1);
        quickSort(arr, lh+1, r);
    }
    
    vector<int> MySort(vector<int>& arr) {
        quickSort(arr, 0, arr.size()-1);
        return arr;
    }
};