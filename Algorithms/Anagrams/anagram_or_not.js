const anagramCheck = (str1, str2) => {
  if (!str2) {
    return `Error! Missing an argument.`;
  } else {
    return str1.split("").sort().join("") === str2.split("").sort().join("")
      ? `Yes, these two are Anagrams of each other.`
      : `No, these two are not Anagrams of each other.`;
  }
};
