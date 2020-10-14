// package main
//
// import (
// 	"fmt"
// 	"strconv"
// 	"sync"
// )
//
// var wg sync.WaitGroup
//
// func main() {
// 	chopsticks := make([]*Chopstick, 5)
// 	for i := 0; i < 5; i++ {
// 		chopsticks[i] = new(Chopstick)
// 	}
//
// 	philosopers := make([]*Philosoper, 5)
// 	for i := 0; i < 5; i++ {
// 		philosopers[i] = &Philosoper{number: i + 1, leftChopstick: chopsticks[i], rightChopstick: chopsticks[(i+1)%5]}
// 	}
//
// 	for i := 0; i < 5; i++ {
// 		wg.Add(1)
// 		go philosopers[i].eat()
// 	}
//
// 	wg.Wait()
// }
//
// type Chopstick struct {
// 	sync.Mutex
// }
//
// type Philosoper struct {
// 	number                        int
// 	leftChopstick, rightChopstick *Chopstick
// }
//
// func (p Philosoper) eat() {
// 	for i := 0; i < 3; i++ {
// 		p.leftChopstick.Lock()
// 		p.rightChopstick.Lock()
//
// 		fmt.Println("Starting to Eat --> " + strconv.Itoa(p.number))
//
// 		p.leftChopstick.Unlock()
// 		p.rightChopstick.Unlock()
//
// 		fmt.Println("Finishing Eating -->" + strconv.Itoa(p.number),"\n")
// 	}
// 	wg.Done()
// }


package main

import (
	"fmt"
	"sync"
    "time"
)
type ChopS struct {
	sync.Mutex
}
type Philos struct {
	num, count int
	leftcs,rightcs *ChopS
}

func (p Philos) eat(c chan *Philos, wg *sync.WaitGroup) {
	for i:=0;i<3;i++ {
			c <- &p
			if (p.count < 3) {
			p.leftcs.Lock()
			p.rightcs.Lock()

			fmt.Println("starting to eat ",p.num)
			p.count = p.count + 1
			fmt.Println("finishing eating",p.num)
			p.rightcs.Unlock()
			p.leftcs.Unlock()
			wg.Done()
			}

	}
}

func host(c chan *Philos, wg *sync.WaitGroup) {
	for {
		if  (len(c)==2) {
		<- c
		<- c
		//time delay
		time.Sleep(20 * time.Millisecond)
		}
	}
}

func main() {
	var i int
	var wg sync.WaitGroup
	c := make(chan *Philos,2)

	wg.Add(15)

	ChopSticks := make([] *ChopS,5)
	for i=0;i<5;i++ {
		ChopSticks[i] = new(ChopS)
	}

	Philosophers := make([] *Philos,5)
	for i=0;i<5;i++ {
		Philosophers[i] = &Philos{i+1,0,ChopSticks[i],ChopSticks[(i+1)%5]}
	}

	go host(c,&wg)
	for i=0;i<5;i++ {
		go Philosophers[i].eat(c,&wg)
	}
	wg.Wait()
}
