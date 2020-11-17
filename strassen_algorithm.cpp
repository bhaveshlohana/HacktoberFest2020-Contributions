#include <iostream>
# include <vector>
using namespace std;

vector< vector<int> >matrix_a={{2,3},{5,6}};
 vector< vector<int> >matrix_b={{1,6},{9,8}};
 vector< vector<int> > result={{0,0},{0,0}};

void strassen_mul( vector< vector<int> > a, vector<vector<int>> b){
  int d1=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
  int d2=(a[1][0]+a[1][1])*b[0][0];
  int d3=(b[0][1]-b[1][1])*a[0][0];
  int d4=(b[1][0]-b[0][0])*a[1][1];
  int d5=(a[0][0]+a[0][1])*b[1][1];
  int d6=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
  int d7=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

  int c11=d1+d4-d5+d7;
  int c12=d3+d5;
  int c21=d2+d4;
  int c22=d1+d3-d2+d6;
   cout << c11 <<"->"<<c12<<"->"<<c21<<"->"<<c22<< '\n';
}

int main(){
  strassen_mul(matrix_a,matrix_b);
}
