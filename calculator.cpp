#include <iostream>
using namespace std;

long long int factorial(int n) {
    long long int p=1;
    for(int i=1;i<=n;i++){
        p=p*i;
    }
    return p;
}

long double exponent(double a, int b) {
    long double p=1;
    for(int i=0;i<b;i++){
        p=p*a;
    }
    return p;
}

double sine(double x){
    double s=0;
    int b=0;
    for(int m=1;m<=19;m=m+2){
        s=s+(exponent(-1,b)*exponent(x,m))/factorial(m);
        b++;
    
    }
    return s;
}

double cos(double x) {
    double s = 0;
    int k = 0;
    for (int i = 0; i <= 20; i = i+2) {
        s = s + (exponent(-1, k)*exponent(x, i))/factorial(i);
        k++;
    }
    return s;
}

void algebra(int x) {
    double a;
    double b;
    cout << "Ok. Please enter the two numbers you want to perform operations on separated by a space: ";
    cin >> a >> b;
    switch (x) {
        case 1:
            cout << a+b << endl;
            break;
        case 2:
            cout << a-b << endl;
            break;
        case 3:
            cout << a*b << endl;
            break;
        case 4:
            cout << a/b << endl;
            break;
        case 5:
            cout << exponent(a, b) << endl;
            break;
    }
    return;
}

void trigonometry(int num) {
    double c;
    cout << "Please enter the argument: ";
    cin >> c;
    switch(num) {
        case 6:
            if(c>-6.28318 && c<6.28318){
                cout<<sine(c) << endl;
            }
            else{
                int m=c/6.28318;
                cout<<sine(c-(6.28318*m)) << endl;
            }
            break;
        case 7:
            if (c > -6.28318 && c < 6.28318) {
                cout << cos(c) << endl;
            }
            else {
                int pre_result = c/6.28318;
                double result = c - (pre_result*6.28318);
                cout << cos(result) << endl;
            }
            break;
        case 8:
            if(c>-6.28318 && c<6.28318){
                cout<<sine(c)/cos(c) << endl;
            }
            else{
                int pre_result = c/6.28318;
                double result = c - (pre_result*6.28318);
                int m=c/6.28318;
                cout<<sine(c-(6.28318*m))/cos(result) << endl;
            }
            break;
    }
    
    return;
}

int main() {
    // Write C++ code
    int num;
    cout << "Welcome to calculator!" << endl;
    cout << "Enter 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division, 5 for exponent, 6 for sin, 7 for cos, 8 for tan." << endl;
    cout << "Please enter a number corresponding to the operation: ";
    cin >> num;
    if (num <6 && num >0) {
        algebra(num);
        cout << "Do you want to continue? Enter 1 to continue or press 0 to exit: ";
        int exit_num;
        cin >> exit_num;
        switch(exit_num) {
            case 0:
                cout << "Exitting calculator..." << endl;
                break;
            case 1:
                main();
                break;
            default:
                cout << "Invalid input. Exitting calculator..." << endl;
        }
    }
    
    else if(num >5 && num <=8) {
        trigonometry(num);
        cout << "Do you want to continue? Enter 1 to continue or press 0 to exit: ";
        int exit_num;
        cin >> exit_num;
        switch(exit_num) {
            case 0:
                cout << "Exitting calculator..." << endl;
                break;
            case 1:
                main();
                break;
            default:
                cout << "Invalid input. Exitting calculator..." << endl;
        }
    }
    
    else {
        cout << "You have to enter a number between 1 and 8. Please try again." << endl;
        main();
    }
    
    return 0;
}