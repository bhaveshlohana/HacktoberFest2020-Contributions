package DataStructures.Queues;

import java.util.ArrayList;

/**
 * This class implements a GenericArrayListQueue.
 * <p>
 * A GenericArrayListQueue data structure functions the same as any specific-typed queue.
 * The GenericArrayListQueue holds elemets of types to-be-specified at runtime.
 * The elements that are added first are the first to be removed (FIFO)
 * New elements are added to the back/rear of the queue.
 *
 */
public class GenericArrayListQueue<T> {
    /**
     * The generic ArrayList for the queue
     * T is the generic element
     */
    ArrayList<T> _queue = new ArrayList<T>();

    /**
     * Checks if the queue has elements (not empty)
     *
     * @return True if the queue has elements. False otherwise.
     */
    private boolean hasElements() {
        return !_queue.isEmpty();
    }

    /**
     * Checks what's at the front of the queue
     *
     * @return If queue is not empty, element at the front of the queue. Otherwise, null
     */
    public T peek() {
        T result = null;
        if(this.hasElements()) { result = _queue.get(0); }
        return result;
    }

    /**
     * Inserts an element of type T to the queue.
     *
     * @param element of type T to be added
     * @return True if the element was added successfully
     */
    public boolean add(T element) {
        return _queue.add(element);
    }

    /**
     * Retrieve what's at the front of the queue
     *
     * @return If queue is not empty, element retrieved. Otherwise, null
     */
    public T poll() {
        T result = null;
        if(this.hasElements()) { result = _queue.remove(0); }
        return result;
    }

    /**
     * Main method
     *
     * @param args Command line arguments
     */
    public static void main(String[] args) {
        GenericArrayListQueue<Integer> queue = new GenericArrayListQueue<Integer>();
        System.out.println("Running...");
        assert queue.peek() == null;
        assert queue.poll() == null;
        assert queue.add(1) == true;
        assert queue.peek() == 1;
        assert queue.add(2) == true;
        assert queue.peek() == 1;
        assert queue.poll() == 1;
        assert queue.peek() == 2;
        assert queue.poll() == 2;
        assert queue.peek() == null;
        assert queue.poll() == null;
        System.out.println("Finished.");
    }
}
