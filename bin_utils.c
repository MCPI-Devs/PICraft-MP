/*   ____ ___ ____            __ _        __  __ ____  
 *  |  _ \_ _/ ___|_ __ __ _ / _| |_     |  \/  |  _ \ 
 *  | |_) | | |   | '__/ _` | |_| __|____| |\/| | |_) |
 *  |  __/| | |___| | | (_| |  _| ||_____| |  | |  __/ 
 *  |_|  |___\____|_|  \__,_|_|  \__|    |_|  |_|_|    
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <misc.h>

#define BIG_ENDIAN 0x00
#define LITTLE_ENDIAN 0x01

void check_length(char* data, int len)
{
	int data_len = strlen(data);
	if (data_len != len)
	{
		printf("Expected %d, got %d", len, data_len);
		exit(1);
	}
}

int get_endianess()
{
	union
	{
		int i;
		char c[sizeof(int)];
	} x;
	x.i = 1;

	return x.c[0] == 1 ? LITTLE_ENDIAN : BIG_ENDIAN;
}

int flip_int_endianess(int value)
{
	return (value >> 24) | (value << 8) & 0x00FF0000 | (value >> 8) & 0x00FF0000 | (value << 24);
}

unsigned int flip_uint_endianess(unsigned int value)
{
	return (value >> 24) | (value << 8) & 0x00FF0000 | (value >> 8) & 0x00FF0000 | (value << 24);
}

long long flip_long_endianess(long long value)
{
	long long flipped_long;
	flipped_long = value >> 56; 
	flipped_long |= (value << 40) & 0x00FF000000000000;
	flipped_long |= (value << 24) & 0x0000FF0000000000;
	flipped_long |= (value << 8) & 0x000000FF00000000;
	flipped_long |= (value >> 8) & 0x00000000FF000000;
	flipped_long |= (value >> 24) & 0x0000000000FF0000;
	flipped_long |= (value >> 40) & 0x000000000000FF00;
	flipped_long |= value << 56;
	return flipped_long;
}

unsigned long long flip_ulong_endianess(unsigned long long value)
{
	unsigned long long flipped_long;
	flipped_long = value >> 56; 
	flipped_long |= (value << 40) & 0x00FF000000000000;
	flipped_long |= (value << 24) & 0x0000FF0000000000;
	flipped_long |= (value << 8) & 0x000000FF00000000;
	flipped_long |= (value >> 8) & 0x00000000FF000000;
	flipped_long |= (value >> 24) & 0x0000000000FF0000;
	flipped_long |= (value >> 40) & 0x000000000000FF00;
	flipped_long |= value << 56;
	return flipped_long;
}

short flip_short_endianess(short value)
{
	return (value >> 8) | (value << 8);
}

unsigned short flip_ushort_endianess(unsigned short value)
{
	return (value >> 8) | (value << 8);
}

int bin2int_d(char* data)
{
	check_length(data, 4);
	return data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
}

unsigned int bin2uint_d(char* data)
{
	check_length(data, 4);
	return (unsigned int)(data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24));
}

long long bin2long_d(char* data)
{
	check_length(data, 8);
	long long tlong;
	tlong = (long long)data[0] | (long long)data[1] << 8 | (long long)data[2] << 16 | (long long)data[3] << 24;
	tlong |= (long long)data[4] << 32 | (long long)data[5] << 40 | (long long)data[6] << 48 | (long long)data[7] << 56;
	return tlong;
}

unsigned long long bin2ulong_d(char* data)
{
	check_length(data, 8);
	long long tlong;
	tlong = (long long)data[0] | (long long)data[1] << 8 | (long long)data[2] << 16 | (long long)data[3] << 24;
	tlong |= (long long)data[4] << 32 | (long long)data[5] << 40 | (long long)data[6] << 48 | (long long)data[7] << 56;
	return (unsigned long long)tlong;
}

short bin2short_d(char* data)
{
	check_length(data, 2);
	return data[0] | data[1] << 8;
}

unsigned short bin2ushort_d(char* data)
{
	check_length(data, 2);
	return (unsigned short)(data[0] | data[1] << 8);
}

float bin2float_d(char* data)
{
	check_length(data, 4);
	float tfloat;
	memcpy(&tfloat, data, sizeof(float));
	return tfloat;
}

double bin2double_d(char* data)
{
	check_length(data, 8);
	double tdouble;
	memcpy(&tdouble, data, sizeof(double));
	return tdouble;
}

int bin2bool_d(char* data)
{
	check_length(data, 1);
	return data[0] >= 1 ? 1 : 0;
}

int bin2int_b(char* data)
{
	return get_endianess() == BIG_ENDIAN ? bin2int_d(data) : flip_int_endianess(bin2int_d(data));
}

unsigned int bin2uint_b(char* data)
{
	return get_endianess() == BIG_ENDIAN ? bin2uint_d(data) : flip_uint_endianess(bin2uint_d(data));
}

long long bin2long_b(char* data)
{
	return get_endianess() == BIG_ENDIAN ? bin2long_d(data) : flip_long_endianess(bin2long_d(data));
}

unsigned long long bin2ulong_b(char* data)
{
	return get_endianess() == BIG_ENDIAN ? bin2ulong_d(data) : flip_ulong_endianess(bin2ulong_d(data));
}

/* TODO: Implement different endianesses. */
all_the_t unpack(int endianess, void* data)
{
	all_the_t final;
	char* buffer = data;

	final.tshort = bin2short_d(buffer);
	final.tint = bin2int_d(buffer);
	final.tlong = bin2long_d(buffer);
	final.tfloat = bin2float_d(buffer);
	final.tdouble = bin2double_d(buffer);
	final.tushort = bin2ushort_d(buffer);
	final.tuint = bin2uint_d(buffer);
	final.tulong = bin2ulong_d(buffer);
	return final;
}

