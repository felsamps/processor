#include "systemc.h"

SC_MODULE(instdec) {
	sc_in<sc_int<32> > instruction;
	sc_out<sc_int<6> > inst_31_26;
	sc_out<sc_int<5> > inst_25_21, inst_20_16, inst_15_11;
	sc_out<sc_int<16> > inst_15_0;

	void compute();

	SC_CTOR(instdec) {
		SC_METHOD(compute);
		sensitive << instruction;
	}
};


