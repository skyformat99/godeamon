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

package main

import (
	"github.com/tcpandip/godeamon"
	"time"
	"fmt"
)

func main() {

	println("Start init godeamon.")

	err := godeamon.GoDeamon()
	if err != nil {
		println(err.Error())
	} else {
		// stderr not close or redirect, so println() will print 
		println(`Success, use "ps -aux | grep EXAMPLE_NAME" to see detail`)
		for {
			fmt.Println("Running...")
			time.Sleep(5 * time.Second)
		}
	}

}
