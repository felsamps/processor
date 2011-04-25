#include "systemc.h"

SC_MODULE(registrador) {
	sc_in<sc_logic> clk, reset;
	sc_in<sc_int<32> > d;
	sc_out<sc_int<32> > q;

	void compute();

	SC_CTOR(registrador) {
		SC_METHOD(compute);
		sensitive << clk.pos() << reset;
	}
};

