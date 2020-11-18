
//  This will take in an array of any ammount of numbers, and if
// the number is divisible by 3, it will console.log Fizz, if it is 
// divisible by 5, it will console.log Buzz, and if the number is divisible
// by both 3 and 5, it will console.log "Fizz Buzz". Otherwise the number will be 
// console.logged

// Declaration of function as a global variable.
var fizzBuzz = function (arr) {

// Looping through the array of integer
    for (i = 0; i < arr.length; i++) {

// Comparing the values with different condition using if else statements
        if (arr[i] % 15 === 0) {
            console.log('Fizz Buzz')
        }
        else if (arr[i] % 5 === 0) {
            console.log('Buzz');
        }

        else if (arr[i] % 3 === 0) {
            console.log('Fizz')
        }
        else {
            console.log(arr[i])
        }
    }
}
