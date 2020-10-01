let ls = function (arr, item) {
    // Go through all the elements of arr to look for item.
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] === item) { // Found it!
            return i;
        }
    }
    // Item not found in the array.
    return null;
}

let arr = [1, 3, 5, 7, 8, 9]; 
let x = 5; 

if (ls(arr, x)) 
	document.write("Element found!<br>"); 
else document.write("Element not found!<br>"); 

x = 6; 

if (ls(arr, x)) 
	document.write("Element found!<br>"); 
else document.write("Element not found!<br>");				 

