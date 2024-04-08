
#include "wood.h"
void do_it(wood3 w) {
    string s;
    cout << "example: y=a*x+b" << endl;
    cout << "y= ";
    cin >> s;
    w.TransformToWood(s);
    int start, finish;
    cout << "start of interval: ";
    cin >> start;
    cout << "finish of interval: ";
    cin >> finish;
    w.PrintWood();
    cout << " for min= " << start << " and max= " << finish << " min value= " << w.FindExtremMin(w.First3, start, 
    finish) << " max value= " << w.FindExtremMax(w.First3, start, finish);
}
void do_it(wood2 w) {
    string s;
    cout << "example: y=a*x^2+b*x+c" << endl;
    cout << "y= ";
    cin >> s;
    w.TransformToWood(s);
    int start, finish;
    cout << "start of interval: ";
    cin >> start;
    cout << "finish of interval: ";
    cin >> finish;
    w.PrintWood();
    cout << " for min= " << start << " and max= " << finish << " min value= " << w.FindExtremMin(w.First2, start, 
    finish) << " max value= " << w.FindExtremMax(w.First2, start, finish);
}
void do_it(wood1 w) {
    string s;
    cout << "example: y=(a*x+b)/(c*x+d)" << endl;
    cout << "y= ";
    cin >> s;
    w.TransformToWood(s);
    int start, finish;
    cout << "start of interval: ";
    cin >> start;
    cout << "finish of interval: ";
    cin >> finish;
    w.PrintWood();
    if (w.FindExtremMax(w.First1,start,finish)!= 999999999)
    cout << " for min= " << start << " and max= " << finish << " min value= " << w.FindExtremMin(w.First1, start, 
    finish) << " max value= " << w.FindExtremMax(w.First1, start, finish);
    else cout << " for min= " << start << " and max= " << finish << " min value= -infinity" << " max value= infinity";

}
int main() {

    int i = 0;
    cout << "*************analitic func*************" << endl << "you can analyze 3 tips of function:" << endl;
    cout << "1) (a*x+b)/(c*x+d) " << endl << "2) a*x^2+b*x+c" << endl << "3) a*x+b" << endl;
    cout << " choose tip:";
    cin >> i;

    switch (i) {
    case 3: { wood3 w; do_it(w); }
    break;
    case 2: { wood2 w; do_it(w); }
    break;
    case 1: { wood1 w; do_it(w); }
    break;
    default:
    break;
    }
};
