class Solution(object):
    def twoSum(self, nums, target):
        dic = {}
        res = []
        for i, num in enumerate(nums):
            if dic.get(num) is None:
                dic[target - num] = i
            else:
                res = [dic[num], i]
        return res

#sample

l = Solution()

print(l.twoSum([2, 7, 1, 0, 8, 1, 8], 9))
print(l.twoSum([3, 2, 4], 6))  # [1, 2]
print(l.twoSum([3, 3], 6))  # [0, 1]