class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        vector<int> element;
        int pre=-1002333, cur, lh, rh, n=num.size();
        
        // 先排序，然后对每个元素转化成二数求和的问题
        // 二数求和用双指针，初始化左边是当前待查找的元素num[i]，右边是数组末尾
        // 移动指针时注意去重
        for(int i=0;i<n;i++){
            if(pre==num[i]){continue;}
            lh = i + 1;
            rh = n - 1;
            while(lh < rh){
                if(num[i]+num[lh]+num[rh]==0){
                    element.push_back(num[i]);
                    element.push_back(num[lh]);
                    element.push_back(num[rh]);
                    ans.push_back(element);
                    element.clear();
                    
                    cur = num[lh];
                    while(lh < rh && num[lh]==cur) {lh++;}
                    cur = num[rh];
                    while(lh < rh && num[rh]==cur) {rh--;}
                }
                else{
                    if(num[i]+num[lh]+num[rh]<0){
                        cur = num[lh];
                        while(lh < rh && num[lh]==cur) {lh++;}
                    }
                    else{
                        cur = num[rh];
                        while(lh < rh && num[rh]==cur) {rh--;}
                    }
                }
            }
            pre = num[i];
        }
        
        return ans;
    }
};