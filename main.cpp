#include "processor.h"
#include "clockgen.h"

using namespace std;

int sc_main(int argc, char* argv[])
{

	processor processor("processor");
	clockgen clk("clk");
	sc_signal<sc_logic> clock;

	clk.set_period(sc_time(10, SC_NS));

	clk.out(clock);
	processor.clk(clock);

	/*
	sc_start(sc_time(45, SC_NS));

	sc_trace_file *tf;
	tf = sc_create_vcd_trace_file("main.trace");

	sc_trace(tf,processor.clock,"clk");
	sc_trace(tf,processor.instruction,"instruction");
	*/

	return 0;
};
