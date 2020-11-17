package adt.linkedList;

public class RecursiveSingleLinkedListImpl<T> implements LinkedList<T> {
   
   	protected T data;
   	protected RecursiveSingleLinkedListImpl<T> next;
   
   	public RecursiveSingleLinkedListImpl() {
   
  	}
  
  	public RecursiveSingleLinkedListImpl(T data,
  			RecursiveSingleLinkedListImpl<T> next) {
  		this.data = data;
  		this.next = next;
  	}
  
  	@Override
  	public boolean isEmpty() {
  		boolean empty = false;
  		if (getData() == null)
  			empty = true;
  		return empty;
  			
  	}
  
  	@Override
  	public int size() {
  		int result = 0;
  		if (!isEmpty())
  			result = 1 + getNext().size();
  		return result;
  	}
  
  	@Override
  	public T search(T element) {
  		T result = null;
  		if (!isEmpty() && element != null) {
  			if (getData().equals(element))
  				result = getData();
  			else
  				result = getNext().search(element);
  		}
  		return result;
  	}
  
  	@Override
  	public void insert(T element) {
  		if (element != null) {
  			if (isEmpty()) {
  				setData(element);
  				setNext(new RecursiveSingleLinkedListImpl<T>());
  			} else
  				getNext().insert(element);
  		}
  	}
  
  	@Override
  	public void remove(T element) {
  		if (!isEmpty() && element != null) {
  			if (getData().equals(element)) {
  				setData(getNext().getData());
  				setNext(getNext().getNext());
  			} else
  				getNext().remove(element);
  		}
  	}
  
  	@Override
  	public T[] toArray() {
  		T[] result = (T[]) new Object[size()];
  		toArray(result, this, 0);
  		return result;
  	}
  	
  
  	private void toArray(T[] result, RecursiveSingleLinkedListImpl<T> node, int index) {
  		if (!node.isEmpty()) {
  			result[index] = node.getData();
  			toArray(result, node.getNext(), index + 1);
  		} 
  	}
  
  	public T getData() {
  		return data;
  	}
  
  	public void setData(T data) {
  		this.data = data;
  	}
  
  	public RecursiveSingleLinkedListImpl<T> getNext() {
  		return next;
  	}
  
  	public void setNext(RecursiveSingleLinkedListImpl<T> next) {
  		this.next = next;
  	}
  
}