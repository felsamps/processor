#include "systemc.h"

SC_MODULE(ula) {
	sc_in<sc_int<32> > a, b;
	sc_in<sc_logic > op;
	sc_out<sc_int<32> > s;
	sc_out<sc_logic > z_flag;

	sc_signal<sc_int<32> > sig_s;

	void compute();

	SC_CTOR(ula){
		SC_METHOD(compute);
		sensitive << a << b << op;

	}
};


