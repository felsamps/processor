#include "and2.h"

void and2::compute() {
	s.write(a.read() & b.read());
}
