#include "control_loop.h"

//We can use the class constructor to set parameters
CONTROLLER::CONTROLLER(double P, double I, double D, double xdes, double dt) {

    _P=P;
    _I=I;
    _D=D;
    set_xdes(xdes);
    _dt=dt;

    boost::thread loop_thread(&CONTROLLER::loop,this);

}


//Sense: get input to change the state of our System

//Random initial value
void CONTROLLER::system_start() {
    
    srand((unsigned)time(NULL));
    _y=rand()/(RAND_MAX+1.0);

}

void CONTROLLER::loop() {

double err=0, P_err=0, I_err=0,D_err=0, old_err=0;
system_start();
_u=0;
int N=0;

//valori iniziali
ofstream f_y("y-txt");
ofstream f_error("error.txt");
f_y<<"";
f_error<<"";
f_error.close();
f_y.close();


cout<<"L'uschita inizile: "<<_y<<"\n L'ingresso iniziale: "<<_u<<"\n";

f_y.open("y-txt");
f_error.open("Error.txt");

while( abs(err-old_err)>0.001 || N==0){

//trascrizione dei campioni

f_y<<_y<<endl;
f_error<<err<<endl;



//controllore
old_err=err;
err=_xdes-_y;
P_err=err;
I_err=I_err+err*_dt;
D_err=(err-old_err)/_dt;
_u=_P*P_err+_I*I_err+_D*D_err;
_y=_u;


cout<<"Misurazione sull'uscita "<<_y<<"\n";
cout<<"Errore: "<<err<<"\n";
cout<<"all'istante: "<<N*_dt<<"\n";
usleep(0.1e5);
N++;
}

f_error.close();
f_y.close();

cout<<"tempo di inseguimento del riferimento cd ..:"<<N*_dt<<"\n";

}

