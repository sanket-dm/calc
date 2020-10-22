////// 
// A simple CLI based calculator written in C having functions like scientific calculator. 
// Assembled and compiled by Sanket Deshmane (sanket.dm@outlook.com)
// Credits go respectively to wherever the pieces of code are taken/built from
// A current work in progress, new features will be added in time
//////

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h> 
#define START "\nEnter the operation you want to perform: "
#define iota sqrt(-1)
#define pi 3.14159265
#define coulomb_const 9000000000
#define r2 sqrt(2)
#define r3 sqrt(3)

void addition();
void modulus();
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

void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
 
int main()
{
    int X=1;
    char operation;
 
    help();
 
    while(X)
    {
        printf("\n");
        SetColor(9);
        printf("%s : ", START);
        SetColor(15);
 
        operation=getche();
 
        switch(operation)
        {
            case '+': addition();
                        break;
            case '?': modulus();
                        break;
            case '!': factorial();
                        break;
            case '^': power();
                        break;
            case 'H': help();
                        break;
            case 'Q': exit(0);
                        break;
            case 'P': pol_rect();
                        break;
            case 'R': rect_pol();
                        break;
            case 'L': find_log();
                        break;
            case 'A': find_antilog();
                        break;    
            case '2': sim_eq_2();
                        break; 
            case '3': sim_eq_3();
                        break;
            case 'I': inv_3();
                        break;
            case '*': mat_mult();
                        break;
            case 'W': work_charges();
                        break;

            case 'C': system("cls");
                      help();
                        break;
 
            default : system("cls");
            printf("\033[1;31m");
            printf("\nThe entered option is unavailable. Please enter any one of the below options.\n");
            printf("\033[0m;"); 
            help();
        }
    }
}
 
void help()
{
        SetColor(10);
    printf("Welcome to cli scientfic calculator for ECE! \n\n");
    printf("Press Q to quit \n");
    printf("Press H to display options \n");
    printf("Press C to clear the screen and display available options \n\n");
        SetColor(14);
    printf("01. Press + for Addition \n");
    printf("02. Press ? for Modulus\n");
    printf("03. Enter ^ for Power \n");
    printf("04. Enter ! for Factorial \n\n");
    printf("05. Enter P for Polar to Rectangular conversion \n");
    printf("06. Enter R for Rectangular to Polar conversion \n");
    printf("07. Enter L for finding log \n");
    printf("08. Enter A for finding antilog \n");
    printf("09. Enter 2 for solution of 2 simultaneous equations \n");
    printf("10. Enter 3 for solution of 3 simultaneous equations \n");
    printf("11. Enter I for determinant and inverse of 3x3 matrix \n");
    printf("12. Enter * for matrix multiplication \n");
    printf("13. Enter W for work done on charges \n");
        SetColor(15);
}
 
void addition()
{
    float n, total=0, k=0, number;
    printf("\nEnter the number of elements you want to add:");
    scanf("%f",&n);
    printf("Please enter %f numbers one by one: \n",n);
    while(k<n)
    { 
        scanf("%f",&number);
        total=total+number;
        k=k+1;
    }
    printf("Sum of %d numbers = %d \n",n,total);
}
 
void modulus()
{
    int a, b, d=0; 
    printf("\nFirst enter the number then the modulus: "); 
    scanf("%d%d",&a,&b); 
    d=a%b;
    printf("\nModulus of entered numbers = %d\n",d);
}
 
void power()
{
    double a,b,p;
    printf("\nFirst enter the number and then power: \n");
    scanf("%lf%lf",&a,&b); 
    p=pow(a,b);
    printf("The result is: %lf \n",p);
}
 
int factorial()
{
    int i,fact=1,num;
    printf("\nEnter a number : ");
    scanf("%d",&num);
    if (num<0)
    {
        printf("\nPlease enter a positive number in order to proceed. \n");
        return 1;
    }               
    for(i=1;i<=num;i++)
        fact=fact*i;
    printf("\n");
    printf("The factorial is: %d",fact);
    return 0;
}

void rect_pol()
{
    float a,b,r,t;
    const float pi = 3.141592;
    printf("\nEnter rectangular coordinates seperated by a space: ");
    scanf("%f%f",&r,&t);
    t=t*(180/pi);
    r=sqrt(a*a+b*b);
    t=atan(b/a);
    printf("The polar form is: %f ∠ %f ",r,t);
}

void pol_rect()
{
    float a,b,r,t;
    const float pi = 3.141592;
    printf("\nEnter polar coordinates seperated by a space: ");
    scanf("%f%f",&r,&t);
    t=t*(pi/180);
    a=r*cos(t);
    b=r*sin(t);
    printf("The rectangular form is: %f + j %f ",a,b);
}

void find_log()
{
    double n, a, b;
    printf("\nEnter a number for finding log: ");
    scanf("%lf", &n);
    a=log(n);
    b=log10(n);
    printf("e's log is:  %lf \n",a);
    printf("10's log is: %lf \n",b);
}

