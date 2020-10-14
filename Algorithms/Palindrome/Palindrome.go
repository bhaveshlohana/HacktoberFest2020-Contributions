package main

import "fmt"

func isPalindrome(input string) bool {
	for i := 0; i < len(input)/2; i++ {
		if input[i] != input[len(input)-i-1] {
			return false
		}
	}
	return true
}

func main() {
	var str string
	fmt.Println("Insert a string: ")
	fmt.Scanf("%s", &str)
	isPalindrome := isPalindrome(str)

	if isPalindrome {
		fmt.Printf("string %s is palindrome", str)
	} else {
		fmt.Printf("string %s not palindrome", str)
	}
}
