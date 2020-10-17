import arraylist.ArrayList;
import list.List;

public class Main{
    public static void main(String[] args){
        ArrayList<String> list = new ArrayList<>();
        list.put("Teste");
        list.put("Vinicius");
        list.put("Silva");

        System.out.println(list.getSize());
        list.remove("Teste");

        System.out.println(list.getSize());
        list.show();
        System.out.println("FIM DA EXECUÇÃO");
    }// End main()
}// End Main
