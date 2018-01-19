/*
 * Copyright (C) 2018  Kevin Zhu
 * Direct questions, comments to  <ipandtcp@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef GO_DEAMON_H
#define GO_DEAMON_H

#define OK          0
#define ERR_FORK   -1
#define ERR_SETSID -2
#define ERR_CHDIR  -3
#define ERR_DUP2   -4
#define ERR_OPEN   -5
#define ERR_CLOSE  -6

int godeamon();

#endif
