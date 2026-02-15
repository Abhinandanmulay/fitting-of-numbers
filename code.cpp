#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

class fittingOnStrightLine{
public:
    int n, hasfrequency;
    vector<float> x;
    vector<float> y;
    vector<int> f;

    double sumx=0, sumy=0, sumxy=0, sumx2=0, sumy2=0;
    double sumfx=0, sumfy=0, sumfxy=0, sumfx2=0, sumfy2=0, sumf=0;
    double a, b, r;

    void takeinput() {
        cout << "Enter no of points: ";
        cin >> n;
        cout << "Enter : " << endl
             << "1 : Simple fitting" << endl
             << "2 : Frequency fitting" << endl;
        cin >> hasfrequency;
        x.resize(n);
        y.resize(n);
        if (hasfrequency==2) f.resize(n);

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
        
        if (hasfrequency==2) {
            cout << endl << "Enter frequencies: " << endl;
            for (int i=0; i<n; i++) {
                cout << i+1 << ": ";
                cin >> f[i];
            }
        }
    }

    void calculatevalues() {

        if (hasfrequency==1) {
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
        } else if (hasfrequency==2) {

            for (int i=0; i<n; i++) {
                sumx+=x[i];
                sumy+=y[i];
                sumf+=f[i];
                sumfx+=f[i]*x[i];
                sumfy+=f[i]*y[i];
                sumfxy+=f[i]*x[i]*y[i];
                sumfx2+=f[i]*x[i]*x[i];
                sumfy2+=f[i]*y[i]*y[i];
            }
            b = (sumfx*sumfxy-sumfy*sumfx2)/(sumfx*sumfx-sumf*sumfx2);
            a = (sumfy-b*sumf)/sumfx;
            r = (sumf*sumfxy-sumfx*sumfy)/sqrt((sumf*sumfx2-sumfx*sumfx)*(sumf*sumfy2-sumfy*sumfy));
        }
    }

    void display() {
        if (hasfrequency==1) {
            cout << left << setw(10) << "x"
            << left << setw(10) << "y"
            << left << setw(10) << "xy"
            << left << setw(10) << "x^2"
            << left << setw(10) << "y^2" << endl;

            cout << "----------------------------------" << endl;
            for (int i=0; i<n; i++) {
                cout << left << setw(10) << x[i]
                << left << setw(10) << y[i]
                << left << setw(10) << x[i]*y[i]
                << left << setw(10) << x[i]*x[i]
                << left << setw(10) << y[i]*y[i] << endl;  
            }  
            cout << "----------------------------------" << endl;
            cout << left << setw(10) << sumx
            << left << setw(10) << sumy
            << left << setw(10) << sumxy
            << left << setw(10) << sumx2
            << left << setw(10) << sumy2 << endl;
            cout << "----------------------------------" << endl;
        } else if (hasfrequency==2) {
            cout << left << setw(10) << "x"
            << left << setw(10) << "y"
            << left << setw(10) << "f"
            << left << setw(10) << "fxy"
            << left << setw(10) << "fx^2"
            << left << setw(10) << "fy^2" << endl;

            cout << "----------------------------------" << endl;
            for (int i=0; i<n; i++) {
                cout << left << setw(10) << x[i]
                << left << setw(10) << y[i]
                << left << setw(10) << f[i]
                << left << setw(10) << f[i]*x[i]*y[i]
                << left << setw(10) << f[i]*x[i]*x[i]
                << left << setw(10) << f[i]*y[i]*y[i] << endl;
            }  
            cout << "----------------------------------" << endl;
            cout << left << setw(10) << sumfx
                 << left << setw(10) << sumfy
                 << left << setw(10) << sumf
                 << left << setw(10) << sumfxy
                 << left << setw(10) << sumfx2
                 << left << setw(10) << sumfy2 << endl;
            cout << "----------------------------------" << endl;

        }
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