package arraylist;

import cell.Cell;
import list.List;

import java.util.Iterator;
import java.util.Objects;
import java.util.Spliterator;
import java.util.function.Consumer;

public class ArrayList<T extends Comparable<T>> implements List<T>{
    private Cell<T> first;
    private Cell<T> last;
    private int length;

    public ArrayList(){
        this(null,null,0);
    }// End ArrayList()

    private ArrayList(Cell<T> root,Cell<T> last, int length){
        this.last = last;
        this.first = first;
        this.length = length;
    }// End ArrayList()

    @Override
    public void clear(){
        this.first = null;
        this.length = 0;
    }// End clear()

    @Override
    public int getSize(){
        return this.length;
    }// End getSize()

    @Override
    public void show(){
        for(Cell<T> c = this.first; c != this.last.getProx(); c = c.getProx()){
            System.out.println(c.getValue());
        }// End for
    }// End show()

    @Override
    public boolean remove(Object o){
        boolean resp = false;
        if(this.length > 0){
            Cell<T> c = this.first;
            Cell<T> i = this.first;
            while(c != null && !c.getValue().equals(o)) c = c.getProx();
            if(c != null && c != this.first){
                while (i.getProx() != c) i = i.getProx();
                i.setProx(c.getProx());
            }else this.first = this.first.getProx();
            resp = true;
            this.length--;
        }// End if
        return resp;
    }// End remove()

    @Override
    public boolean contains(Object o){
        boolean resp = false;
        if(this.length > 0) {
            for(Cell<T> c = this.first; c != this.last.getProx() && !resp; c = c.getProx()){
                if(c.getValue().equals(o)) resp = true;
            }// End for
        }// End if
        return resp;
    }// End contains()

    public boolean put(T value){
        try{
            if (this.length == 0) this.last = this.first = new Cell<>(value);
            else{
                this.last.setProx(new Cell<>(value));
                this.last = this.last.getProx();
            }//End else
        }catch(NullPointerException e){ return false; }// End cath
        this.length++;
        return true;
    }// End put()

    @Override
    public Iterator iterator(){
        return null;
    }// End iterator()

    @Override
    public void forEach(Consumer action){
        Objects.requireNonNull(action);
        for(Object t : this) {
            action.accept(t);
        }// End for
    }// End forEach

    @Override
    public Spliterator spliterator(){
        return null;
    }// End spliterator()
}// End ArrayList
