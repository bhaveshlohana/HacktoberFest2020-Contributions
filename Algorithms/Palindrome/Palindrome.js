// For single values
const palindrome = (val) =>
  String(val).split("").reverse().join("") === String(val)
    ? `Culprit ${val} is a Palindrome.`
    : `Culprit ${val} is not a Palindrome.`;

// For arrays
const palindromeArr = (arr) =>
  arr.map((val) => {
    return String(val).split("").reverse().join("") === String(val)
      ? console.log(`Culprit ${val} is a Palindrome`)
      : console.log(`Culprit ${val} is not a Palindrome.`);
  });
