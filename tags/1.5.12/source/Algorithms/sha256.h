/*
* Copyright (C) 2001 Niels Moller
*
* The nettle library is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2.1 of the License, or (at your
* option) any later version.
*
* The nettle library is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
* License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with the nettle library; see the file COPYING.LIB.  If not, write to
* the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
* MA 02111-1307, USA.
*/

#ifndef __SHA256_H
#define __SHA256_H
/*
*  Copyright (C) 2007-2008 Sourcefire, Inc.
*
*  Authors: Tomasz Kojm
*
*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License version 2 as
*  published by the Free Software Foundation.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
*  MA 02110-1301, USA.
*/

#include "../stdafx.h"

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef signed short int16_t;
typedef unsigned short uint16_t;

typedef signed int int32_t;
typedef unsigned int uint32_t;

typedef signed long long int64_t;
typedef unsigned long long uint64_t;



#define SHA256_DIGEST_SIZE 32
#define SHA256_DATA_SIZE 64

/* Digest is kept internally as 8 32-bit words. */
#define _SHA256_DIGEST_LENGTH 8

typedef struct sha256_ctx
{
	uint32_t state[_SHA256_DIGEST_LENGTH];    /* State variables */
	uint32_t count_low, count_high;           /* 64-bit block count */
	unsigned char block[SHA256_DATA_SIZE];          /* SHA256 data buffer */
	uint32_t index;                       /* index into buffer */
} SHA256_CTX;

void
sha256_init(struct sha256_ctx *ctx);

void
sha256_update(struct sha256_ctx *ctx, const unsigned char *data, uint32_t length);

void
sha256_final(struct sha256_ctx *ctx);

void
sha256_digest(const struct sha256_ctx *ctx, unsigned char *digest);

void
sha256_digest(const struct sha256_ctx *ctx, CString* sDigest);

#endif
