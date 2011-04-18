#include "ula.h"

void ula::compute() {
	if( op.read() == SC_LOGIC_0 ) { //ADD OPERATION
		sig_s.write(a.read() + b.read());
	}
	else { //SUB OPERATION
		sig_s.write(a.read() - b.read());
	}

	if( sig_s.read() == 0 ) { //ZERO FLAG TEST
		z_flag.write(SC_LOGIC_1);
	}
	else {
		z_flag.write(SC_LOGIC_0);
	}
	
	s.write(sig_s); 
}

