const search = (
  list: number[],
  left: number,
  right: number,
  x: number
): number => {
  if (right >= left) {
    const mid = Math.floor(left + (right - left) / 2);
    if (list[mid] === x) {
      return list[mid];
    }

    if (list[mid] > x) {
      return search(list, left, mid - 1, x);
    } else {
      return search(list, mid + 1, right, x);
    }
  }
  return -1;
};

const data = [1, 2, 3, 4, 5, 6];
console.log(search(data, 0, data.length - 1, 1));
