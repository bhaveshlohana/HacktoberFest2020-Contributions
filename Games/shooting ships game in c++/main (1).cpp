#include <iostream>
#include <graphics.h>
#include<windows.h>
#include<conio.h>
#include<dos.h>
#include<cstdlib>
#include<time.h>
#include<mmsystem.h>

using namespace std;
void introduction();
void input();
void draw();
void logic();
void reset1();
void reset2();
void path();
void newgame();

int gameover=1,s=20,r=4,t,n1,m,rc=7,speed=15,let=0,userwannaplay=1;
int countp1=0,shootp1=0,winp1=0, ip1=20,jp1=100,xp1=ip1,yp1=jp1,a[10][10],ic1=200,jc1=400;//p1 variables
int countp2=0,shootp2=0,winp2=0,ip2=616,jp2=372,xp2=ip2,yp2=jp2,b[10][10],ic2=200,jc2=400;//p2 variables
string h;
char choice;

int main()
{PlaySound(TEXT("undertale1.wav"),NULL,SND_ASYNC | SND_LOOP);
introduction();
while(userwannaplay){
cout<<"enter any random number to start"<<endl;
cin>>t;
PlaySound(TEXT("MyAppSound"), NULL, SND_APPLICATION);
newgame();
path();
PlaySound(TEXT("undertale36.wav"),NULL,SND_ASYNC | SND_LOOP);

for(m=0;m<10;m++)//path printing
{
    for(n1=0;n1<10;n1++)
    {
        cout<<a[m][n1]<<" ";
    }
    cout<<"    ";
        for(n1=0;n1<10;n1++)
    {
        cout<<b[m][n1]<<" ";
    }
    cout<<endl;
}

int gd =DETECT ,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");gameover=1;
    while(gameover)
    {
        cleardevice();
        draw();
        input();
        bar(ip1,jp1,ip1+s,jp1+s);
        bar(ip2-s,jp2-s,ip2,jp2);
        if(shootp1){
              if(countp1==0)
              {
                  ic1=ip1+s+rc;
                  jc1=jp1+(s/2);
              }
          setcolor(05);
        for(int rad=0;rad<=rc;rad++)
          {circle(ic1,jc1,rad);}
          countp1++;
              if(ic1>580)
              {
                  countp1=0;
                  shootp1=0;
              }
              if(ic1<ip2&&jc1==jp2-s/2&&ic1>ip2-s)
              {reset2();shootp1=0;}
          ic1+=speed;
         }
        if(shootp2){
              if(countp2==0)
              {
                  ic2=ip2-s-rc;
                  jc2=jp2-(s/2);
              }
          setcolor(06);
          for(int rad=0;rad<=rc;rad++)
          {circle(ic2,jc2,rad);}
          countp2++;
              if(ic2<26)
              {
                  countp2=0;
                  shootp2=0;
              }
              if(ic2<ip1+s&&jc2==jp1+s/2&&ic2>ip1)
              {reset1();shootp2=0;}
         ic2-=speed;
         }
        logic();
        delay(100);
        if(winp1){
        setcolor(15);
        outtextxy(50,50,"player 1 wins ");
        delay(100);
        getch();
        }
        if(winp2){
        setcolor(15);
        outtextxy(400,50,"player 2 wins");
        delay(100);
        getch();
        }
    }

 closegraph();PlaySound(TEXT("MyAppSound"), NULL, SND_APPLICATION);PlaySound(TEXT("undertale1.wav"),NULL,SND_ASYNC | SND_LOOP);
 userwannaplay=2;system("CLS");
 cout<<"do you wanna play again y/n?";
 while(userwannaplay==2)
 {
  cin>>choice;
  if(choice=='y')
    userwannaplay=1;
  else if(choice=='n')
    userwannaplay=0;
  else
    cout<<"enter again";
 }
 }
return 0;
}


void input()//ip1,s,jp1
{
    if(GetAsyncKeyState(0x41))//a
       {shootp1=1;}
    if(GetAsyncKeyState(0x44))//d
        {ip1+=(s+8);}
    if(GetAsyncKeyState(0x57))//w
        {jp1-=(s+8);}
    if(GetAsyncKeyState(0x53))//s
        {jp1+=(s+8);}
    if(GetAsyncKeyState(0x46))//f
        {gameover=0;}
    if(GetAsyncKeyState(0x27))//right arrow key
        {shootp2=1;}
    if(GetAsyncKeyState(0x25))//left arrow key
        {ip2-=(s+8);}
    if(GetAsyncKeyState(0x26))//up arrow key
        {jp2-=(s+8);}
    if(GetAsyncKeyState(0x28))//down arrow key
        {jp2+=(s+8);}
}


