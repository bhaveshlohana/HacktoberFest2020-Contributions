//Airline Reservation system
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
 FILE *fp, *ft;
 char another, choice;
 char name[20];
 int i;
 float tax, base, fr1, fr2, fr3;            //'base' over here denotes the base flight fare which differs for each flight

 struct flight
 {
  int no_of_seats;
  char name[20], add[20], dob[20], date[20], fcode[20];
  char _class[20];                 //'class' cannot be used as it is a keyword
  float fare, amount;              //'fare' over here denotes the base class fare where as 'amount' denotes the sum to be paid
 }f;

 long int recsize;

 fp=fopen("FLIGHT.DAT", "rb+");
 if(fp==NULL)
 {
  fp=fopen("FLIGHT.DAT", "wb+");
  exit(1);
 }

 recsize=sizeof(f);
 while(1)
 {
  clrscr();
  printf("\t");
  printf("WELCOME TO AGYEYA AND AYUSH's airLINE TICKET RESERVATION SYSTEM");
  printf("\n");
  for(i=0;i<80;i++)
  {
   printf("*");
  }
  printf("\t 1:-> New record \n \t 2:-> List records \n \t 3:-> Modify records");
  printf("\n \t 4:-> Change flight rates \n \t 5:-> Delete records \n \t 6:-> Exit \n");
  for(i=0;i<80;i++)
  {
  printf("*");
  }
  printf("Please enter your choice : ");
  fflush(stdin);
  choice=getche();
  switch(choice)
  {
    case '1': fseek(fp,0,SEEK_END);
	      another='y';
	      while(another=='y')
	      {
	       printf("\n\nEnter customer name : ");
	       gets(f.name);
	       printf("Enter address : ");
	       gets(f.add);
	       printf("Enter date of birth : ");
	       gets(f.dob);
	       printf("Enter date of booking : ");
	       gets(f.date);
	       printf("Class Menu :\n 1. Economy\n 2. Business\n 3. First Class\n");
	       printf("Select a class: ");
	       gets(f._class);
	       printf("Flight Menu:\n FC2301: Delhi to Mumbai\n FC2302: Delhi to Chennai\n FC2303: Delhi to Kolkata\n");
	       printf("Enter flight code : ");
	       gets(f.fcode);
	       printf("Enter the number of seats to book : ");
	       scanf("%d",&f.no_of_seats);
	       if(stricmp(f.fcode, "FC2301")==0)
		base=fr1;
	       else if(stricmp(f.fcode, "FC2302")==0)
		base=fr2;
	       else if(stricmp(f.fcode, "FC2303")==0)
		base=fr3;
	       if(stricmp(f._class, "First Class")==0)
	       {
		 f.fare=5000;
		 tax=(0.15*f.fare);                          //GST is taken to be 15% on First class flights
		 f.amount=base+f.no_of_seats*(f.fare+tax);
	       }
	       else if(stricmp(f._class, "Business")==0)
	       {
		f.fare=3000;
		tax=(0.12*f.fare);                          //GST is taken to be 12% on Business class flights
		f.amount=base+f.no_of_seats*(f.fare+tax);
	       }
	       else if(stricmp(f._class, "Economy")==0)
	       {
		f.fare=1000;                                //GST is taken to be 5% on Economy class flights
		tax=(0.05*f.fare);
		f.amount=base+f.no_of_seats*(f.fare+tax);
	       }

	       printf("Total payable amount with tax is %f INR", f.amount);          //INR stands for Indian National Rupees
	       fwrite(&f,recsize,1,fp);
	       printf("\nPress y to add another record and n to discontinue : ");
	       fflush(stdin);
	       another=getche();
	       }
	       break;

    case '2':
	       while(fread(&f,recsize,1,fp)==1)
	       {
		printf("\nFlight Code : ");
		puts(f.fcode);
		printf("Name : ");
		puts(f.name);
		printf("Address : ");
		puts(f.add);
		printf("Date of Birth : ");
		puts(f.dob);
		printf("Date : ");
		puts(f.date);
		printf("Class : ");
		puts(f._class);
		printf("Seats : %d\nAmount : %f\n", f.no_of_seats, f.amount);
	       }
	       rewind(fp);
	       getch();
	       break;

   case '3':   another='y';
	       while(another=='y')
	       {
		printf("\n\nEnter the name of person whose record is to be modified : ");
		gets(name);
		rewind(fp);
		if(stricmp(f.name, name)!=0)
		 printf("Sorry! Record not found.\n");
		else
		{
		 while(fread(&f, recsize, 1, fp)==1)
		 {
		  if(stricmp(f.name, name)==0)
		  {
		   printf("Enter new name : ");
		   gets(f.name);
		   printf("Enter new address : ");
		   gets(f.add);
		   printf("Enter new date of birth : ");
		   gets(f.dob);
		   fseek(fp,-recsize, SEEK_CUR);
		   fwrite(&f,recsize,1,fp);
		   break;
		  }
		 }
		}
		printf("Press y to modify another record and n to discontinue : ");
		fflush(stdin);
		another=getche();
	       }
	       break;

   case '4':  another='y';
	      while(another=='y')
	      {
	       printf("\n\nEnter the code of the flight for which rates have to be changed : ");
	       gets(f.fcode);
	       if(stricmp(f.fcode, "FC2301")==0)
	       {
		printf("Enter new flight rates for Delhi to Mumbai flight : ");
		scanf("%f", &fr1);
	       }
	       else if(stricmp(f.fcode, "FC2302")==0)
	       {
		printf("Enter new flight rates for Delhi to Chennai flight : ");
		scanf("%f", &fr2);
	       }
	       else if(stricmp(f.fcode, "FC2303")==0)
	       {
		printf("Enter new flight rates for Delhi to Kolkata flight : ");
		scanf("%f", &fr3);
	       }
	       else
		printf("Sorry! Wrong flight code entered.\n");
	       printf("Press y if you still want to change flight rates and n to discontinue : ");
	       fflush(stdin);
	       another=getche();
	      }
	      break;

   case '5':  another ='y';
	      while(another=='y')
	     {
	      printf("\n\nEnter name of person whose record is to be deleted : ");
	      gets(name);
	      if(stricmp(f.name, name)!=0)
	       printf("Sorry! Record not found.\n");
	      else
	      {
	       ft=fopen("pop.DAT","wb");
	       rewind(fp);
	       while(fread(&f,recsize,1,fp)==1)
	      {
	       if(stricmp(f.name,name)!=0)
		fwrite(&f,recsize,1,ft);
	      }
	      fclose(fp);
	      fclose(ft);
	      remove("FLIGHT.DAT");
	      rename("pop.DAT","FLIGHT.DAT");
	      fp=fopen("FLIGHT.DAT","rb+");
	      }
	      printf("Press y to delete another record and n to discontinue : ");
	      fflush(stdin);
	      another=getche();
	    }
	    break;

  case '6': fclose(fp);
	    exit(0);
  }
 }
}
