
public class ShellSort{

    public static void insertion(int[] a, int delta, int start){
        int pivot;
        int j;
        for(int i = start + delta ;i < a.length; i+=delta){
            pivot = a[i];   
            j = i-delta;
            while(j >= start && a[j] > pivot){
                a[j + delta] = a[j];  
                j -= delta;           
            }
            a[j+delta] = pivot; 
        }
    }
    public static void shell(int[] a){
        //find first delta: gratest integer smaller than a.length in the series {1,4,13,40, ...} 3x+1
        int delta=1;
        while((delta*3)+1 < a.length){
            delta = (delta*3)+1;
        }
        while(1 <= delta){
            for(int start = 0; (start + delta) < a.length && start < delta; start++){
                insertion(a, delta, start);
            }
            delta = (delta -1 )/3;
        }
    }
    public static void main(String[] Args){
        int[] array = {4,7,1,2,4,5,12,4,5,13,5,-7,-8,-9,4,5,2,18};
        final int N = 100000;
        array = Sesion1.randomArray(N, -N, N);
        long start = System.currentTimeMillis();
        insertionMethod.insertion(array);
        long end = System.currentTimeMillis();
        System.out.printf("%.2f\n", (end-start)/1000.0 );
        
        start = System.currentTimeMillis();
        shell(array);
        end = System.currentTimeMillis();
        System.out.printf("%.2f\n", (end-start)/1000.0 );
        //System.out.println(Arrays.toString(array));
    }
}