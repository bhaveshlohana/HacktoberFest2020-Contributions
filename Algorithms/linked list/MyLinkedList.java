package collectionFramework.linkedList;

public class MyLinkedList <E> {
	Node <E>head;
	
	public void  add (E data) {
		Node <E>toAdd=new Node<E>(data);
		if(isEmpty()) {
		 head=toAdd;
		 return;
		}
		Node<E> temp=head;
		while(temp.next!=null) {
			temp= temp.next;
		}
		temp.next=toAdd;
	}
	void print() {
		Node <E>temp=head;
		while(temp!=null) {
			System.out.println(temp.data+" ");
			temp= temp.next;
		}
	}
	public boolean isEmpty() {
//		if(head==null) return true;
//		else return false;
		return head==null;
	}
    public E removeLast() throws Exception{
    	Node<E> temp=head;
    	if(temp==null) {
    		throw new Exception("can't remove last element from empty list");
    	}
    	if(temp.next==null) {
    		Node <E> toRemove=head;
    		head=null;
    		return toRemove.data;
    	}
    	while(temp.next.next != null) {
    		temp=temp.next;
    	}
    	Node<E> toRemove=temp.next;
    	temp.next=null;
    	return toRemove.data;
    }
    public E getLast() throws Exception{
    	Node<E> temp=head;
    	if(temp==null) {
    		throw new Exception("can't peek last element from empty list");
    	}
    	while(temp.next!= null) {
    		temp=temp.next;
    	}
    	
    	return temp.data;
    }

 static class Node <E> {
	 E data;
	 Node<E> next;
	 public Node(E data){
		 this.data=data;
		 next=null;
	 }
 } 
 }
