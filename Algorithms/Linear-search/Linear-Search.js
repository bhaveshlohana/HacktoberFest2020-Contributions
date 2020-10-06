const array = [1, 2, 4, 5, 7, 8, 9, 2];

// Match all using .filter
const filterSearch = (arr, elem) => arr.filter((val) => elem == val);

// Check for element using .includes
const includesSearch = (arr, elem) => (arr.includes(elem) ? true : false);

// Check for element using .indexOf
const indexOfSearch = (arr, elem) => (arr.indexOf(elem) !== -1 ? true : false);

// Check for element using .find
const findSearch = (arr, elem) =>
  arr.find((val) => val === elem) ? true : false;
