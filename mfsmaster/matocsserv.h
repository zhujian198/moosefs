/*
   Copyright 2008 Gemius SA.

   This file is part of MooseFS.

   MooseFS is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, version 3.

   MooseFS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with MooseFS.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MATOCSSERV_H_
#define _MATOCSSERV_H_
#include <inttypes.h>

void matocsserv_usagedifference(double *minusage,double *maxusage,uint16_t *usablescount,uint16_t *totalscount);
uint16_t matocsserv_getservers_ordered(void* ptrs[65535],double maxusagediff,uint32_t *min,uint32_t *max);
uint16_t matocsserv_getservers_wrandom(void* ptrs[65535],uint16_t demand);
void matocsserv_getspace(uint64_t *totalspace,uint64_t *availspace);
int matocsserv_getlocation(void *a,uint32_t *servip,uint16_t *servport);
uint32_t matocsserv_cservlist_size(void);
void matocsserv_cservlist_data(uint8_t *ptr);
int matocsserv_send_replicatechunk(void *e,uint64_t chunkid,uint32_t version,void *from);
int matocsserv_send_deletechunk(void *e,uint64_t chunkid,uint32_t version);
int matocsserv_send_createchunk(void *e,uint64_t chunkid,uint32_t version);
int matocsserv_send_setchunkversion(void *e,uint64_t chunkid,uint32_t version,uint32_t oldversion);
int matocsserv_send_duplicatechunk(void *e,uint64_t chunkid,uint32_t version,uint64_t oldchunkid,uint32_t oldversion);
int matocsserv_send_truncatechunk(void *e,uint64_t chunkid,uint32_t length,uint32_t version,uint32_t oldversion);
int matocsserv_send_duptruncchunk(void *e,uint64_t chunkid,uint32_t version,uint64_t oldchunkid,uint32_t oldversion,uint32_t length);
void matocsserv_broadcast_logstring(uint64_t version,uint8_t *logstr,uint32_t logstrsize);
void matocsserv_broadcast_logrotate();
int matocsserv_init(void);

#endif