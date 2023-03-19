#include "control_loop.h"

using namespace std;

//the goal is to implement a simple PID controller, 
//running on input value to reach the desired one

// Sense: read a value from keyboard
// Plan:  generate the correct input
// Act:   set the input

double xdes;
double dt;
double P;
double I;
double D;

int main(int argc, char** argv) {

    P=atof(argv[1]);
    I=atof(argv[2]);
    D=atof(argv[3]);
    dt=atof(argv[4]);
    cout<<"Segnale di controllo iniziale: "<<endl;
    cin>>xdes;

    CONTROLLER controllore(P,I,D,xdes,dt);

    while(true){

        cout<<"Segnale di controllo: "<<endl;
        cin>>xdes;
        controllore.set_xdes(xdes);

    }

    return 0;
}