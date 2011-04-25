#include "shift2.h"

void shift2::compute() {
	int temp = in.read() << 2;
	out.write(temp);
}
