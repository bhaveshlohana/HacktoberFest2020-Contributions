// For single values
const palindromeCheck = (val) =>
  String(val).split("").reverse().join("") === String(val)
    ? `Yes, the culprit ${val} is a Palindrome.`
    : `No, the culprit ${val} is not a Palindrome.`;

// For arrays
const palindromeArrCheck = (arr) =>
  arr.map((val) => {
    return String(val).split("").reverse().join("") === String(val)
      ? console.log(`Yes, the culprit ${val} is a Palindrome`)
      : console.log(`No, the culprit ${val} is not a Palindrome.`);
  });
