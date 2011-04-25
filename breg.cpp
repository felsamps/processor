#include "breg.h"

void breg::compute() {
	if( reset.read() == '1' ) {
		for(int i=0; i<32; i++) {
			array[i].write(0);
		}
	}
	else {
		if( write.read() == '0' ) {
			out_1.write(array[reg_1.read()].read());
			out_2.write(array[reg_2.read()].read());
		}
		else {
			if( clk.posedge() ) {
				array[reg_w.read()].write(in_w.read());
			}
		}
	}
}
		


