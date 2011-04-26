#include "instdec.h"

void instdec::compute() {
	inst_31_26.write(instruction.read().range(31,26));
	inst_25_21.write(instruction.read().range(25,21));
	inst_20_16.write(instruction.read().range(20,16));
	inst_15_0.write(instruction.read().range(15,0));
}

