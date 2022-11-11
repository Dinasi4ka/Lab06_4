// Lab06_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Create(double* a, const int n, const double Low, const double High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() * (High - Low )/ RAND_MAX;
}

void Print(double* a, const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(10) << a[i];
    cout << endl;
}
double Sum(double* a, const int n)
{
    double S=0;
    for (int i = 1; i < n; i++)
        if (a[i] > 0)
            S += a[i];
    return S;
}
void Max(double*& a, const int n, double& max, int& imax)
{
    max = a[0];
    imax = 0;
    for (int i = 0; i < n; i++)
    {
        if (fabs(a[i]) > max)
        {
            max = a[i];
            imax = i;
        }
    }
}

 void Min(double* a, const int n, double& min, int& imin)
 {
     min = a[0];
     imin = 0;
     for (int i = 0; i < n; i++)
     {
         if (fabs(a[i]) < min)
         {
            min = a[i];
            imin = i;
         }
     }
}

double P(double* a, const int n, int i,int imin,int imax)
{
    int in1 = 0;
    int in2 = 0;
    double d = 1.;
    if (imin < imax) {
        in1 = imin;
        in2 = imax;
    }
    else {
        in2 = imin;
        in1 = imax;
    }

    double P = 1.;
    for (int i = in1; i <= in2; i++)
            P *= a[i];
    return P;
}
void Sort(double*& a, const int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        double max = a[i];
        int imax = i;
        for (int j = i + 1; j < n; j++)
            if (max < a[j])
            {
                max = a[j];
                imax = j;
            }
        a[imax] = a[i];
        a[i] = max;
    }
}


int main()
{
    srand((unsigned)time(NULL));

    int n;

    cout << " input n "; cin >> n;

    int k = n;
    double* a = new double[k];

    double Low = -10;
    double High = 35;

    Create(a, n, Low, High);
    Print(a, n);
    double max = 0.;
    int imax = 0;

    double min = 0.;
    int imin = 0;
    Max(a, n, max, imax);
    Min(a, n, min, imin);

    cout << " " << "S = " << Sum(a, n) << endl;
    cout << " " << "P = " << P(a, n,0,imin,imax) << endl;

    Sort(a, n);
    cout << "Sort a = { ";
    Print(a, n);

    delete[]a;
    return 0;
}
