def twoSum(nums, target):
    nums.sort()
    l = 0
    r = len(nums)-1
    while l < r:
        cs = nums[l]+nums[r]
        if cs == target:
            return [nums[l], nums[r]]
        elif cs < target:
            l = l+1
        elif cs > target:
            r = r-1
    return []


if __name__ == "__main__":

    nums = list(map(int, input().split()))
    target = int(input())
    result = twoSum(nums, target)
    print(result)