void draw()
{   setcolor(03);
    for(m=0;m<11;m++)
     {
        line((xp1-r)+((s+(2*r))*m),yp1-r,(xp1-r)+((s+(2*r))*m),(yp1-r)+((s+(2*r))*10));//(xp1-r)+((s+(2*r))*m)=(xp1-r=xp1 of forst line)+((s+2xr)=diffrence bw 2 lines)

     }
    for(m=0;m<11;m++)
     {
        line(xp1-r,(yp1-r)+((s+(2*r))*m),(xp1-r)+((s+(2*r))*10),(yp1-r)+((s+(2*r))*m));
     }
    setcolor(04);
     for(m=0;m<11;m++)
     {
        line((xp2+r)-((s+(2*r))*m),yp2+r,(xp2+r)-((s+(2*r))*m),(yp2+r)-((s+(2*r))*10));//(xp1-r)+((s+(2*r))*m)=(xp1-r=xp1 of forst line)+((s+2xr)=diffrence bw 2 lines)

     }
    for(m=0;m<11;m++)
     {
        line(xp2+r,(yp2+r)-((s+(2*r))*m),(xp2+r)-((s+(2*r))*10),(yp2+r)-((s+(2*r))*m));
     }
    setcolor(15);
     bar(298,96,339,377);//finish line
     outtextxy(298,80,"Finish");
}


void logic()//variable used are p1,q1,ip1,jp1,xp1,yp1,s,r,m,n1,a[][]
{int p1,q1=(-1),p2,q2=(-1);

    {//check if player1 out of bound or on the finish line
    if(ip1<(xp1-r)||jp1>(yp1-r)+((s+(2*r))*10)||jp1<(yp1-r))
         reset1();
    else if(ip1>(xp1-r)+((s+(2*r))*10))
        {gameover=0;winp1=1;}
    }

    {//check if player2 out of bound or on the finish line
    if(ip2>(xp2+r)||jp2<(yp2+r)-((s+(2*r))*10)||jp2>(yp2+r))
         reset2();
    else if(ip2<(xp2+r)-((s+(2*r))*10))
        {gameover=0;winp2=1;}
    }

    for(m=0;m<10;m++)//get pos of player1 where p1 is vertical and q1 is horizontal positions
    {
        for(n1=0;n1<10;n1++)
        {
            if(ip1<(xp1-r)+((s+(2*r))*(m+1)) && jp1<(yp1-r)+((s+(2*r))*(n1+1)))
               {q1=m;p1=n1;break;}//m and q1 are horizontal n1 and p1 are vertical
        }
        if(q1>(-1))
            break;
    }

    if(a[p1][q1]==0)
    {reset1();}

    p1=0;q1=-1;

    for(m=0;m<10;m++)//get pos of player2 where p2 is vertical and q2 is horizontal positions
    {
        for(n1=0;n1<10;n1++)
        {
            if(ip2<(xp2+r)+((s+(2*r))*(m-9)) && jp2<(yp2+r)+((s+(2*r))*(n1-9)))
               {q2=m;p2=n1;break;}//m and q1 are horizontal n1 and p1 are vertical
        }
        if(q2>(-1))
            break;
    }

    if(b[p2][q2]==0)
    {reset2();}

    p2=0,q2=(-1);
}


void reset1()//variables used here are ip1,jp1,xp1,yp1
{
    ip1=xp1;jp1=yp1;
}
void reset2()//variables used here are ip1,jp1,xp1,yp1
{
    ip2=xp2;jp2=yp2;
}


void path()//variables used here are m,n1,temp,pathdir,a[][],u
{
    m=0;n1=0; int temp=40,pathdir;a[0][0]=1;int u=0;
srand(t);
   while(n1!=9)
   {
   pathdir=rand()%3;

   if(pathdir==0)//right
   {
       n1++;a[m][n1]=1;
       if(u==0)
       {u++;}
       else
       {temp=0;}
   }
   if(pathdir==1&&m<9&&temp!=2)//down
   {m++;a[m][n1]=1;temp=1;u=0;}
   if(pathdir==2&&m>0&&temp!=1)//up
   {m--;a[m][n1]=1;temp=2;u=0;}
   }

   n1=9;m=9;temp=40;b[9][9]=1;u=0;

   while(n1!=0)
   {
    pathdir=rand()%3;

   if(pathdir==0)//left
   {
       n1--;b[m][n1]=1;
       if(u==0)
       {u++;}
       else
       {temp=0;}
   }
   if(pathdir==1&&m<9&&temp!=2)//down
   {m++;b[m][n1]=1;temp=1;u=0;}
   if(pathdir==2&&m>0&&temp!=1)//up
   {m--;b[m][n1]=1;temp=2;u=0;}
   }
}


