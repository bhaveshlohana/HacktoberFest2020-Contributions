class BinarySearchTree { 
	class Node { 
		int key; 
		Node left, right; 

		public Node(int item) { 
			key = item; 
			left = right = null; 
		} 
	} 

	// Root of BST 
	Node root; 
	BinarySearchTree() { 
		root = null; 
	} 
	void insert(int key) { 
	root = insertRec(root, key); 
	} 
	Node insertRec(Node root, int key) { 
		if (root == null) { 
			root = new Node(key); 
			return root; 
		} 
		if (key < root.key) 
			root.left = insertRec(root.left, key); 
		else if (key > root.key) 
			root.right = insertRec(root.right, key); 
		return root; 
	} 
	void inorder() { 
	inorderRec(root); 
	} 
	void inorderRec(Node root) { 
		if (root != null) { 
			inorderRec(root.left); 
			System.out.println(root.key); 
			inorderRec(root.right); 
		} 
	} 
	public static void main(String[] args) { 
		BinarySearchTree tree = new BinarySearchTree(); 
		tree.insert(50); 
		tree.insert(30); 
		tree.insert(20); 
		tree.insert(40); 
		tree.insert(70); 
		tree.insert(60); 
		tree.insert(80); 

		// print inorder traversal of the BST 
		tree.inorder(); 
	} 
} 
