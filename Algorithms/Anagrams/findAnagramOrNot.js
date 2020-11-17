function checkAnagram(string1, string2) {
  return (
    string1.toLowerCase().split('').sort().join('') ===
    string2.toLowerCase().split('').sort().join('')
  );
}

console.log(checkAnagram('aba', 'baa'));
console.log(checkAnagram('dell', 'ledd'));
