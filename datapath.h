#include "systemc.h"
#include "ula.h"
#include "breg.h"
#include "inst_memory.h"
#include "data_memory.h"
#include "registrador.h"



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
	sc_in<sc_logic> breg_write;
	sc_in<sc_uint<5> > breg_reg_1, breg_reg_2, breg_reg_w;
	sc_in<sc_int<32> > breg_in_w;
	sc_out<sc_int<32> > breg_out_1, breg_out_2;

	//IMEM SIGNALS
	sc_in<sc_int<32> > imem_address;
	sc_out<sc_int<32> > imem_data_out;
	
	
	//DMEM SIGNALS
	sc_in<sc_logic> dmem_read_write;
	sc_in<sc_int<32> > dmem_address, dmem_data_in;
	sc_out<sc_int<32> > dmem_data_out;

	ula ula_i;
	breg breg_i;
	inst_memory imem_i;
	data_memory dmem_i;
	registrador pc;

	void compute();

	SC_CTOR(datapath) : ula_i("ula_0"), breg_i("breg_0"), imem_i("imem_0"), dmem_i("dmem_0"), pc("pc_0")	{

		SC_METHOD(datapath);
		sensitive << clk << reset;

		ula_i.a(ula_a);
		ula_i.b(ula_b);
		ula_i.op(ula_op);
		ula_i.s(ula_s);
		ula_i.z_flag(ula_z_flag);

		breg_reg_1.write(imem_data_out.read().range(31,26));

		breg_i.clk(clk);
		breg_i.reset(reset);
		breg_i.write(breg_write);
		breg_i.reg_1(breg_reg_1);
		breg_i.reg_2(breg_reg_2);
		breg_i.reg_w(breg_reg_w);
		breg_i.in_w(breg_in_w);
		breg_i.out_1(breg_out_1);
		breg_i.out_2(breg_out_2);

		imem_i.address(imem_address);
		imem_i.data_out(imem_data_out);

		dmem_i.clk(clk);
		dmem_i.read_write(dmem_read_write);
		dmem_i.address(dmem_address);
		dmem_i.data_in(dmem_data_in);
		dmem_i.data_out(dmem_data_out);

		pc.clk(clk);
		pc.reset(reset);
		pc.q(pc_q);
		pc.d(pc_d);
	}

}
