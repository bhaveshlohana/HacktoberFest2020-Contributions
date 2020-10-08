// Bubble sort algo in GO lang

package main
import (
	"fmt"
)

func input_number(tmp_arr *[10]int) {
  ele:=0
	for ; ele<10; ele++{
    fmt.Scanln(&tmp_arr[ele])
  }
}

func display_sorted(tmp_arr *[10]int){
  var (
      n = len(tmp_arr)
      sorted = false
  )
  for !sorted {
      swap := false
      for i := 0; i < n-1; i++ {
          if tmp_arr[i] > tmp_arr[i+1] {
              tmp_arr[i+1], tmp_arr[i] = tmp_arr[i], tmp_arr[i+1]
              swap = true
          }
      }
      if !swap {
          sorted = true
      }
      n = n - 1
  }
}

func main() {
  p_num :=[10] int{}
  n_num :=[10] int{}
  fmt.Println("Please enter 10 positive numbers")
  input_number(&p_num)
  fmt.Println(p_num)
  display_sorted(&p_num)
  fmt.Println("sorted array is ",p_num)
  fmt.Println("Please enter 10 numbers including atleast 1 negative number")
  input_number(&n_num)
  fmt.Println(n_num)
  display_sorted(&n_num)
  fmt.Println("sorted array is ",n_num)

}
