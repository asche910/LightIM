package main

import (
	"fmt"
	"github.com/asche910/LightIM/server/tool"
	"log"
	"net"
)

var (
	clientMap = make(map[string]net.Conn)
)

func main() {
	println("server start...")

	port := 9090
	listen, err := net.Listen("tcp", fmt.Sprintf(":%d", port))
	if err != nil {
		log.Fatal("listen failed:", port, err)
	}

	for {
		client, err := listen.Accept()
		fmt.Printf("%s connected!\n", client.RemoteAddr().String())
		if err != nil {
			log.Println("accept failed!")
			continue
		}
		if login(client) {
			//client.Write([]byte("hello,client!"))
			go handle(client)
		} else {
			log.Println("login failed!")
		}
	}
}

func login(conn net.Conn) bool {
	data := make([]byte, 1024)
	n, _ := conn.Read(data[:])
	username := string(data[:n])
	fmt.Println(fmt.Sprintf("%s login success!", username))
	clientMap[username] = conn
	return true
}

func handle(conn net.Conn) {
	data := make([]byte, 1024)
	//conn.Write([]byte("hello, client!"))

	for {
		_, err := conn.Read(data[:])
		if err != nil {
			log.Println("read error!", err)
			//clientMap[]
			break
		}

		//from := tool.ParseName(data[8:24], 16)
		target := tool.ParseName(data[24:40], 16)
		targetConn := clientMap[target]
		if targetConn == nil {
			fmt.Println("target server doesn't exist!")
		} else {
			_, err = targetConn.Write(data)
			if err != nil {
				fmt.Println("write failed:", err)
			}
		}
	}
	fmt.Println("disconnect!")
}
