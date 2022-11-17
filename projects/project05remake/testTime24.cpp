#include <iostream>
#include "Dijkstra.cpp"
#include "time24.h"
using namespace std;

int main() {
    time24 t1 = time24(5, 30);
    time24 t2 = time24(6, 45);
    time24 t = t1 - t2;
    t.Display();
    t = t1 + t2;
    t.Display();
    bool tt;
    tt = t1 > t2; cout << tt << endl;
    tt = t1 < t2; cout << tt << endl;   
}