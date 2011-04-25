#include "data_memory.h"

void data_memory::compute() {
	if( read_write.read() == '0' ) { //READ
		data_out.write(array[address.read()].read());
	}
	else { //WRITE
		if( clk.posedge() ) {
			array[address.read()].write(data_in.read());
		}
	}
}	
		
