#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class fittingOnStrightLine{
public:
    int n;
    vector<int> x;
    vector<float> y;
    double sumx=0, sumy=0, sumxy=0, sumx2=0;
    double a, b;

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
    }
};

int main() {
    fittingOnStrightLine t;
    t.takeinput();
    t.display();
    return 0;
}