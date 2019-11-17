#include <stdlib.h>
#include <string.h>

#include "streamer.h"

static char streamer_peak(const struct streamer *s);
static char streamer_next(struct streamer *s);
static int streamer_eof(const struct streamer *s);

/**
 * 
 * @param buf
 * @return 
 */
struct streamer* streamer_init(const char *buf)
{
	struct streamer *s = calloc(1, sizeof(struct streamer));
	s->buf = buf;
	s->rd_ptr = s->buf;
	s->peak = &streamer_peak;
	s->next = &streamer_next;
	
	return s;
}

/**
 * 
 * @param p
 * @return 
 */
static char streamer_peak(const struct streamer *s)
{
	if (streamer_eof(s))
		return -1;
	
	return *s->rd_ptr;
}

/**
 * 
 * @param p
 * @return 
 */
static char streamer_next(struct streamer *s)
{
	if (streamer_eof(s))
		return -1;
	
	return *s->rd_ptr++;
}

/**
 * 
 * @param s
 * @return 
 */
static int streamer_eof(const struct streamer *s)
{
	if (s->rd_ptr - s->buf == s->size)
		return 1;
	else
		return 0;
}
