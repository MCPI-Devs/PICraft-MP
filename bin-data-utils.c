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

int bin2uint_d(char* data)
{
	unsigned int tint; 
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

long bin2ulong_d(char* data)
{
	unsigned long tlong; 
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

long long bin2ulonglong_d(char* data)
{
	unsigned long long tlonglong;
	tlonglong = (unsigned long long) data[0];
	tlonglong |= (unsigned long long) data[1] << 8;
	tlonglong |= (unsigned long long) data[2] << 16;
	tlonglong |= (unsigned long long) data[3] << 24;
	tlonglong |= (unsigned long long) data[4] << 32;
	tlonglong |= (unsigned long long) data[5] << 40;
	tlonglong |= (unsigned long long) data[6] << 48;
	tlonglong |= (unsigned long long) data[7] << 56;
	return tlonglong;
}

short bin2short_d(char* data)
{
	short tshort;
	tshort = data[0]; 
	tshort |= data[1] << 8;
	return tshort;
}

short bin2ushort_d(char* data)
{
	unsigned short tshort;
	tshort = data[0]; 
	tshort |= data[1] << 8;
	return tshort;
}

float bin2float_d(char* data)
{
	union
	{
		char stream[4];
		float tfloat;
	} b2f;
	b2f.stream[0] = data[0];
	b2f.stream[1] = data[1];
	b2f.stream[2] = data[2];
	b2f.stream[3] = data[3];
	return b2f.tfloat;
}

double bin2double_d(char* data)
{
	union
	{
		char stream[8];
		double tdouble;
	} b2f;
	b2f.stream[0] = data[0];
	b2f.stream[1] = data[1];
	b2f.stream[2] = data[2];
	b2f.stream[3] = data[3];
	b2f.stream[4] = data[4];
	b2f.stream[5] = data[5];
	b2f.stream[6] = data[6];
	b2f.stream[7] = data[7];
	return b2f.tdouble;
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

int bin2uchar_d(char* data)
{
	unsigned int tchar;
	tchar = data[0];
	return tchar;
}

int bin2bool_d(char* data)
{
	int tbool;
	tbool = data[0] >= 1 ? 1 : 0;
	return tbool;
}

int unpack(char* type, char* data)
{
	if (type == "i")
	{
		bin2int_d(data);
	}
	else if (type == "I")
	{
		bin2uint_d(data);
	}
	else if (type == "l")
	{
		bin2long_d(data);
	}
	else if (type == "L")
	{
		bin2ulong_d(data);
	}
	else if (type == "q")
	{
		bin2longlong_d(data);
	}
	else if (type == "Q")
	{
		bin2ulonglong_d(data);
	}
	else if (type == "h")
	{
		bin2short_d(data);
	}
	else if (type == "H")
	{
		bin2ushort_d(data);
	}
	else if (type == "c")
	{
		bin2char_d(data);
	}
	else if (type == "b")
	{
		bin2schar_d(data);
	}
	else if (type == "B")
	{
		bin2uchar_d(data);
	}
	else if (type == "?")
	{
		bin2bool_d(data);
	} else
	{
		printf("Unknown type: %s\n", type);
		return 0;
	}
}

int main() {
	return 0;
}
