package main

import (
	"fmt"
	"log"
	"net"
)

func main() {
	println("start...")

	port := 9090
	listen, err := net.Listen("tcp", fmt.Sprintf(":%d", port))
	if err != nil{
		log.Fatal("listen failed:", port, err)
	}

	for  {
		client, err := listen.Accept()
		if err != nil {
			log.Println("accept failed!")
			continue
		}
		go handle(client)
	}
}

func handle(conn net.Conn)  {
	data := make([]byte, 1024)
	conn.Write([]byte("hello, client!"))

	for  {
		n, err := conn.Read(data[:])
		if err != nil {
			log.Println("read error!")
			return
		}
		fmt.Println(string(data[:n]))
		if(n > 0){
			conn.Write(data[:n])
		}
	}
}
