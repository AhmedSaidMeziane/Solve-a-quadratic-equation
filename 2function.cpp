#include<iostream>
#include<cmath>
#include<limits>
using namespace std;

struct Value_Eqation{
    int x2; // معامل a
    int x1; // معامل b
    int c;  // معامل c
};

int input_number(){
    int x; 
    cin >> x;
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> x;
    }
    return x;
}

void x2_x1_c(Value_Eqation &eq){
    cout<<"Enter coefficient of x^2 (a): \n";
    eq.x2 = input_number();
    cout<<"Enter coefficient of x^1 (b): \n";
    eq.x1 = input_number();
    cout<<"Enter constant (c): \n";
    eq.c = input_number();
}

double Calculate_delta(Value_Eqation eq){
    return pow(eq.x1,2) - 4.0*(eq.x2 * eq.c);
}

double Value_x1(Value_Eqation eq){
    double delta = Calculate_delta(eq);
    return ((-eq.x1) - sqrt(delta)) / (2.0*eq.x2 );
}

double Value_x2(Value_Eqation eq){
    double delta = Calculate_delta(eq);
    return ((-eq.x1) + sqrt(delta)) / (2.0*eq.x2 );
}

void process(Value_Eqation &eq){
    double delta = Calculate_delta(eq);
    if(delta > 0){
        cout<<"x1: "<<Value_x1(eq)<<"\n";
        cout<<"x2: "<<Value_x2(eq)<<"\n";
    } else if(delta == 0){
        cout<<"One repeated solution: "<< (-eq.x1)/(2.0*eq.x2) <<"\n";
    } else {
        cout<<"No real solution\n";
    }
}

int main(){
    Value_Eqation eq;
    x2_x1_c(eq);
    process(eq);
    return 0;
}
