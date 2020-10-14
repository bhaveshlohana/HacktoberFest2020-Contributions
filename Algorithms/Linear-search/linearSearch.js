// Two Way Linear Search 

var arr = [2,5,1,88,22,66,4];
var start = 0;
var end = arr.length - 1;

// Input
var ip = parseInt(prompt("Enter number to search"));


for (var i = 0; i < arr.length / 2; i++) {
    if ( (ip == arr[start]) || (ip == arr[end]) ) {
        document.write("Found "+ ip);
        break;
    }
    else {
        start++;
        end--;
    }
}
