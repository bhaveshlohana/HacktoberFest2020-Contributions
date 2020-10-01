class Node{
  constructor(value){
    this.value = value;
    this.next = null;
  }
}

class LinkedList{
  constructor(value){
    this.head = new Node(value)
    this.tail = this.head;
    this.length = 1;
  }

  append(value){
    const newNode = new Node(value)
    this.tail.next = newNode
    this.tail = newNode
    this.length++
    return this
  }

  prepend(value){
    const newNode = new Node(value);
    newNode.next = this.head;
    this.head = newNode;
    this.length++;
    return this;
  }

  insert(index,value){
    // Head
    if(index == 0){
      return this.prepend(value)
    }

    // tail
    if(index>=this.length){
      return this.append(value)
    } 

    // inbetween
    let node = this.head
    let i = 0
    while(node.next){
      if(i == index-1){
        const newNode = new Node(value)
        newNode.next = node.next
        node.next = newNode
        this.length++
        return this;
      }
      node = node.next
      i++;
    }
  }

  remove(index){
    if(index==undefined){
      return this
    }
    // Remove head
    if(index == 0){
      this.head = this.head.next;
      this.length--
      return this
    }
    // Remove tail
    else if(index>=this.length){
      let tailPreNode = this.getNodeAtIndex(this.length-2)
      tailPreNode.next= null
      this.tail = tailPreNode
      this.length--
      return this
    }
    else{
      // In between
      let preNode = this.getNodeAtIndex(index-1)
      preNode.next=preNode.next.next;
      this.length--;
      return this
    }
  }
  getNodeAtIndex(index){
    let node = this.head
    let i = 0
    while(node){
      if(i == index){
        return node
      }
      node = node.next
      i++
    }
  }
  printList(){
    const array = []
    let node = this.head;
    while(node){
      array.push(node.value);
      node = node.next
    }
    console.log(array)
    return this
  }

  reverse(){
    let curr = this.head
    let prev = null
    let next = null
    while(curr){
      next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }
    this.tail = this.head
    this.head = prev
    return this;
  }
}

const myLinkedList = new LinkedList(10);
myLinkedList // [10]
  .append(5) // [10, 5]
  .append(16) // [10, 5, 6]
  .prepend(1) // [1, 10, 5, 6]
  .insert(4,99) // [1, 10, 5, 6, 99]
  .printList() // [1, 10, 5, 6, 99]
  .reverse() // [ 99, 16, 5, 10, 1 ]
  .printList() // [ 99, 16, 5, 10, 1 ]
