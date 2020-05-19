#pragma once

void _reverse(double* a) {
	*a = 1 / (*a);
	return;
}

void _reverse(double& a) {
	a = 1 / a;
	return;
}

void _reverse(float* a) {
	*a = 1 / (*a);
	return;
}

void _reverse(float& a) {
	a = 1 / a;
	return;
}

void float_int(double* a) {
	*a -= (int)(*a);
	return;
}

void float_int(double& a) {
	a -= (int)(a);
	return;
}

void float_int(float* a) {
	*a -= (int)(*a);
	return;
}

void float_int(float& a) {
	a -= (int)(a);
	return;
}