void introduction()
{int skip=1;
h="WeLcOmE pLaYeRs";
if(skip)
while(h[let]!='\0')
{
    cout<<h[let];
    Beep(850,50);if(GetAsyncKeyState(0x0D))skip=0;
    if(skip)delay(50);let++;
}else{cout<<h;}cout<<endl<<endl;let=0;


h="press enter to skip instructions";
if(skip)
while(h[let]!='\0')
{
    cout<<h[let];
    Beep(850,50);if(GetAsyncKeyState(0x0D))skip=0;
    if(skip)delay(50);let++;
}else{cout<<h;}cout<<endl<<endl;let=0;

h="aim of the game is to reach the center";
if(skip)
while(h[let]!='\0')
{
    cout<<h[let];
    Beep(850,35);if(GetAsyncKeyState(0x0D))skip=0;
    if(skip)delay(50);let++;
}else{cout<<h;}cout<<endl<<endl;let=0;

h="player 1 is on the left player 2 is on the right";
if(skip)
while(h[let]!='\0')
{
    cout<<h[let];
    Beep(850,50);if(GetAsyncKeyState(0x0D))skip=0;
    if(skip)delay(50);let++;
}else{cout<<h;}cout<<endl<<endl;let=0;

h="p1 controls --";
if(skip)
while(h[let]!='\0')
{
    cout<<h[let];
    Beep(850,35);if(GetAsyncKeyState(0x0D))skip=0;
    if(skip)delay(50);let++;
}else{cout<<h;}cout<<endl;let=0;

h="a to shoot";
if(skip)
while(h[let]!='\0')
{
    cout<<h[let];
    Beep(50,35);if(GetAsyncKeyState(0x0D))skip=0;
    if(skip)delay(50);let++;
}else{cout<<h;}cout<<endl;let=0;

h="w/s to move up/down";
if(skip)
while(h[let]!='\0')
{
    cout<<h[let];
    Beep(50,35);if(GetAsyncKeyState(0x0D))skip=0;
    if(skip)delay(50);let++;
}else{cout<<h;}cout<<endl;let=0;

h="d to move right";
if(skip)
while(h[let]!='\0')
{
    cout<<h[let];
    Beep(50,35);if(GetAsyncKeyState(0x0D))skip=0;
    if(skip)delay(50);let++;
}else{cout<<h;}cout<<endl<<endl;let=0;

h="p2 controls --";
if(skip)
while(h[let]!='\0')
{
    cout<<h[let];
    Beep(50,35);if(GetAsyncKeyState(0x0D))skip=0;
    if(skip)delay(50);let++;
}else{cout<<h;}cout<<endl;let=0;

h="right arrow key to shoot";
if(skip)
while(h[let]!='\0')
{
    cout<<h[let];
    Beep(50,35);if(GetAsyncKeyState(0x0D))skip=0;
    if(skip)delay(50);let++;
}else{cout<<h;}cout<<endl;let=0;

h="up/down arrow key to move up/down";
if(skip)
while(h[let]!='\0')
{
    cout<<h[let];
    Beep(50,35);if(GetAsyncKeyState(0x0D))skip=0;
    if(skip)delay(50);let++;
}else{cout<<h;}cout<<endl;let=0;

h="left arrow key to move left";
if(skip)
while(h[let]!='\0')
{
    cout<<h[let];
    Beep(50,35);if(GetAsyncKeyState(0x0D))skip=0;
    if(skip)delay(50);let++;
}else{cout<<h;}cout<<endl<<endl;let=0;

}

void newgame()
{
gameover=1;s=20;r=4;rc=7;speed=15;let=0;
countp1=0;shootp1=0;winp1=0; ip1=20;jp1=100;xp1=ip1;yp1=jp1;a[10][10];ic1=200;jc1=400;//p1 variables
countp2=0;shootp2=0;winp2=0;ip2=616;jp2=372;xp2=ip2;yp2=jp2;b[10][10];ic2=200;jc2=400;//p2 variables
for(n1=0;n1<10;n1++)
 {
  for(m=0;m<10;m++)
  {
    a[n1][m]=0;
    b[n1][m]=0;
  }
 }
}
