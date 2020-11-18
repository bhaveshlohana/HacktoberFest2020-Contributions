package main

import (
	"fmt"
)

func binarySearch(value int, array []int) int {
 
    low := 0
    high := len(array) - 1
 
    for low <= high{
        median := (low + high) / 2
 
        if array[median] < value {
            low = median + 1
        }else{
            high = median - 1
        }
    }
 
    if low == len(array) || array[low] != value {
        return -1
    }
 
    return low 
}

func main(){
    items := []int{5, 7, 11, 22, 33, 47, 58, 65}
    fmt.Println(binarySearch(11, items))
}