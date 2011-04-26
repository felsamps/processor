#include "systemc.h"

SC_MODULE(and2) {
	sc_in<sc_logic> a,b;
	sc_out<sc_logic> s;

	void compute();

	SC_CTOR(and2) {
		SC_METHOD(compute);
		sensitive << a << b;
	}
};
