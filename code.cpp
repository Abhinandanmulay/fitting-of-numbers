#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

class fittingOnStrightLine{
public:
    int n;
    vector<int> x;
    vector<float> y;
    double sumx=0, sumy=0, sumxy=0, sumx2=0, sumy2=0;
    double a, b, r;

    void takeinput() {
        cout << "Enter no of points: ";
        cin >> n;
        x.resize(n);
        y.resize(n);
        cout << endl << "Enter Points of x: " << endl;
        for (int i=0; i<n; i++) {
            cout << i+1 << ": ";
            cin >> x[i];
        }

        cout << endl << "Enter Points of y: " << endl;
        for (int i=0; i<n; i++) {
            cout << i+1 << ": ";
            cin >> y[i];
        }
    }

    void calculatevalues() {
        for (int i=0; i<n; i++) {
            sumx+=x[i];
            sumy+=y[i];
            sumxy+=x[i]*y[i];
            sumx2+=x[i]*x[i];
            sumy2+=y[i]*y[i];
        }
        b = (sumx*sumxy-sumy*sumx2)/(sumx*sumx-n*sumx2);
        a = (sumy-b*n)/sumx;
        r = (n*sumxy-sumx*sumy)/sqrt((n*sumx2-sumx*sumx)*(n*sumy2-sumy*sumy));
    }

    void display() {
        cout << left << setw(10) << "x"
        << left << setw(10) << "y"
        << left << setw(10) << "xy"
        << left << setw(10) << "x^2" << endl;
        cout << "----------------------------------" << endl;
        for (int i=0; i<n; i++) {
            cout << left << setw(10) << x[i]
            << left << setw(10) << y[i]
            << left << setw(10) << x[i]*y[i]
            << left << setw(10) << x[i]*x[i] << endl;   
        }  
        cout << "----------------------------------" << endl;
        cout << left << setw(10) << sumx
             << left << setw(10) << sumy
             << left << setw(10) << sumxy
             << left << setw(10) << sumx2 << endl;
        cout << "----------------------------------" << endl;
        cout << "For y = ax+b: " << endl
             << "a = " << a << endl
             << "b = " << b << endl
             << "r = " << r << endl;
    }
};

int main() {
    fittingOnStrightLine t;
    t.takeinput();
    t.calculatevalues();
    t.display();
    return 0;
}