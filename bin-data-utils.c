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
	int tint; 
	tint = data[0];
	tint |= data[1] << 8;
	tint |= data[2] << 16;
	tint |= data[3] << 24;
	return tint;
}

long bin2long_d(char* data)
{
	long tlong; 
	tlong = data[0];
	tlong |= data[1] << 8;
	tlong |= data[2] << 16;
	tlong |= data[3] << 24;
	return tlong;
}

long long bin2longlong_d(char* data)
{
	long long tlonglong;
	tlonglong = (long long) data[0];
	tlonglong |= (long long) data[1] << 8;
	tlonglong |= (long long) data[2] << 16;
	tlonglong |= (long long) data[3] << 24;
	tlonglong |= (long long) data[4] << 32;
	tlonglong |= (long long) data[5] << 40;
	tlonglong |= (long long) data[6] << 48;
	tlonglong |= (long long) data[7] << 56;
	return tlonglong;
}

short bin2short_d(char* data)
{
	short tshort;
	tshort = data[0]; 
	tshort |= data[1] << 8;
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

char bin2char_d(char* data)
{
	char tchar;
	tchar = data[0];
	return tchar;
}

int bin2schar_d(char* data)
{
	int tchar;
	tchar = data[0];
	return tchar;
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
