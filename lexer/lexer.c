/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <string.h>

#include "streamer/streamer.h"

static int lexer_have_token(const char *buf);

struct lexer {
	struct streamer *s;
};

struct lexer* lexer_init()
{
	struct lexer *l = calloc(1, sizeof(struct lexer));
	return l;
}

const char* lexer_get_token(struct lexer *l)
{
	struct streamer *s = l->s;
	const char *token;
	static char buf[1024];			//Should be maximum length of token
	
	for (;;) {
		//Lets find that token!
		char c = s->next(s);
		if (c == ' ')
			continue;
		buf[strlen(buf)] = c;
		if (lexer_have_token(buf))
			return buf;
		else
			continue;
		
	}
}

static int lexer_have_token(const char *buf)
{
	
}

