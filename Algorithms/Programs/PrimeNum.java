public class PrimeNum {

	public static void main(String[] args) {
		
		int[] a= new int[3];
		int i=0,n=0,count=0;
		String prime="";
		for(i=1;i<=50;i++) {
			count = 0;
			if(i!=2&&(i==1||i%2==0))
				continue;
			else {
				for(n=1;n<=i;n++) {
					if(i%n==0) {
						count++;
					}	
				}
				if(count==2) {
					prime = prime + i + " ";
				}
			}
		}
		
		System.out.print("prime: "+prime);

	}

}
