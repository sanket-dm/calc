//////
// A simple CLI based calculator written in C having functions like scientific calculator.
// Assembled and compiled by Sanket Deshmane (sanket.dm@outlook.com)
// A current work in progress, new features will be added in time
//////

#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
#define START "\nEnter the operation you want to perform: ";
const float iota = sqrt(-1);
const float pi = 3.14159265;
const float coulomb_const = 9000000000;
const float r2 = sqrt(2);
const float r3 = sqrt(3);


void addition();
void modulus_operation();
void power();
int factorial();
void help();
void pol_rect();
void rect_pol();
void find_log();
void find_antilog();
void sim_eq_2();
void sim_eq_3();
void inv_3();
void mat_mult();
void integral_cos();
void integral_sin();

/*
16-bit colour scheme for the SetColor function:
Name            | Value
Black           |   0
Blue            |   1
Green           |   2
Cyan            |   3
Red             |   4
Magenta         |   5
Brown           |   6
Light Gray      |   7
Dark Gray       |   8
Light Blue      |   9
Light Green     |   10
Light Cyan      |   11
Light Red       |   12
Light Magenta   |   13
Yellow          |   14
White           |   15
*/

void SetColor(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

int main()
{
    char operation;
    help();
    while(1){
        cout<<endl;
        SetColor(9);
        cout<<endl<<"START: ";
        SetColor(15);
        cin>>operation;

        switch(operation){
            case 'A': addition();
                        break;
            case 'B': modulus_operation();
                        break;
            case 'C': power();
                        break;
            case 'D': factorial();
                        break;
            case 'E': pol_rect();
                        break;
            case 'F': rect_pol();
                        break;
            case 'G': find_log();
                        break;
            case 'H': find_antilog();
                        break;
            case 'I': sim_eq_2();
                        break;
            case 'J': sim_eq_3();
                        break;
            case 'K': inv_3();
                        break;
            case 'L': mat_mult();
                        break;
            case 'M': integral_cos();
                        break;
            case 'N': integral_sin();
                        break;

            case '/': exit(0);
                        break;
            case '*': help();
                        break;
            case '-': system("cls");
                      help();
                        break;

            default : system("cls");
            cout<<"\033[1;31m";
            cout<<"\nThe entered option is unavailable. Please enter any one of the below options.\n";
            cout<<"\033[0m;";
            help();
        }
    }
}

void help()
{
        SetColor(10);
    cout<<"Welcome to CLI scientfic calculator!!!"<<endl<<endl;
    cout<<"Press / to quit"<<endl;
    cout<<"Press * to display options"<<endl;
    cout<<"Press - to clear the screen and display available options"<<endl<<endl;
        SetColor(14);
    cout<<"Press A for Addition"<<endl;
    cout<<"Press B for modulus_operation"<<endl;
    cout<<"Enter C for Power"<<endl;
    cout<<"Enter D for Factorial"<<endl;
    cout<<"Enter E for Polar to Rectangular conversion"<<endl;
    cout<<"Enter F for Rectangular to Polar conversion"<<endl;
    cout<<"Enter G for finding log"<<endl;
    cout<<"Enter H for finding antilog"<<endl;
    cout<<"Enter I for solution of 2 simultaneous equations"<<endl;
    cout<<"Enter J for solution of 3 simultaneous equations"<<endl;
    cout<<"Enter K for determinant and inverse of 3x3 matrix"<<endl;
    cout<<"Enter L for matrix multiplication"<<endl;
    cout<<"Enter M for cos integration"<<endl;
    cout<<"Enter N for sin integration"<<endl;
        SetColor(15);
}

void addition()
{
    float n, total=0, k=0, number;
    cout<<endl<<"Enter the number of elements you want to add:";
        cin>>n;
    cout<<"Please enter "<<n<<" numbers one by one: "<<endl;
    while(k<n){
        cin>>number;
        total=total+number;
        k=k+1;
    }
    cout<<"Sum of "<<n<<" numbers = "<<total<<endl;
}

void modulus_operation()
{
    int a, b, d=0;
    cout<<endl<<"First enter the number then the modulus number: ";
        cin>>a>>b;
    d=a%b;
    cout<<endl<<"The modulus of entered numbers = "<<d<<endl;
}

void power()
{
    double a,b,p;
    cout<<endl<<"First enter the number and then power:"<<endl;
        cin>>a>>b;
    p=pow(a,b);
    cout<<"The result is: "<<p<<endl;
}

int factorial()
{
    int i,fact=1,num;
    cout<<endl<<"nEnter a number : ";
        cin>>num;
    if (num<0){
        cout<<endl<<"Please enter a positive number in order to proceed."<<endl;
        return 1;
    }
    for(i=1;i<=num;i++)
        fact=fact*i;
    cout<<endl<<"The factorial is: "<<fact;
    return 0;
}

void rect_pol()
{
    float a,b,r,t;
    const float pi = 3.141592;
    cout<<"\nEnter rectangular coordinates seperated by a space: ";
        cin>>r>>t;
    t=t*(180/pi);
    r=sqrt(a*a+b*b);
    t=atan(b/a);
    cout<<"The polar form is: "<<r<<"|_"<<t<<endl;
}

void pol_rect()
{
    float a,b,r,t;
    const float pi = 3.141592;
    cout<<endl<<"Enter polar coordinates seperated by a space: ";
        cin>>r>>t;
    t=t*(pi/180);
    a=r*cos(t);
    b=r*sin(t);
    cout<<"The rectangular form is: "<<a<<" + j "<<b<<endl;
}

void find_log()
{
    double n, a, b;
    cout<<endl<<"Enter a number for finding log: ";
        cin>>n;
    a=log(n);
    b=log10(n);
    cout<<"e's log is:  "<<a<<endl;
    cout<<"10's log is: "<<b<<endl;
}

void find_antilog()
{
    float n, c, d;
    cout<<endl<<"Enter a number for finding antilog: ";
        cin>>n;
    c = pow(2.718281828,n);
    d = pow(10,n);
    cout<<endl<<"e's antilog is:  "<<c<<endl;
    cout<<endl<<"10's antilog is: "<<d<<endl;
}

void sim_eq_2()
{
    float a,b,c,d,e,f,x,y,arr[4];
    cout<<endl<<"Enter a,b,c in format ax+by=c: ";
        cin>>a>>b>>c;
    cout<<endl<<"Enter d,e,f in format dx+ey=f: ";
        cin>>d>>e>>f;
    if(((a*e)-(d*b))!=0){
        arr[0]=(c/a);
        arr[1]=(-1)*(b/a);
        arr[2]=(f/d);
        arr[3]=(-1)*(e/d);
        y=((arr[2]-arr[0])/(arr[1]-arr[3]));
        x=arr[0]+(arr[1]*y);
        cout<<"X="<<x<<endl<<"Y="<<y<<endl;
    }
    if(((a*e)-(d*b))==0 && ((b*f)-(e*c))==0 && ((d*c)-(a*f))==0){
        if(c/a>=0)
            cout<<"Infinite number of solutions"<<endl<<"X="<<(-1*b)/a<<"Y+"<<c/a<<endl;
        else
            cout<<"Infinite number of solutions"<<endl<<"X="<<(-1*b)/a<<"Y="<<c/a<<endl;
    }
    if(((a*e)-(d*b))==0 && ((b*f)-(e*c))!=0 && ((d*c)-(a*f))!=0){
        cout<<"No Solutions found\n";
    }
}

void sim_eq_3()
{
    float a,b,c,l,m,n,p,q,r,x,y,z,i,j,k,D,D1,D2,D3;
    cout<<endl<<"Enter a,b,c,i in format ax+by+cx+i=0: ";
        cin>>a>>b>>c>>i;
    cout<<endl<<"Enter l,m,n,j in format lx+my+zn+j=0: ";
        cin>>l>>m>>n>>j;
    cout<<endl<<"Enter p,q,r,k in format px+qy+rz+k=0: ";
        cin>>p>>q>>r>>k;
    D = (a*m*r+b*p*n+c*l*q)-(a*n*q+b*l*r+c*m*p);
    D1 = (b*r*j+c*m*k+i*n*q)-(b*n*k+c*q*j+i*m*r);
    D2 = (a*n*k+c*p*j+i*l*r)-(a*r*j+c*l*k+i*n*p);
    D3 = (a*q*j+b*l*k+i*m*p)-(a*m*k+b*p*j+i*l*q);
    if (D != 0){
        x = D1/D;
        y = D2/D;
        z = D3/D;
        cout<<endl<<"The value of x,y,z respectively are: "<<x<<" "<<y<<" "<<z;
    }else{
        if (D1 == 0 && D2 == 0 && D3 == 0)
            cout<<endl<<"Infinite possible solutions"<<endl;
        else if (D1 != 0 || D2 != 0 || D3 != 0)
            cout<<endl<<"No possible solutions"<<endl;
    }
}

void inv_3()
{
    int mat[3][3], i, j;
    float det = 0;
    cout<<endl<<"Enter elements of matrix in a[i][j] format one by one: ";
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cin>>mat[i][j];
        }
    }
    for(i = 0; i < 3; i++)
        det = det + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
    cout<<endl<<endl<<"The determinant is: "<<det;
    cout<<endl<<"The inverse is: ";
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cout<<((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3])) / det;
        }
        cout<<endl;
    }
}

