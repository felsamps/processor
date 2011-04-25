#include "inst_memory.h"

void inst_memory::compute() {
	data_out.write(array[address.read()].read());
}	
		
