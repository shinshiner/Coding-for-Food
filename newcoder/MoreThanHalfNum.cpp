class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        // 哈希法，空间复杂度高，正解可用候选人法，空间复杂度O(1)
        map<int, int> dic;
        int n=numbers.size(), val;
        for(int i=0;i<n;i++){
            val = numbers[i];
            if(!dic.count(val)){dic[val] = 1;}
            else{dic[val]++;}
            if(dic[val] > n/2){return val;}
        }
        return 0;
    }
};