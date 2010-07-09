#ifndef __UTIL_HASH_H__
#define __UTIL_HASH_H__

/**
 * Hash the given string, where
 *     h[i] = k * h[i-1] + s[i-1]
 *     h[0] = h0
 */
unsigned int hash_str(const char *s, unsigned int h0, unsigned int k);

#define HASH_FUNC(fnname, h0, k) \
static inline unsigned int fnname(const char *s) { \
    return hash_str(s, h0, k); \
}

/**
 * A hash function reported by Dan J Bernstein on comp.lang.c in the early
 * 1990s.
 * See <http://groups.google.com/group/comp.lang.c/msg/6b82e964887d73d9>
 */
HASH_FUNC(hash_djb2, 5381, 33);

/**
 * The hash function used for the sdbm database engine.
 * See <http://github.com/davidar/sdbm>
 */
HASH_FUNC(hash_sdbm, 0, 65599);

/**
 * The hash function used in K&R 2nd ed.
 */
HASH_FUNC(hash_knr2, 0, 31);

/**
 * The hash function used in K&R 1st ed.
 */
HASH_FUNC(hash_knr1, 0, 1);

#endif
