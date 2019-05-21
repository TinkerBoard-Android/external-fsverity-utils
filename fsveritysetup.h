/* SPDX-License-Identifier: GPL-2.0+ */
#ifndef FSVERITYSETUP_H
#define FSVERITYSETUP_H

#include "util.h"

struct fsveritysetup_params {
	const struct fsverity_hash_alg *hash_alg;
	u8 *salt;
	size_t saltlen;
	int blocksize;
	int blockbits;			/* ilog2(blocksize) */
	unsigned int hashes_per_block;	/* blocksize / digest_size */
	const char *signing_key_file;
	const char *signing_cert_file;
	const char *signature_file;
};

void fsverity_append_extension(void **buf_p, int type,
			       const void *ext, size_t extlen);

#define FSVERITY_EXTLEN(inner_len)	\
	ALIGN(sizeof(struct fsverity_extension) + (inner_len), 8)

/* sign.c */
int append_signed_measurement(struct filedes *out,
			      const struct fsveritysetup_params *params,
			      const u8 *measurement);

#endif /* FSVERITYSETUP_H */
