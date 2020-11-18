import transformGrid from "../transformGrid";

const grid = [
  [null, null, null, null],
  [null, null, null, null],
  [null, null, null, null],
  [null, null, null, null]
];

const gridUp = [
  [2, null, null, null],
  [null, null, null, null],
  [null, null, null, null],
  [null, null, null, null]
];

const gridDown = [
  [null, null, null, null],
  [null, null, null, null],
  [null, null, null, null],
  [2, null, null, null]
];

const gridRight = [
  [null, null, null, 2],
  [null, null, null, null],
  [null, null, null, null],
  [null, null, null, null]
];

test("transformGrid is an object", () => {
  expect(typeof transformGrid).toEqual("object");
});

test("Cell added", () => {
  expect(
    transformGrid
      .addRandomCell(grid)
      .flat()
      .filter(x => x != null)
      .toString()
  ).not.toEqual("");
});

test("Calculated available cells", () => {
  expect(transformGrid.getAvailableCells(grid).length).toEqual(15);
});

test("Grid shifts left", () => {
  expect(transformGrid.shiftLeft(gridRight)).toEqual(gridUp);
});

test("Grid shifts right", () => {
  expect(transformGrid.shiftRight(gridUp)).toEqual(gridRight);
});

test("Grid shifts up", () => {
  expect(transformGrid.shiftUp(gridDown)).toEqual(gridUp);
});

test("Grid shifts down", () => {
  expect(transformGrid.shiftDown(gridUp)).toEqual(gridDown);
});
