#include "systemc.h"

SC_MODULE(data_memory) {
	sc_in<sc_logic> clk, read_write;
	sc_in<sc_int<32> > address, data_in;
	sc_out<sc_int<32> > data_out;

	sc_signal<sc_int<32> > array[1024];

	void compute();

	SC_CTOR(data_memory) {
		SC_METHOD(compute);
		sensitive << clk.pos() << address;
	}
};
