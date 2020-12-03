package main

import (
	"fmt"
)
 
func main() {
 
	items := []int{78, 7, 2, 851, 33, 47, 58, 65}
	insertionsort(items)
    fmt.Println(items)
}
 
  
func insertionsort(items []int) {
    var n = len(items)
    for i := 1; i < n; i++ {
        j := i
        for j > 0 {
            if items[j-1] > items[j] {
                items[j-1], items[j] = items[j], items[j-1]
            }
            j = j - 1
        }
    }
}
