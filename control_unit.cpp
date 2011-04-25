#include "control_unit.h"

void control_unit::compute() {

	switch(opcode.read().to_uint()) {
		case 0: //SUB
			reg_dst.write(SC_LOGIC_1);
			branch.write(SC_LOGIC_0);
			mem_to_reg.write(SC_LOGIC_0);
			mem_read_write.write(SC_LOGIC_X);
			alu_op.write(SC_LOGIC_1);
			alu_src.write(SC_LOGIC_0);
			reg_write.write(SC_LOGIC_1);

		case 1: //ADD
			reg_dst.write(SC_LOGIC_1);
			branch.write(SC_LOGIC_0);
			mem_to_reg.write(SC_LOGIC_0);
			mem_read_write.write(SC_LOGIC_X);
			alu_op.write(SC_LOGIC_0);
			alu_src.write(SC_LOGIC_0);
			reg_write.write(SC_LOGIC_1);

		case 2: //LW			
			reg_dst.write(SC_LOGIC_0);
			branch.write(SC_LOGIC_0);
			mem_to_reg.write(SC_LOGIC_1);
			mem_read_write.write(SC_LOGIC_0);
			alu_op.write(SC_LOGIC_0);
			alu_src.write(SC_LOGIC_1);
			reg_write.write(SC_LOGIC_1);

		case 3: //SW
			reg_dst.write(SC_LOGIC_X);
			branch.write(SC_LOGIC_0);
			mem_to_reg.write(SC_LOGIC_X);
			mem_read_write.write(SC_LOGIC_1);
			alu_op.write(SC_LOGIC_0);
			alu_src.write(SC_LOGIC_1);
			reg_write.write(SC_LOGIC_0);

		case 4: //BEq	
			reg_dst.write(SC_LOGIC_X);
			branch.write(SC_LOGIC_1);
			mem_to_reg.write(SC_LOGIC_X);
			mem_read_write.write(SC_LOGIC_X);
			alu_op.write(SC_LOGIC_1);
			alu_src.write(SC_LOGIC_0);
			reg_write.write(SC_LOGIC_0);
	}
}
