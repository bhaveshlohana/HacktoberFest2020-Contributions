#include<stdio.h>
#include<sting.h>
int top=-1,i,go=-1;
char s[100],ma[100];
int main(){
            char ch[1000];
            printf("Enter the element");
            scanf("%s",ch);
            for(i=0;i<strlen(ch);i++){
                if (ch[i]=='+'||ch[i]=='-'){
                    top++;
                    s[top]=ch[i];
                }
                if(ch[i]=='*'||ch[i]=='/'||ch[i]=='%'){
                    for(int j=i;j<=-1;j--){
                        if(s[j]=='+'||s[j]=='-'){
                            go++;
                            ma[go]=s[i];
                            //++ re counts........ check it out..... 
                        }

                    }
                }
                if (ch[i]=='('){
                    for(i=top;i<-1;i--){
                        if(s[i]!="("){
                            go++;
                            ma[go]=s[i];
                        }    
                    }
                }
                else{
                    go++;
                    ma[go]=ch;
                }
            }
        for(i=0;i<;)
            

