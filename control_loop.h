#include <iostream>
#include <fstream>

#include "boost/thread.hpp"

using namespace std;

class CONTROLLER {
    public:
        CONTROLLER(double , double ,double, double , double );
        
        void loop();                //Main loop function        
        void system_start();       //start the system
        void set_xdes(double x){
            _xdes=x;}   //member to set the desired value

    private:
        double _P;
        double _I;
        double _D;
        double _xdes;
        double _y;
        double _u;
        double _dt;
};