//PROGRAM TO DISPLAY WORD WISE COUNT OF UPPER AND LOWER CASE CHARACTERS USING RECURSION.
import java.io.*;
class COUNT_CASE_RECURSION_STRING
{

    public static int UpperCase(String m)
    {

        int l=(m.length()-1);//storing length-1
        if(l<0)//base case
            return(0);

        else//recursive case
        /*if within the range then adding one and recalling function by 
        sending the substring by reducing it one less than total length which keeps on decreasing**/
            return((((m.charAt(l)>=65) && (m.charAt(l)<=90)) ?1:0)+(UpperCase(m.substring(0,l))));
    }//end of UpperCase()

    public static int LowerCase(String x)
    {

        int l1=(x.length()-1);//storing length-1
        if(l1<0)//base case
            return(0);

        else//recursive case
        /*if within the range then adding one and recalling function by 
        sending the substring by reducing it one less than total length which keeps on decreasing**/
            return((((x.charAt(l1)>=97) && (x.charAt(l1)<=122)) ?1:0)+(LowerCase(x.substring(0,l1))));
    }//end of LowerCase()

    public static void main (String args[])throws IOException
    {

        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("ENTER A SENTENCE");
        int i,len,upp,low;
        String v=br.readLine();//reading a sentence
        System.out.println();
        len=v.length();//storing length
        char ch;
        String w="";
        System.out.println("WORD WISE COUNT OF UPPER AND LOWER CASE CHARACTERS:");
        System.out.println("***************************************************");
        for(i=0;i<len;i++)
        {
            ch=v.charAt(i);//extracting chracters
            if(ch!=' ')
                w=w+ch;//forming words

            if(ch==' ' || i==(len-1))
            {
                //calling the functions to do the task
                upp=UpperCase(w);
                low=LowerCase(w);
                System.out.println(w);
                System.out.println("NUMBER OF UPPERCASE CHARACTERS:"+upp);
                System.out.println("NUMBER OF LOWERCASE CHARACTERS:"+low);
                System.out.println();
                w="";//refreshing the variable storing the words
            }//end of if
        }//end of for loop
        
        
        /*
        ENTER A SENTENCE
        HelLO WoRLd
        
        WORD WISE COUNT OF UPPER AND LOWER CASE CHARACTERS:
        ***************************************************
        HelLO
        NUMBER OF UPPERCASE CHARACTERS:3
        NUMBER OF LOWERCASE CHARACTERS:2
        
        WoRLd
        NUMBER OF UPPERCASE CHARACTERS:3
        NUMBER OF LOWERCASE CHARACTERS:2
        **/

    }//end of print()
}//end of class