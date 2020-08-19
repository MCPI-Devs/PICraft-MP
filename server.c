/*   ____ ___ ____            __ _        __  __ ____  
 *  |  _ \_ _/ ___|_ __ __ _ / _| |_     |  \/  |  _ \ 
 *  | |_) | | |   | '__/ _` | |_| __|____| |\/| | |_) |
 *  |  __/| | |___| | | (_| |  _| ||_____| |  | |  __/ 
 *  |_|  |___\____|_|  \__,_|_|  \__|    |_|  |_|_|    
 *
 *
 * Copyright Alvarito050506, MFDGaming 2020
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
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <packets.h>

#define TRUE ((void*)1)
#define FALSE !(TRUE)

static volatile int terminated;

char* text_format(char* format)
{
	if (format == "BOLD")
	{
		return "\x1b[1m";
	}
	else if (format == "OBFUSCATED")
	{
		return "";
	}
	else if (format == "ITALIC")
	{
		return "\x1b[3m";
	}
	else if (format == "UNDERLINE")
	{
		return "\x1b[4m";
	}
	else if (format == "STRIKETHROUGH")
	{
		return "\x1b[9m";
	}
	else if (format == "RESET")
	{
		return "\x1b[m";
	}
	else if (format == "BLACK")
	{
		return "\x1b[38;5;16m";
	}
	else if (format == "DARKBLUE")
	{
		return "\x1b[38;5;19m";
	}
	else if (format == "DARKGREEN")
	{
		return "\x1b[38;5;34m";
	}
	else if (format == "DARKAQUA")
	{
		return "\x1b[38;5;37m";
	}
	else if (format == "DARKRED")
	{
		return "\x1b[38;5;124m";
	}
}

int main(int argc, char* argv[])
{
	while (!terminated)
	{
		continue;
	}
	return 0;
}