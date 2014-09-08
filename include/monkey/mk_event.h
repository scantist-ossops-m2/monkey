/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Monkey HTTP Server
 *  ==================
 *  Copyright 2001-2014 Monkey Software LLC <eduardo@monkey.io>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef MK_EVENT_H
#define MK_EVENT_H

struct mk_event_fd_state {
    int fd;
    int mask;
};

typedef struct {
    int size;
    struct mk_event_fd_state *states;
} mk_event_fdt_t;

typedef struct {
    int size;
    void *data;
} mk_event_loop_t;

/* Event types */
#define MK_EVENT_SLEEP      0
#define MK_EVENT_READ       1
#define MK_EVENT_WRITE      2

/* Events behaviors */
#define MK_EVENT_LEVEL    256
#define MK_EVENT_EDGE     512

#endif
