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

#ifndef PACKETS_H
#define PACKETS_H

typedef struct base_packet_t {
	unsigned char prefix;
	unsigned char iteration;
	unsigned char padding[2];
	unsigned char encapsulation;
	unsigned char length;
} base_packet_t;

typedef struct raw_packet_t {
	base_packet_t base;

	unsigned char* data;
} raw_packet_t;

typedef struct q_packet_t {
	base_packet_t base;

	unsigned char padding[3];
	unsigned char id;
	unsigned char* data;
} q_packet_t;

typedef struct s_packet_t {
	base_packet_t base;

	unsigned char padding[7];
	unsigned char id;
	unsigned char* data;
} s_packet_t;

typedef union mcpi_packet_t {
	raw_packet_t raw;
	q_packet_t q;
	s_packet_t s;
} mcpi_packet_t;

#endif /* PACKETS_H */
