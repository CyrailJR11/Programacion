
#include <iostream>
using namespace std;
int main()
{
    //int score;
    //double distance;
    //char playagain;
    //bool shieldsup;

    //short lives, alienskilled;

    //score = 0;
    //distance = 1200.76;
    //playagain = 'y';
    //shieldsup = true;
    //lives = 3;
    //alienskilled = 10;
    //double engineTemp = 6572.89;

    //cout << "\n score: "    << score << endl;
    //cout << "distance: "    << distance << endl;
    //cout << "playagain: "     << playagain << endl;
    //cout << "lives: "        << lives << endl;
    //cout << "alienskilled: " << alienskilled << endl;
    //cout << "engineTemp: "  << engineTemp << endl;

    //int fuel;
    //cout << "\nHow much fuel? ";
    //cin >> fuel;
    //cout << "fuel: " << fuel << endl;

    //typedef unsigned short int ushort;
    //ushort bonus = 10;
    //cout << "\nbonus: " << bonus << endl;

    //return 0;

    cout << "Enter two integers: ";
    int Value1;
    int Value2;
    cin >> Value1 >> Value2;
    if (Value1 > Value2) {
        int RememberValue1 = Value1;
        Value1 = Value2;
        Value2 = RememberValue1;
    }
    cout << "The input in sorted order: "
        << Value1 << " " << Value2 << endl;
    int Max;

    if (Value1 < Value2) {
        Max = Value2;
    }
    else {
        Max = Value1;
    }
    cout << "Maximum of inputs is: " << Max << endl;
    
    if (Value1 < 0) {
        cout << Value1 << " is negative" << endl;
    }
    else if (Value1 > 0) {
        cout << Value1 << " is positive" << endl;
    }
    else {
        cout << Value1 << " is zero" << endl;
    }

}

