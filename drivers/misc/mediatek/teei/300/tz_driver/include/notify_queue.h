/*
 * Copyright (c) 2015-2019, MICROTRUST Incorporated
 * All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef NOTIFY_QUEUE_H
#define NOTIFY_QUEUE_H

#include <linux/types.h>

struct NQ_head {
	unsigned long long nq_type;
	unsigned long long max_count;
	unsigned long long put_index;
	unsigned long long reserve[5];
};

struct NQ_entry {
	unsigned long long cmd_ID;
	unsigned long long sub_cmd_ID;
	unsigned long long block_p;
	unsigned long long param[5];
};

int add_nq_entry(unsigned long long cmd_ID, unsigned long long sub_cnd_ID,
			unsigned long long block_p, unsigned long long p0,
			unsigned long long p1, unsigned long long p2);

int add_bdrv_nq_entry(unsigned long long cmd_ID, unsigned long long sub_cnd_ID,
			unsigned long long block_p, unsigned long long p0,
			unsigned long long p1, unsigned long long p2);

struct NQ_entry *get_nq_entry(void);

int create_nq_buffer(void);
int set_soter_version(void);
void secondary_init_cmdbuf(void *info);
int show_t_nt_queue(void);

extern unsigned long long switch_input_index;
extern unsigned long long switch_output_index;

#endif /* end of NOTIFY_QUEUE_H */
