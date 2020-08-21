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

#ifndef MISC_H
#define MISC_H

#define TRUE (1)
#define FALSE !(TRUE)

#define BOLD "\x1b[1m"
#define OBFUSCATED ""
#define ITALIC "\x1b[3m"
#define UNDERLINE "\x1b[4m"
#define STRIKETHROUGH "\x1b[9m"
#define RESET "\x1b[m"
#define BLACK "\x1b[38;5;16m"
#define DARKBLUE "\x1b[38;5;19m"
#define DARKGREEN "\x1b[38;5;34m"
#define DARKAQUA "\x1b[38;5;37m"
#define DARKRED "\x1b[38;5;124m"
#define PURPLE "\x1b[38;5;127m"
#define GOLD "\x1b[38;5;214m"
#define GRAY "\x1b[38;5;145m"
#define DARKGRAY "\x1b[38;5;59m"
#define BLUE "\x1b[38;5;63m"
#define GREEN "\x1b[38;5;83m"
#define AQUA "\x1b[38;5;87m"
#define RED "\x1b[38;5;203m"
#define LIGHTPURPLE "\x1b[38;5;207m"
#define YELLOW "\x1b[38;5;227m"
#define WHITE "\x1b[38;5;231m"

typedef enum text_style_t {
	INFO,
	ERROR
} text_style_t;

typedef union all_the_t {
	short tshort;
	int tint;
	long long tlong;
	float tfloat;
	double tdouble;
	unsigned short tushort;
	unsigned int tuint;
	unsigned long long tulong;
} all_the_t;

all_the_t unpack(int endianess, void* data);

#endif /* MISC_H */
