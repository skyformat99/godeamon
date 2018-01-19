# godeamon
Run golang program as deamon


## Start using it

1. Download and install it:

```sh
$ go get github.com/ipandtcp/godeamon
```

2. Import it in your code:

```go
import "github.com/ipandtcp/godeamon"
```

## [Example](https://github.com/ipandtcp/godeamon/blob/master/example/example.go)

```go
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
```

```
$ go build
$ ./example
$ ps -aux | grep example
```

## Note

- (1): Support Linux only
- (2): Current work directory  will change to /,
- (3): umask will set to 0
- (4): Signal: SIGCHLD, SIGHUP will be ignored
- (5): stdin, stdout will redirect to /dev/null

