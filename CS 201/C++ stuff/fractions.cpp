#include <iostream>
#include <string>

using namespace std;

class Fraction {
    public:
        Fraction();
        Fraction(int num);
        Fraction(int num, int den);
        void print();
    private:
        int numerator;
        int denominator;

};
Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
}
Fraction::Fraction(int num, int den){
    if (num == 0) {
        numerator = 0;
        denominator = 0;
    } else {
        int t1, t2;

        t1 = num;
        t2 = den;

        while (t1 != t2) {
            if (t1 > t2){
                t1 -= t2;
            } else {
                t2 -= t1;
            }
        }
        numerator = num / t1;
        denominator = den / t2;
    }    
}
Fraction::Fraction(int val){
    numerator = val;
    denominator =1;
}
void Fraction::print(){
    cout << numerator << " / " << denominator << endl;
}

int main(void) {

    return 0;
}