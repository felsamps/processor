#ifndef DATAPATH_H
#define DATAPATH_H

#include "systemc.h"
#include "ula.h"
#include "breg.h"
#include "inst_memory.h"
#include "data_memory.h"
#include "adder.h"
#include "and2.h"
#include "mux2.h"
#include "mux2_5b.h"
#include "instdec.h"
#include "registrador.h"
#include "signext.h"
#include "shift2.h"

SC_MODULE(datapath) {
	sc_in<sc_logic> clk, reset;
	sc_in<sc_logic> reg_dst, branch, mem_to_reg, mem_read_write, alu_op, alu_src, reg_write;
	sc_out<sc_int<6> > opcode;

	//ULA SIGNALS
	sc_signal<sc_int<32> > ula_a, ula_b;
	sc_signal<sc_logic > ula_op;
	sc_signal<sc_int<32> > ula_s;
	sc_signal<sc_logic > ula_z_flag;

	//BREG SIGNALS
	sc_signal<sc_logic> breg_write;
	sc_signal<sc_int<5> > breg_reg_1, breg_reg_2, breg_reg_w;
	sc_signal<sc_int<32> > breg_in_w;
	sc_signal<sc_int<32> > breg_out_1, breg_out_2;

	//IMEM SIGNALS
	sc_signal<sc_int<32> > imem_address;
	sc_signal<sc_int<32> > imem_data_out;
	
	
	//DMEM SIGNALS
	sc_signal<sc_logic> dmem_read_write;
	sc_signal<sc_int<32> > dmem_address, dmem_data_in;
	sc_signal<sc_int<32> > dmem_data_out;

	sc_signal<sc_int<32> > s_adder_pc;

	//INSTRUCTION DECOMPOSITION
	sc_signal<sc_int<6> > inst_31_26;
	sc_signal<sc_int<5> > inst_25_21, inst_20_16, inst_15_11;
	sc_signal<sc_int<16> > inst_15_0;

	sc_signal<sc_logic> s_and;
	sc_signal<sc_int<32> > s_mux_2, pc_q, pc_d, const_4, out_shift2, s_adder_br, in_shift2, out_mux_2;

	ula ula_i;
	breg breg_i;
	inst_memory imem_i;
	data_memory dmem_i;
	registrador pc;
	adder adder_pc, adder_br;
	instdec instdec_i;
	mux2 mux_1, mux_2, mux_3;
	shift2 shift2_i;
	and2 and2_i;
	signext signext_i;
	mux2_5b mux_0;

	SC_CTOR(datapath) : signext_i("signext_0"), and2_i("and2_0"), shift2_i("shift2_0"), mux_0("mux_0"), mux_1("mux_1"), mux_2("mux_2"), mux_3("mux_3"), instdec_i("instdec_0"), adder_pc("adder_0"), adder_br("adder_1"), ula_i("ula_0"), breg_i("breg_0"), imem_i("imem_0"), dmem_i("dmem_0"), pc("pc_0")	{


		ula_i.a(breg_out_1);
		ula_i.b(s_mux_2);
		ula_i.op(ula_op);
		ula_i.s(ula_s);
		ula_i.z_flag(ula_z_flag);

		breg_i.clk(clk);
		breg_i.reset(reset);
		breg_i.write(breg_write);
		breg_i.reg_1(inst_25_21);
		breg_i.reg_2(inst_20_16);
		breg_i.reg_w(breg_reg_w);
		breg_i.in_w(breg_in_w);
		breg_i.out_1(breg_out_1);
		breg_i.out_2(breg_out_2);

		imem_i.address(imem_address);
		imem_i.data_out(imem_data_out);

		dmem_i.clk(clk);
		dmem_i.read_write(dmem_read_write);
		dmem_i.address(ula_s);
		dmem_i.data_in(dmem_data_in);
		dmem_i.data_out(dmem_data_out);

		pc.clk(clk);
		pc.reset(reset);
		pc.q(pc_q);
		pc.d(pc_d);

		adder_pc.a(pc_d);
		adder_pc.b(const_4);
		adder_pc.s(s_adder_pc);

		adder_br.a(s_adder_pc);
		adder_br.b(out_shift2);
		adder_br.s(s_adder_br);

		mux_1.a(s_adder_pc);
		mux_1.b(s_adder_br);
		mux_1.sel(s_and);
		mux_1.s(pc_q);
		
		signext_i.in(inst_15_0);
		signext_i.out(in_shift2);

		shift2_i.in(in_shift2);
		shift2_i.out(out_shift2);

		instdec_i.instruction(imem_data_out);
		instdec_i.inst_31_26(inst_31_26);
		instdec_i.inst_25_21(inst_25_21);
		instdec_i.inst_20_16(inst_20_16);
		instdec_i.inst_15_11(inst_15_11);
		instdec_i.inst_15_0(inst_15_0);

		mux_0.a(inst_20_16);
		mux_0.b(inst_15_11);
		mux_0.sel(reg_dst);
		mux_0.s(breg_reg_w);

		mux_2.a(breg_out_2);
		mux_2.b(in_shift2);
		mux_2.sel(alu_src);
		mux_2.s(out_mux_2);

		mux_3.a(dmem_data_out);
		mux_3.b(ula_s);
		mux_3.sel(mem_to_reg);
		mux_3.s(breg_in_w);

		and2_i.a(branch);
		and2_i.b(ula_z_flag);
		and2_i.s(s_and);

	}

};

#endif
