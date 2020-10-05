const sort = (list: number[]): number[] => {
  const temp = list;
  for (let i = 0; i < list.length; i++) {
    for (let j = 0; j < list.length - i - 1; j++) {
      if (temp[j] > temp[j + 1]) {
        const t = temp[j];
        temp[j] = temp[j + 1];
        temp[j + 1] = t;
      }
    }
  }
  return temp;
};

console.log(sort([4, 5, 1, 8, 9, 0]));
