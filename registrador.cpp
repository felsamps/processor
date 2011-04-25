#include "registrador.h"

void registrador::compute() {
	if( reset.read() == '1' ) {
		q.write('0');
	}
	q.write(d.read());	
}

