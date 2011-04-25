#include "systemc.h"

SC_MODULE(breg) {
	sc_in<sc_logic> clk, reset, write;
	sc_in<sc_uint<5> > reg_1, reg_2, reg_w;
	sc_in<sc_int<32> > in_w;
	sc_out<sc_int<32> > out_1, out_2;
	
	sc_signal<sc_int<32> > array[32];

	void compute();

	SC_CTOR(breg) {
		SC_METHOD(compute);
		sensitive << reset << reg_1 << reg_2 << clk.pos();
	}
};

