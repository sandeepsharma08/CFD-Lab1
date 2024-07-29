#include<iostream>
#include<iomanip>
#define A 5
#define B 8


using namespace std;
float f(int x) {
	return 4*x - (x*x)/2.0;
}
int main() {
	float u[B+1][A+1],h=1.0, k=0.125,csqr,alpha,ust,uet;
	int i,j;
	cout<<"Enter the square of 'c'"<<endl;
	cin >> csqr;
	alpha = (csqr*k)/(h*h);
	cout <<"Enter the value of u[0,t]"<<endl;
	cin>>ust;
	cout <<"Enter the value of u["<<B<<",t]"<<endl;
	cin>>uet;
	cout<<fixed;
	for (j=0; j<=A; j++) {
		u[0][j] = u[B][j]=ust;
	}
	for(i=1; i<=B-1; i++) {
		u[i][0] = f(i*h);
	}
	for(j=0; j<=A-1; j++) {
		for(i=1; i<=B-1; i++) {
			u[i][j+1]=alpha*u[i-1][j] + (1-2*alpha)*u[i][j] + alpha*u[i+1][j];
		}
	}
	cout<<"The value of alpha is"<<setw(4) << setprecision(2)<<alpha<<endl;
	cout<<"THe values of u[i,j] are:-"<<endl;
	for(j=0; j<=A; j++) {
		for(i=0; i<=B; i++) {
			cout<<setw(7) <<setprecision(3)<<u[i][j];

		}
		cout<<endl;
	}
	return 0;
}
