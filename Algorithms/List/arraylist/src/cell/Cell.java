package cell;

public class Cell<T extends Comparable<T>>{
    private T value;
    private Cell prox;
    private boolean tree;
    private boolean istrue;
    private boolean paris;
    
    public Cell(T value){
        this(value,null);
    }// End Cell()

    public Cell(){
        this(null,null);
    }// End Cell()

    public Cell(T value, Cell prox){
        this.value = value;
        this.prox = prox;
    }// End Cell()

    public T getValue(){
        return value;
    }// End getValue()

    public void setValue(T value){
        this.value = value;
    }// End setValue()

    public Cell getProx(){
        return prox;
    }// End getProx()

    public void setProx(Cell prox){
        this.prox = prox;
    }// End setProx()
}// End Cell
