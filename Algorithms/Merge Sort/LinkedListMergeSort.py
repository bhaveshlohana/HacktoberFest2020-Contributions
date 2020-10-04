#Program for merge sort in linked list
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None

	def append(self, new_value):

		new_node = Node(new_value)
		if self.head is None:
			self.head = new_node
			return
		curr_node = self.head
		while curr_node.next is not None:
			curr_node = curr_node.next

		curr_node.next = new_node

	def sortedMerge(self, a, b):
		result = None

		# Base cases
		if a == None:
			return b
		if b == None:
			return a

		if a.data <= b.data:
			result = a
			result.next = self.sortedMerge(a.next, b)
		else:
			result = b
			result.next = self.sortedMerge(a, b.next)
		return result

    #function for merge sort
	def mergeSort(self, h):

		if h == None or h.next == None:
			return h

		# get the middle of the list
		middle = self.getMiddle(h)
		nexttomiddle = middle.next

		# set the next of middle node to None
		middle.next = None

		# Apply mergeSort on left list
		left = self.mergeSort(h)

		# Apply mergeSort on right list
		right = self.mergeSort(nexttomiddle)

		# Merge the left and right lists
		sortedlist = self.sortedMerge(left, right)
		return sortedlist

	#get middle element from the linked list
	def getMiddle(self, head):
		if (head == None):
			return head

		slow = head
		fast = head

		while (fast.next != None and
			fast.next.next != None):
			slow = slow.next
			fast = fast.next.next

		return slow

def printList(head):
	if head is None:
		print(' ')
		return
	curr_node = head
	while curr_node:
		print(curr_node.data, end = " ")
		curr_node = curr_node.next
	print(' ')

# Main Code
if __name__ == '__main__':
	li = LinkedList()

	li.append(67)
	li.append(98)
	li.append(45)
	li.append(12)
	li.append(43)
	li.append(17)

	# Apply merge Sort
	li.head = li.mergeSort(li.head)
	print ("Sorted Linked List is:")
	printList(li.head)