void mat_mult()
{
    int m, n, p, q, c, d, k, sum = 0;
    int first[10][10], second[10][10], multiply[10][10];
    cout<<endl<<"Rows & Columns of 1st matrix:"<<endl;
        cin>>m>>n;
    cout<<"Rows & Columns of 2nd matrix:"<<endl;
        cin>>p>>q;
    cout<<"Elements of first matrix: "<<endl;
    for (  c = 0 ; c < m ; c++ ){
        for ( d = 0 ; d < n ; d++ ){
            cin>>first[c][d];
        }
    }
    if ( n != p )
        cout<<endl<<"Multiplication not possible";
    else{
        cout<<"Elements of second matrix"<<endl;
        for ( c = 0 ; c < p ; c++ ){
            for ( d = 0 ; d < q ; d++ ){
                cin>>second[c][d];
            }
        }
        for ( c = 0 ; c < m ; c++ ){
            for ( d = 0 ; d < q ; d++ ){
                for ( k = 0 ; k < p ; k++ ){
                    sum = sum + first[c][k]*second[k][d];
                }
                multiply[c][d] = sum;
                sum = 0;
            }
        }
        cout<<"Matrix product is:"<<endl;
        for ( c = 0 ; c < m ; c++ ){
            for ( d = 0 ; d < q ; d++ ){
                cout<<multiply[c][d];
            }
            cout<<"\n";
        }
    }
}

void integral_cos()
{
    double(*f)(double x)=cos;
    double a, b, n;
    char type;
    cout<<endl<<"Enter values of Lower Bound, Upper Bound, Steps respectively:"<<endl;
    cin>>a>>b>>n;
    double step = (b - a) / n;
    double area = 0.0;
    for (int i = 0; i < n; i ++) {
        area += f(a + (i + 0.5) * step) * step;
    }
    cout<<"The integral value is: "<<area;
}

void integral_sin()
{
    double(*f)(double x)=sin;
    double a, b, n;
    char type;
    cout<<endl<<"Enter values of Lower Bound, Upper Bound, Steps respectively:"<<endl;
    cin>>a>>b>>n;
    double step = (b - a) / n;
    double area = 0.0;
    for (int i = 0; i < n; i ++) {
        area += f(a + (i + 0.5) * step) * step;
    }
    cout<<"The integral value is: "<<area;
}
