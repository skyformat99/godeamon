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

package godeamon

/*
#include "godeamon.h"
*/
import "C"
import "errors"

// Current work directory  will change to /, umask will set to 0 
// Signal: SIGCHLD, SIGHUP will be ignored, stdin, stdout will redirect to /dev/null
func GoDeamon() error {

	i := C.godeamon()
	switch i {
	case C.ERR_FORK:
		return errors.New("Do fork() error")

	case C.ERR_SETSID:
		return errors.New("Do setsid() error")

	case C.ERR_CHDIR:
		return errors.New("Change current work dir error")

	case C.ERR_DUP2:
		return errors.New("Redirect stdin, stdout error")

	case C.ERR_OPEN:
		return errors.New(`Open "/dev/null" error`)

	case C.ERR_CLOSE:
		return errors.New("Close useless fd error")
	}

	return nil
}

