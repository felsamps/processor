#include "clockgen.h"

void clockgen::compute(void) {
	while(1) {
		out.write(sc_logic('0'));
		wait(_period/2);
		out.write(sc_logic('1'));
		wait(_period/2);
	}
}
