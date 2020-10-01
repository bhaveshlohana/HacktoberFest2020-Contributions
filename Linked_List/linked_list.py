class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None

    # Insert a element at beginning
    def prepend(self, data):
        node = Node(data, self.head)
        self.head = node

    # Inserting an element at the end
    def append(self, data):
        if self.head is None:
            self.head = Node(data)
            return
        node = Node(data)
        itr = self.head
        while itr.next:
            itr = itr.next
        itr.next = node

    # Inserting a list of values at the end
    def append_values(self, data):
        pass


    # Print a Linked list
    def print(self):
        if self.head is None:
            print("List is Empty")
            return
        itr = self.head
        llstr = "[" + str(itr.data) + "] ->"
        while itr.next.next:
            itr = itr.next
            llstr += "[" + str(itr.data) + "] ->"
        print(llstr + "[" + str(itr.next.data) + "]")




if __name__ == '__main__':
    ll = LinkedList()
    ll.prepend(25)
    ll.prepend(20)
    ll.prepend(15)
    ll.prepend(10)
    ll.prepend(5)

    ll.append(30)
    ll.append(35)

    ll.print()
