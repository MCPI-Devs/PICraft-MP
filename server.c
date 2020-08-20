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
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <packets.h>
#include <misc.h>

static int terminated;

/* Segfaulty method. */
char* get_current_time()
{
	char* tmp_str = malloc(11);
	time_t now = time(NULL);
	struct tm *now_tm = localtime(&now);
	int now_h = now_tm->tm_hour;
	int now_m = now_tm->tm_min;
	int now_s = now_tm->tm_sec;

	sprintf(tmp_str, "%02d:%02d:%02d", now_h, now_m, now_s);
	return tmp_str;
}

int logger(text_style_t type, char* message)
{
	if (type == INFO)
	{
		printf(BLUE "INFO => " AQUA "%s \n" RESET, message);
	} else if (type == ERROR)
	{
		printf(RED "ERROR => " AQUA "%s \n" RESET, message);
	}
	return 0;
}

int command_interpreter()
{
	size_t line_size;
	char* input;

	printf("> ");
	getline(&input, &line_size, stdin);
	if (strcmp(input, "help\n") == 0)
	{
		logger(INFO, "helpcommand");
	} else if (strcmp(input, "stop\n") == 0)
	{
		logger(INFO, "stopcommand");
		terminated = TRUE;
	} else
	{
		logger(ERROR, "Invalid Command!");
	}
	return 0;
}

int main(int argc, char* argv[])
{
	while (!terminated)
	{
		command_interpreter();
		continue;
	}
	return 0;
}
