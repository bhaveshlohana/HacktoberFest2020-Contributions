interface IStack<T> {
  size: number;
  stack: T[];
  currentIndex: number;
  push(data: T): void;
  pop(): void;
  peak(): T;
}

class Stack implements IStack<number> {
  currentIndex: number = 0;
  size: number;
  stack: number[] = [];
  constructor(size: number) {
    this.size = size;
  }

  push(data: number) {
    if (this.currentIndex === this.size) throw new Error("overdlow");
    this.stack[this.currentIndex] = data;
    this.currentIndex++;
  }

  pop() {
    this.stack = this.stack.filter((_, index) => index !== this.currentIndex);
  }

  peak(): number {
    return this.stack[this.currentIndex];
  }
}

const listStack = new Stack(2);
listStack.push(1);
listStack.push(2);
