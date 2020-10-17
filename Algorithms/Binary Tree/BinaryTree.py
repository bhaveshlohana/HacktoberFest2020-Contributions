class node(object):
    def __init__(self,value):
        self.value = value
        self.left = None
        self.right = None
class BinaryTree(object):
    def __init__(self,root):
        self.root = node(root)
    def print_tree(self,strr):
        if strr=='preorder':
            return self.preorder_print(tree.root,"")
        if strr =='inorder':
            return self.inorder_print(tree.root,"")
        if strr =='postorder':
            return self.postorder_print(tree.root,"")
    def preorder_print(self,start,traversal):
        if start:
            traversal += (str(start.value)+'-')
            traversal = self.preorder_print(start.left,traversal)
            traversal = self.preorder_print(start.right,traversal)
        return traversal
    def inorder_print(self,start,traversal):
        if start:
            traversal = self.inorder_print(start.left,traversal)
            traversal+=str(start.value) + '-'
            traversal = self.inorder_print(start.right,traversal)
        return traversal
    def postorder_print(self,start,traversal):
        if start:
            traversal = self.preorder_print(start.left,traversal)
            traversal = self.preorder_print(start.right,traversal)
            traversal += (str(start.value)+'-')
        return traversal
tree = BinaryTree(1)
tree.root.left = node(2)
tree.root.left.left = node(4)
tree.root.left.right = node(5)
tree.root.right = node(3)
tree.root.right.left = node(6)
tree.root.right.right = node(7)
print(tree.print_tree('preorder'))
print(tree.print_tree('inorder'))
print(tree.print_tree('postorder'))
#        1
 #      /  \
 #     2     3
 #    / \   / \
 #   4   5  6  7