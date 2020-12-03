/*
variables tweaking the design

- numberOfColumns: the number of columns to be included in the viewport
  ! the value is capped to 360 to have at most one color for each hue in the [0-360] color wheel
- duration: the number of seconds it takes to complete the bubble sort
  ! this does not account for the animation of the button, but the animation of the columns only

- lightness and saturation: default values for the hsl color
*/
const numberOfColumns = 359;
const duration = 7.5;
const saturation = 70;
const lightness = 70;

// array describing the hues of the different columns, to avoid doubles
const hues = [];
// function returning a random hue, which is not already in the hues array
const uniqueHue = () => {
  const hue = Math.floor(Math.random() * 360);
  // if the hue is already present re-run the function
  if (hues.includes(hue)) {
    return uniqueHue();
  }
  // else add the hue to the array and return its value
  hues.push(hue);
  return hue;
};

// select the node in which to add the columns
const body = document.querySelector('body');

// in the body include as many div elements as specified by the columns variable
for (let i = 0; i < Math.min(numberOfColumns, 359); i += 1) {
  const columns = document.createElement('div');
  // with a unique hue
  const hue = uniqueHue();
  columns.style.background = `hsl(${hue}, ${saturation}%, ${lightness}%)`;
  // with a transition incrementally delayed for each successive column
  // ! ultimately this has the effect of swapping the columns one after the other
  columns.style.transition = `all 0.2s ${duration / numberOfColumns * i}s ease-out`;
  // add a data attribute to rapidly order the columns according to the hue value
  columns.setAttribute('data-hue', hue);
  body.appendChild(columns);
}

// target the button
const button = document.querySelector('button');

// function called to sort the items of an array according to data-hue attribute
function bubbleSort(arr) {
  // bubble sort algorithm
  // instead of swapping the items based on their values, swap them on the basis of the data-hue attribute
  for (let n = arr.length; n >= 0; n -= 1) {
    for (let i = 0; i < n - 1; i += 1) {
      const currentPosition = i;
      const nextPosition = i + 1;

      const current = arr[currentPosition];
      const next = arr[nextPosition];

      const currentHue = Number.parseInt(current.getAttribute('data-hue'), 10);
      const nextHue = Number.parseInt(next.getAttribute('data-hue'), 10);

      if (currentHue > nextHue) {
        [arr[currentPosition], arr[nextPosition]] = [arr[nextPosition], arr[currentPosition]];
      }
    }
  }
  return arr;
}

// function called when the button is pressed
function handleClick() {
  // add the class prompting the transition
  button.classList.add('clicked');
  // once the button's animation is complete
  button.addEventListener('animationend', () => {
    // target all the columns
    const columns = body.querySelectorAll('div');
    // sort an copy of the node list, converting it first to an array
    const sortedColumns = bubbleSort([...columns]);

    // loop through the sortedColumns array
    for (let i = 0; i < sortedColumns.length; i += 1) {
      // find the column in the unsorted data structure with the data-hue attribute matching the sorted value
      const sortedColumn = sortedColumns[i];
      const matchingColumn = [...columns].find(column => column.getAttribute('data-hue') === sortedColumn.getAttribute('data-hue'));
      // apply a property of order beginning with the smallest values, pushing the smaller hues to the beginning of the grid
      matchingColumn.style.order = i - sortedColumns.length;
    }
  });
}

// on click call the function prompting the sorting and the application of the order property according to the hue
button.addEventListener('click', handleClick);
