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

#ifndef HANDLERS_H
#define HANDLERS_H

typedef int (*handler_t)(int fd, mcpi_packet_t packet);

handler_t handlers[53]; /* 52 documented packets + weird ping packet. */

#endif /* HANDLERS_H */
