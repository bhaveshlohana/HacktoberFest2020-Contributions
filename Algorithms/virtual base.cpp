#include<iostream>
using namespace std;
class student{
	protected: 
		int r_no;
	public:
		void get_n (int a){
			r_no = a;
		
		cout <<"Roll No. "<< r_no<< "\n";}
};
class test : virtual public student{
	protected:
		int part1, part2;
		public:
		void get_m (int x, int y)
{ part1= x; part2=y;}
void putm (void)
{
cout << "marks obtained: "<< "\n"; cout << "part1 = " << part1 << "\n"; cout << "part2 = "<< part2 << "\n";
}	
};

class sports : public virtual student{
                        //base class 2
	protected:
		int score;
	public:
		void get_s (int a) 
		{ 
		score = a ;
		}
void put_s (void){
cout << "sports wt.: " <<score<< "\n";
}};
class result: public test, public sports	//derived class
{
private : 
int total ;
 public:
void show (void) ;
};

void result :: show (void)
{
 total = part1 + part2 + score ; 
put_n ();
put_m();
put_s() ; 
cout << "\n total score= " <<total<< "\n" ;
}
int main()
{
result S1; 
S1.get_n(345)
S1.get_m(30, 35) ;
S1.get_S(7) ;
S1. show();
return 0;
}







