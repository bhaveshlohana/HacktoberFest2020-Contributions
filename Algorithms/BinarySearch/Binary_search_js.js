function binarySearch(value, list) {
    let first = 0;    //first index
    let last = list.length - 1;   //last index
    let found = false;
    let middle;
 
    while (found === false && first <= last) {
        middle = Math.floor((first + last)/2);
        if (list[middle] == value) {
            found = true;
            position = middle;
        } else if (list[middle] > value) {  //if in lower half
            last = middle - 1;
        } else {  //in in upper half
            first = middle + 1;
        }
    }
    return position;
}

//test code
var items = [1, 2, 3, 4, 5, 7, 8, 9];
console.log(binarySearch(1, items));   
console.log(binarySearch(5, items));