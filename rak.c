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

#include <rak.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int rak_handle_ping(rak_config_t config, struct sockaddr_in addr, unsigned char* packet)
{
	return 0;
}

int rak_run(int port, char* motd)
{
	int rt;
	struct sockaddr_in addr;
	struct sockaddr_in client_addr;
	int client_len = sizeof(client_addr);
	char buffer[2048];
	rak_config_t config;

	config.fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (config.fd < 0)
	{
		fprintf(stderr, "Error while opening socket.\n");
		return -1;
	}
	config.motd = motd;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, TRUE, sizeof(int));
	memset((char*)&addr, 0x00, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);
	rt = bind(config.fd, (struct sockaddr*)&addr, sizeof(addr));
	if (rt < 0)
	{
		fprintf(stderr, "Error while binding.\n");
		return -1;
	}

	while (TRUE)
	{
		memset(buffer, 0x00, 2048);
		rt = recvfrom(config.fd, buffer, 2048, 0, (struct sockaddr*)&client_addr, &client_len);
		switch (buffer[0])
		{
			case 0x01:
			case 0x02:
				rak_handle_ping(config.fd, client_addr, buffer);
			break;
		}
	}
	close(config.fd);
	return 0;
}
