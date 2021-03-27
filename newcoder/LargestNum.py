#
# 最大数
# @param nums int整型一维数组 
# @return string字符串
#
class Solution:
    def solve(self , nums ):
        # 把数组元素按照字符串顺序排序
        ans = ''
        for i in range(len(nums)):
            for j in range(len(nums)-i-1):
                a = str(nums[j]) + str(nums[j+1])
                b = str(nums[j+1]) + str(nums[j])
                if a < b:
                    nums[j], nums[j+1] = nums[j+1], nums[j]
        for i in range(len(nums)):
            ans += str(nums[i])
        if ans[0] == '0':
            return '0'
        return ans