#include<stdio.h>
#include<conio.h>
int main()
{
    char msg[100], ch,x='y';
    int i,key,choice;
    printf("Enter a plaintext \n");
    gets(msg);
    printf("Enter key\n");
    scanf("%d",&key);
while(x=='y')
{
printf("Enter Choice\n1.Encryption\n2.Decryption\n");
scanf("%d",&choice);

switch(choice)
{
case 1:
for(i=0;msg[i]!='\0';i++)
    {
        ch=msg[i];
        if(ch>='a'&&ch<='z')//a se bada and z se kam
        {
            ch=ch+key; 
            
            msg[i]=ch;
        }
        else if(ch>='A'&&ch<'Z')
        {
            ch=ch+key;
            
            msg[i]=ch;
        }
    }
    printf("Encrypted message: %s\n", msg);
	break;
case 2:
for(i=0;msg[i]!='\0';i++)
    {
        ch=msg[i];
        if(ch>='a'&&ch<='z')
        {
            ch=ch-key;
            if(ch<'a')
            {
                ch=ch+'z'-'a'+1;
            }
            msg[i]=ch;
        }
        else if(ch>='A'&&ch<'Z')
        {
            ch=ch+key;
            if(ch<'A')
            {
                ch=ch+'Z'-'A'+1;
            }
            msg[i]=ch;
        }
    }
    printf("Dycrypted message: %s", msg);
	break;
default: printf("\nEnter correct choice");
break;
}
printf("\nwant to continue\n");
scanf("%s",&x);
if(x!='y')
exit(0);
}
    getch();
    return 0;
}