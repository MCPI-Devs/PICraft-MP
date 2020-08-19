#include <stdio.h>
#include <string.h>

int big_endian = 0x00;
int little_endian = 0x01;

int endianess()
{
	union
	{
		int i;
		char c[sizeof(int)];
	} x;
	x.i = 1;
	if (x.c[0] == 1)
	{
		return little_endian;
	} else
	{
		return big_endian;
	}
}

int bin2int_d(char* data)
{
	int tint = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
	return tint;
}

int bin2long_d(char* data)
{
	long tlong = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
	return tlong;
}

int bin2longlong_d(char* data)
{
	long long tlonglong = ((long long) data[0] << 56) | ((long long) data[1] << 48) | ((long long) data[2] << 40) | ((long long) data[3] << 32) | ((long long) data[4] << 24) | ((long long) data[5] << 24) | ((long long) data[6] << 8) | (long long) data[7];
	return tlonglong;
}

int bin2short_d(char* data)
{
	short tshort = data[0] | (data[1] << 8);
	return tshort;
}

float bin2float_d(char* data)
{
	int tfloat = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
	return tfloat;
}

int bin2double_d(char* data)
{
	double tdouble = ((long long) data[0] << 56) | ((long long) data[1] << 48) | ((long long) data[2] << 40) | ((long long) data[3] << 32) | ((long long) data[4] << 24) | ((long long) data[5] << 24) | ((long long) data[6] << 8) | (long long) data[7];
	return (double) tdouble;
}

int unpack(char* type, char* data)
{
	if (type == "i")
	{
		bin2int_d(data);
	}
	else if (type == "I")
	{
	} else
	{
		printf("Unknown type: %s\n", type);
		return 0;
	}
}

int main() {
	return 0;
}
