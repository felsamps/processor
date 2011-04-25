#include "systemc.h"

SC_MODULE(shift2) {
	sc_in<sc_int<32> > in;
	sc_out<sc_int<32> > out;

	void compute();

	SC_CTOR(shift2) {
		SC_METHOD(compute);
		sensitive << in;
	}
};
