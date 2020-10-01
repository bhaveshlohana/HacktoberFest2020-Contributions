function linearSearch(array, element) {
  for (var i=0; i<array.length; i++) {
    if (arr[i] == element) {
      return i;
    }
  } return null;
}

var array = [1,2,4,5,7,8,9,2];

linearSearch(array, 0); // returns null
linearSearch(array, 2); // returns 1