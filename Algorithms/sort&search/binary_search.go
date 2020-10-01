func binarySearch(s []int, num int, start int, end int) int{
    if start > end {
        return -1
    }

    mid := (start + end) /2
    if s[mid] == num {
        return mid
    } else if s[mid] > num {
        return binarySearch(s, num, start, mid-1)
    } else {
        return binarySearch(s, num, mid+1, end)
    }
}