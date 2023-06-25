package main

import "fmt"

func TestRoutine(ch chan *int) {
	var testVar int = 123
	defer func() { ch <- &testVar }()
	fmt.Printf("TestRoutine - testVar:%v\n", testVar)
}

func main() {
	var ch chan *int = make(chan *int)
	go TestRoutine(ch)
	var res *int = <-ch
	close(ch)
	fmt.Printf("main - testVar:%v\n", *res)
}
