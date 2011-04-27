#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "systemc.h"
#include "control_unit.h"
#include "datapath.h"

SC_MODULE(processor) {
	sc_in<sc_logic> clk, reset;
		
	sc_signal<sc_logic> reg_dst, branch, mem_to_reg, mem_read_write, alu_op, alu_src, reg_write;
	sc_signal<sc_int<6> > opcode;

	control_unit control;
	datapath path;
	
	SC_CTOR(processor) : control("control_0"), path("path_0")	{
		
		control.clk(clk);
		control.opcode(opcode);
		control.reg_dst(reg_dst);
		control.branch(branch);
		control.mem_to_reg(mem_to_reg);
		control.mem_read_write(mem_read_write);
		control.alu_op(alu_op);
		control.alu_src(alu_src);
		control.reg_write(reg_write);		

		path.clk(clk);
		path.reset(reset);
		path.reg_dst(reg_dst);
		path.branch(branch);
		path.mem_to_reg(mem_to_reg);
		path.mem_read_write(mem_read_write);
		path.alu_op(alu_op);
		path.alu_src(alu_src);
		path.reg_write(reg_write);		
		
	}
};

#endif
