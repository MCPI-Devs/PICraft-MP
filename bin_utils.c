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

#include <arpa/inet.h>

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

	return x.c[0] == 1 ? LITTLE_END : BIG_END;
}

int flip_int_endianess(int value)
{
	return (value >> 24) | ((value << 8) & 0x00FF0000) | ((value >> 8) & 0x00FF0000) | (value << 24);
}

unsigned int flip_uint_endianess(unsigned int value)
{
	return (value >> 24) | ((value << 8) & 0x00FF0000) | ((value >> 8) & 0x00FF0000) | (value << 24);
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

// Still expiremental
float flip_float_endianess(float value)
{
	union
	{
		float f;
		int i;
	} flip;
	flip.f = value;
	flip.i = htonl(flip.i);
	return flip.f;		
}

// Still expiremental
float flip_double_endianess(double value)
{
	union
	{
		double d;
		long long l;
	} flip;
	flip.d = value;
	flip.l = htonl(flip.l);
	return flip.d;		
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
	return get_endianess() == BIG_END ? bin2int_d(data) : flip_int_endianess(bin2int_d(data));
}

unsigned int bin2uint_b(char* data)
{
	return get_endianess() == BIG_END ? bin2uint_d(data) : flip_uint_endianess(bin2uint_d(data));
}

long long bin2long_b(char* data)
{
	return get_endianess() == BIG_END ? bin2long_d(data) : flip_long_endianess(bin2long_d(data));
}

unsigned long long bin2ulong_b(char* data)
{
	return get_endianess() == BIG_END ? bin2ulong_d(data) : flip_ulong_endianess(bin2ulong_d(data));
}

short bin2short_b(char* data)
{
	return get_endianess() == BIG_END ? bin2short_d(data) : flip_short_endianess(bin2short_d(data));
}

unsigned short bin2ushort_b(char* data)
{
	return get_endianess() == BIG_END ? bin2ushort_d(data) : flip_ushort_endianess(bin2ushort_d(data));
}

float bin2float_b(char* data)
{
	return get_endianess() == BIG_END ? bin2float_d(data) : flip_float_endianess(bin2float_d(data));
}

double bin2double_b(char* data)
{
	return get_endianess() == BIG_END ? bin2double_d(data) : flip_double_endianess(bin2double_d(data));
}

int bin2int_l(char* data)
{
	return get_endianess() == LITTLE_END ? bin2int_d(data) : flip_int_endianess(bin2int_d(data));
}

unsigned int bin2uint_l(char* data)
{
	return get_endianess() == LITTLE_END ? bin2uint_d(data) : flip_uint_endianess(bin2uint_d(data));
}

long long bin2long_l(char* data)
{
	return get_endianess() == LITTLE_END ? bin2long_d(data) : flip_long_endianess(bin2long_d(data));
}

unsigned long long bin2ulong_l(char* data)
{
	return get_endianess() == LITTLE_END ? bin2ulong_d(data) : flip_ulong_endianess(bin2ulong_d(data));
}

short bin2short_l(char* data)
{
	return get_endianess() == LITTLE_END ? bin2short_d(data) : flip_short_endianess(bin2short_d(data));
}

unsigned short bin2ushort_l(char* data)
{
	return get_endianess() == LITTLE_END ? bin2ushort_d(data) : flip_ushort_endianess(bin2ushort_d(data));
}

float bin2float_l(char* data)
{
	return get_endianess() == LITTLE_END ? bin2float_d(data) : flip_float_endianess(bin2float_d(data));
}

double bin2double_l(char* data)
{
	return get_endianess() == LITTLE_END ? bin2double_d(data) : flip_double_endianess(bin2double_d(data));
}

/* TODO: Implement different endianesses. */
all_the_t unpack(int endianess, void* data)
{
	all_the_t final;
	char* buffer = data;

	final.tshort = (endianess == BIG_END ? bin2short_b(buffer) : bin2short_l(buffer));
	final.tint = (endianess == BIG_END ? bin2int_b(buffer) : bin2int_l(buffer));
	final.tlong = (endianess == BIG_END ? bin2long_b(buffer) : bin2long_l(buffer));
	final.tfloat = (endianess == BIG_END ? bin2float_b(buffer) : bin2float_l(buffer));
	final.tdouble = (endianess == BIG_END ? bin2double_b(buffer) : bin2double_l(buffer));
	final.tushort = (endianess == BIG_END ? bin2ushort_b(buffer) : bin2ushort_l(buffer));
	final.tuint = (endianess == BIG_END ? bin2uint_b(buffer) : bin2uint_l(buffer));
	final.tulong = (endianess == BIG_END ? bin2ulong_b(buffer) : bin2ulong_l(buffer));
	return final;
}
