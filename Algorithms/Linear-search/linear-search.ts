function search(list: number[], key: number): number {
  for (let i = 0; i < list.length; i++) {
    if (list[i] === key) {
      return key;
    }
  }
  return -1;
}

console.log(search([1, 2, 5, 6, 9, 22, 3, 61], 2));
console.log(search([1, 2, 5, 6, 9, 22, 3, 61], 99));
