#include "systemc.h"

SC_MODULE(inst_memory) {
	sc_in<sc_int<32> > address;
	sc_out<sc_int<32> > data_out;

	sc_signal<sc_int<32> > array[1024];

	void compute();

	SC_CTOR(inst_memory) {
		SC_METHOD(compute);
		sensitive << address;
	}
};
