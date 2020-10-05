const isPalindrome = (text: string): boolean => {
  const temp = text.split("");
  for (let left = 0, right = temp.length - 1; left < right; left++, right--) {
    if (temp[left] !== temp[right]) return false;
  }
  return true;
};

console.log(isPalindrome("tot"));
console.log(isPalindrome("toe"));
