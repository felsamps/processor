#include "systemc.h"

SC_MODULE(control_unit) {
	sc_in<sc_logic> clk;
	sc_in<sc_int<6> > opcode;
	sc_out<sc_logic> reg_dst, branch, mem_to_reg, mem_read_write, alu_op, alu_src, reg_write;

	void compute();

	SC_CTOR(control_unit) {
		SC_METHOD(compute);
		sensitive << clk;
	}
};