void find_antilog()
{
    float n, c, d;
    printf("\nEnter a number for finding antilog: ");
    scanf("%lf", &n);
    c = pow(2.718281828,n);
    d = pow(10,n);
    printf("\ne's antilog is:  %f",c);
    printf("\n10's antilog is: %f",d);
}

void sim_eq_2()
{
    float a,b,c,d,e,f,x,y,arr[4];
    printf("\nEnter a,b,c in format ax+by=c: ");
    scanf("%f%f%f",&a,&b,&c);
    printf("\nEnter d,e,f in format dx+ey=f: ");
    scanf("%f%f%f",&d,&e,&f);
    if(((a*e)-(d*b))!=0)
    {
        arr[0]=(c/a);
        arr[1]=(-1)*(b/a);
        arr[2]=(f/d);
        arr[3]=(-1)*(e/d); 
        y=((arr[2]-arr[0])/(arr[1]-arr[3]));
        x=arr[0]+(arr[1]*y);
        printf("X=%f\nY=%f\n",x,y);
    }
    if(((a*e)-(d*b))==0 && ((b*f)-(e*c))==0 && ((d*c)-(a*f))==0)
    {
        if(c/a>=0)
            printf("Infinite number of solutions\nX=%fY+%f\n",(-1*b)/a,c/a);
        else
            printf("Infinite number of solutions\nX=%fY%f\n",(-1*b)/a,c/a);
    }
    if(((a*e)-(d*b))==0 && ((b*f)-(e*c))!=0 && ((d*c)-(a*f))!=0)
    {
        printf("No Solutions found\n");
    }
}

void sim_eq_3()
{
    float a,b,c,l,m,n,p,q,r,x,y,z,i,j,k,D,D1,D2,D3;
    printf("\nEnter a,b,c,i in format ax+by+cx+i=0: ");
    scanf("%f%f%f%f",&a,&b,&c,&i);
    printf("\nEnter l,m,n,j in format lx+my+zn+j=0: ");
    scanf("%f%f%f%f",&l,&m,&n,&j);
    printf("\nEnter p,q,r,k in format px+qy+rz+k=0: ");
    scanf("%f%f%f%f",&p,&q,&r,&k);
    D = (a*m*r+b*p*n+c*l*q)-(a*n*q+b*l*r+c*m*p);
    D1 = (b*r*j+c*m*k+i*n*q)-(b*n*k+c*q*j+i*m*r);
    D2 = (a*n*k+c*p*j+i*l*r)-(a*r*j+c*l*k+i*n*p);
    D3 = (a*q*j+b*l*k+i*m*p)-(a*m*k+b*p*j+i*l*q);
    if (D != 0)
    {   
        x = D1/D;
        y = D2/D;
        z = D3/D;
        printf("\nThe value of x,y,z respectively are: %f %f %f",x,y,z);
    }
    else 
    { 
        if (D1 == 0 && D2 == 0 && D3 == 0) 
            printf("\nInfinite possible solutions\n"); 
        else if (D1 != 0 || D2 != 0 || D3 != 0) 
            printf("\nNo possible solutions\n"); 
    }
}

void inv_3()
{
    int mat[3][3], i, j;
    float det = 0;
    printf("\nEnter elements of matrix in a[i][j] format one by one: ");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    for(i = 0; i < 3; i++)
        det = det + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
    printf("\n\nThe determinant is: %f", det);
    printf("\nThe inverse is: ");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {    
            printf("%.2f\t",((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ det);
        }
        printf("\n");
    }
}

void mat_mult()
{
    int m, n, p, q, c, d, k, sum = 0;
    int first[10][10], second[10][10], multiply[10][10];
 
    printf("\nRows & Columns of 1st matrix: \n");
        scanf("%d%d", &m, &n);
    printf("Rows & Columns of 2nd matrix: \n");
        scanf("%d%d", &p, &q);

    printf("Elements of first matrix\n");
    for (  c = 0 ; c < m ; c++ )
    {
        for ( d = 0 ; d < n ; d++ )
        {
            scanf("%d", &first[c][d]);
        }
    }
 
    if ( n != p )
    {
        printf("\nMultiplication not possible");
    }
    else
    {
        printf("Elements of second matrix\n");
        for ( c = 0 ; c < p ; c++ )
        {    
            for ( d = 0 ; d < q ; d++ )
            {    
                scanf("%d", &second[c][d]);
            }
        }        
        for ( c = 0 ; c < m ; c++ )
        {
            for ( d = 0 ; d < q ; d++ )
            {
                for ( k = 0 ; k < p ; k++ )
                {
                    sum = sum + first[c][k]*second[k][d];
                }
                multiply[c][d] = sum;
                sum = 0;
            }
        }
        printf("Matrix product is:\n");
        for ( c = 0 ; c < m ; c++ )
        {
            for ( d = 0 ; d < q ; d++ )
            {    
                printf("%d\t", multiply[c][d]);
            }
            printf("\n");
        }
    }
}

