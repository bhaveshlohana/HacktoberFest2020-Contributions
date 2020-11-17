package list;

public interface List<T extends Comparable<T>> extends Iterable{

    public void clear();
    public int getSize();
    public void show();
    public boolean remove(Object o);
    public boolean contains(Object o);

}// End List
