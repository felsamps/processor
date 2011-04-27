#include <systemc.h>

SC_MODULE(clockgen) {

	sc_out<sc_logic> out;

	SC_CTOR(clockgen) {
		_period = sc_time(2, SC_NS);
		SC_THREAD(compute);
	}

	void set_period(sc_time period) {
		_period = period;
	}

	void compute(void);

	private: sc_time _period;

};
