/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   streamer.h
 * Author: Daniel Machon
 *
 * Created on 15. november 2019, 21:16
 */

#ifndef STREAMER_H
#define STREAMER_H


struct streamer {
	const char *buf;			//Data buffer
	const char *rd_ptr;			//Read pointer
	int size;				//Size of buffer
	char (*peak)(const struct streamer *);	//Function pointer
	char (*next)(struct streamer *);	//Function pointer
};

struct streamer* streamer_init(const char *buf);

#endif /* STREAMER_H */

