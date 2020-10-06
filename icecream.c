/*To print the discounted price for any flavor ice cream*/
#include<stdio.h>
main()
{
    int x,cupsc,cupsv,cupsb,cupsa,cost;
    printf("\n\t\t\t\t*************** AMUL ICE CREAM PARLOR ****************");
    printf("\n\t\t\t\t******   Chitrakut Complex, Channi Jakat Naka   ******");
    printf("\n\t\t\t\t**********         Vadodara-390024           *********");
    printf("\n\t\t\t\t**********      Contact No. 9104805395       *********");
    printf("\n\t\t\t\t------------------------------------------------------");
    printf("\n\n\t\t\t\t              Welcome to the Amul Parlour!!!        ");
    printf("\n\t\t\t\t CURRENTLY WE HAVE FOLLOWING FLAVORS OF ICE CREAMS:-  ");
    printf("\n\t\t\t\t              1. CHOCOLATE                            ");
    printf("\n\t\t\t\t              2. VANILLA                              ");
    printf("\n\t\t\t\t              3. BADSHAHI                             ");
    printf("\n\t\t\t\t              4. AMERICAN DRYFRUIT                    ");
    sneh:
    printf("\n\n\t\t\t\t NUMBER 1 IS FOR CHOCOLATE FLAVOR ICE CREAM         ");
    printf("\n\t\t\t\t NUMBER 2 IS FOR VANILLA FLAVOR ICE CREAM            ");
    printf("\n\t\t\t\t NUMBER 3 IS FOR BADSHAHI FLAVOR  ICE CREAM           ");
    printf("\n\t\t\t\t NUMBER 4 IS FOR AMERICAN DRYFRUIT FLAVOR  ICE CREAM  ");
    printf("\n\n\t\t\t\t SO, WHICH FLAVOR YOU WOULD LIKE TO BUY TODAY?\n");
    scanf("%d",&x);

     if(x==1)
     {
         printf("\n\t\t\t\t You have selected DELICIOUS CHOCOLATE FLAVOR ICECREAM.\n\t\t\t\t The cost of the Ice cream is Rs 20.\n\t\t\t\t How many cups of ice cream do you want?.\n");
         printf("\n\t\t\t\t For this special DIWALI Festival we have a discount of 15 percent on chocolate flavour.\n");
         scanf("%d",&cupsc);
     }
     else if(x==2)
     {
         printf("\n\t\t\t\t You have selected YUMMY VANILLA FLAVOR ICECREAM.\n\t\t\t\t The cost of the Ice cream is Rs 15.\n\t\t\t\t How many cups of ice cream do you want?.\n");
         printf("\n\t\t\t\t For this special DIWALI Festival we have a discount of 10 percent on vanilla flavour.\n");
         scanf("%d",&cupsv);
     }
     else if(x==3)
     {
         printf("\n\t\t\t\t You have selected TASTY BADSHAHI FLAVOR ICECREAM.\n\t\t\t\t The cost of the Ice cream is Rs 25.\n\t\t\t\t How many cups of ice cream do you want?.\n");
         printf("\n\t\t\t\t For this special DIWALI Festival we have a discount of 20 percent on Badshahi flavor.\n");
         scanf("%d",&cupsb);
     }
     else if(x==4)
     {
         printf("\n\t\t\t\t You have selected MOUTH-WATERING AMERICAN DRYFRUIT FLAVOR ICECREAM.\n\t\t\t\t The cost of the Ice cream is Rs 30.\n\t\t\t\t How many cups of ice cream do you want?.\n");
         printf("\n\t\t\t\t For this special DIWALI Festival we have a discount of 20 percent on American Dryfruit flavor.\n");
         scanf("%d",&cupsa);
     }
     else
     {
         printf("\n\t\t\t\t Please enter a VALID number to proceed the purchase.");
         goto sneh;
     }
     printf("\n\n\t\t\t\t-------------------------------------------------------");
     printf("\n\t\t\t\t\t\t      TAKE AWAY                                         ");
     printf("\n\t\t\t\t-------------------------------------------------------  ");
     printf("\n\t\t\t\t ITEM\t\t  QTY\t\tRATE\t\tPRICE");
     if(x==1)
        printf("\n\n\t\t\t\tChocolate 500gm\t   %d\t\t20\t\t %d",cupsc,cupsc*20);
     else if(x==2)
        printf("\n\n\t\t\t\tVanilla 500gm\t   %d\t\t15\t\t %d",cupsv,cupsv*15);
     else if(x==3)
        printf("\n\n\t\t\t\tBadshahi 500gm\t   %d\t\t25\t\t %d",cupsb,cupsb*25);
     else if(x==4)
        printf("\n\n\t\t\t\tAmnDry 500gm\t   %d\t\t30\t\t %d",cupsa,cupsa*30);
     else
        printf("INVALID NUMBER");
    printf("\n\t\t\t\t-------------------------------------------------------  ");
    if(x==1)
        {
        printf("\n\n\t\t\t\tAmount after discount is                       Rs%d",(cupsc*20)-((15*cupsc*20)/100));
        printf("\n\n\t\t\t\tCongratulations, You just saved Rs%d.",(15*cupsc*20)/100);
        }
    else if(x==2)
        {
        printf("\n\n\t\t\t\tAmount after discount is                       Rs%d",(cupsv*15)-((10*cupsv*15)/100));
        printf("\n\n\t\t\t\tCongratulations, You just saved Rs%d.",(10*cupsv*15)/100);
        }
    else if(x==3)
        {
        printf("\n\n\t\t\t\tAmount after discount is                       Rs%d",(cupsb*25)-((20*cupsb*25)/100));
        printf("\n\n\t\t\t\tCongratulations, You just saved Rs%d.",(20*cupsb*25)/100);
        }
    else if(x==4)
        {
        printf("\n\n\t\t\t\tAmount after discount is                       Rs%d",(cupsa*30)-((20*cupsa*30)/100));
        printf("\n\n\t\t\t\tCongratulations, You just saved Rs%d.",(20*cupsa*30)/100);
        }
    else
        printf("INVALID NUMBER");
    printf("\n\t\t\t\t-------------------------------------------------------  ");
    printf("\n\n\n");
    printf("\n\t\t\t\t*******************************************************");
    printf("\n\t\t\t\t*********** THANK YOU. PLEASE VISIT AGAIN.*************");
    printf("\n\t\t\t\t***********       HAVE A NICE DAY.        *************");
    printf("\n\t\t\t\t*******************************************************");
}
