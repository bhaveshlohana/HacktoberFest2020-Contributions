function linearSearch(arr, item) 
{
  for (var i = 0; i < arr.length; i++) 
  {
    if (arr[i] === item) 
    { 
      return i;
    }
  }
    return null;
}
linearSearch([1, 2, 3, 4, 5, 6, 7, 8, 9, 10] , 7)