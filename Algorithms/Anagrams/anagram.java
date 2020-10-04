import java.util.*;
public class anagram {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		String a=in.next();
		String b=in.next();
		int count[]=new int[256];
		int i=0,j=0;
		while(i<a.length()&&j<b.length())
		{
			char a1=a.charAt(i);
			++count[a1];
			char b1=b.charAt(j);
			--count[b1];
			i++;j++;
		}
		boolean flag=true;
		for (int q=0;q<256;q++)
		{
			if (count[q]!=0)
				{System.out.println("NOT");flag=false;
			break;}
			
		}
		if (flag==true&&a.length()==b.length())
			System.out.println("ANAGRAM");
	}

}
