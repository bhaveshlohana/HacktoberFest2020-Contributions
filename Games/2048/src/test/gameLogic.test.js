import gameLogic from "../gameLogic";

const grid = [[2, 2, 2, 2], [2, 2, 2, 2], [2, 2, 2, 2], [2, 2, 2, 2]];

const transform1 = [
  [4, 4, null, null],
  [4, 4, null, null],
  [4, 4, null, null],
  [4, 4, null, null]
];

const transform2 = [
  [8, 8, null, null],
  [8, 8, null, null],
  [null, null, null, null],
  [null, null, null, null]
];

const noMoves = [
  [2, 4, 8, 16],
  [32, 64, 128, 256],
  [1024, 128, 64, 32],
  [16, 8, 4, 2]
];

const has2048 = [
  [2, 4, 8, 16],
  [32, 64, 128, 256],
  [2048, 128, 64, 32],
  [16, 8, 4, 2]
];

let fn = () => {
  return {
    score: 0,
    best: 0,
    grid: grid,
    setScore: () => {},
    setBest: () => {},
    setGridState: () => {}
  };
};

test("gameLogic is an object", () => {
  expect(typeof gameLogic).toEqual("object");
});

test("No transfromation yields default", () => {
  expect(gameLogic.addCell(grid, fn())).toEqual({
    best: 0,
    score: 0,
    grid: grid,
    transform: grid
  });
});

test("score is calculated 1", () => {
  expect(gameLogic.calcScore(grid, transform1)).toEqual(32);
});

test("score is calculated 2", () => {
  expect(gameLogic.calcScore(transform1, transform2)).toEqual(32);
});

test("Has no moves left", () => {
  expect(gameLogic.hasNoMovesLeft(noMoves)).toEqual(true);
});

test("Has moves left", () => {
  expect(gameLogic.hasNoMovesLeft(transform1)).toEqual(false);
});

test("Has 2048", () => {
  expect(gameLogic.has2048(has2048)).toEqual(true);
});
