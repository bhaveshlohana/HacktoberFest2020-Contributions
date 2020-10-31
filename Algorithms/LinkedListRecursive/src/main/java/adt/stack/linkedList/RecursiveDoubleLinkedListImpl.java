package adt.linkedList;

public class RecursiveDoubleLinkedListImpl<T> extends
   		RecursiveSingleLinkedListImpl<T> implements DoubleLinkedList<T> {
   
   	protected RecursiveDoubleLinkedListImpl<T> previous;
   
   	public RecursiveDoubleLinkedListImpl() {
   
  	}
  
  	public RecursiveDoubleLinkedListImpl(T data,
  			RecursiveSingleLinkedListImpl<T> next,
  			RecursiveDoubleLinkedListImpl<T> previous) {
  		super(data, next);
  		this.previous = previous;
  	}
  	
  	@Override
  	public void insert(T element) {
  		if (element != null) {
  			if (isEmpty()) {
  				setData(element);
  				setNext(new RecursiveDoubleLinkedListImpl<T>());
  				((RecursiveDoubleLinkedListImpl<T>) getNext()).setPrevious(this);
  				if (getPrevious() == null) {
  					setPrevious(new RecursiveDoubleLinkedListImpl<T>());
  					getPrevious().setNext(this);
  				}
  			} else
  				getNext().insert(element);
  		}
  	}
  
  	@Override
  	public void insertFirst(T element) {
  		if (element != null) {
  			if (isEmpty()) {
  				setData(element);
  				setPrevious(new RecursiveDoubleLinkedListImpl<T>());
  				getPrevious().setNext(this);
  				if (getNext() == null) {
  					setNext(new RecursiveDoubleLinkedListImpl<T>());
  					((RecursiveDoubleLinkedListImpl<T>) getNext()).setPrevious(this);
  				} else
  					tradeHead(((RecursiveDoubleLinkedListImpl<T>) getNext()), this);
  			} else
  				getPrevious().insertFirst(element);
  		}
  	}
  	
  	private void tradeHead(RecursiveDoubleLinkedListImpl<T> head, RecursiveDoubleLinkedListImpl<T> newHead) {
  		T dataHead = head.getData();
  		head.setData(newHead.getData());
  		newHead.setData(dataHead);
  		newHead.setNext(head.getNext());
  		head.setNext(newHead);
  		((RecursiveDoubleLinkedListImpl<T>) newHead.getNext()).setPrevious(newHead);
  		newHead.setPrevious(head);
  		head.setPrevious(new RecursiveDoubleLinkedListImpl<T>());
  		head.getPrevious().setNext(head);
  	}
  
  	@Override
  	public void removeFirst() {
  		if (!isEmpty()) {
  			if (getPrevious().isEmpty()) {
  				setData(getNext().getData());
  				setNext(getNext().getNext());
  			} else
  				getPrevious().removeFirst();
  		}
  	}
  
  	@Override
  	public void removeLast() {
  		if (!isEmpty()) {
  			if (getNext().isEmpty()) {
  				setData(getNext().getData());
  				setNext(getNext().getNext());
  			} else
  				((RecursiveDoubleLinkedListImpl<T>) getNext()).removeLast();
  		}
  	}
  
  	public RecursiveDoubleLinkedListImpl<T> getPrevious() {
  		return previous;
  	}
  	public void setPrevious(RecursiveDoubleLinkedListImpl<T> previous) {
  		this.previous = previous;
  	}

}