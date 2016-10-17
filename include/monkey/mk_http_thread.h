/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Monkey HTTP Server
 *  ==================
 *  Copyright 2001-2016 Monkey Software LLC <eduardo@monkey.io>
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

#ifndef MK_HTTP_THREAD_H
#define MK_HTTP_THREAD_H

#include <monkey/mk_http.h>
#include <monkey/mk_thread.h>

struct mk_http_thread {
    struct mk_http_session *session;  /* HTTP session            */
    struct mk_http_request *request;  /* HTTP request            */
    struct mk_thread       *parent;   /* Parent thread           */
    struct mk_list _head;             /* Link to worker->threads */
};

static MK_INLINE void mk_http_thread_resume(struct mk_thread *thread)
{
    mk_thread_resume(thread);
}

struct mk_http_thread *mk_http_thread_new(struct mk_plugin *plugin,
                                          struct mk_http_session *session,
                                          struct mk_http_request *request,
                                          int n_params,
                                          struct mk_list *params);
int mk_http_event(struct mk_event *event);

#endif
