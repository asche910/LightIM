package main

import (
	"bufio"
	"bytes"
	"encoding/binary"
	"fmt"
	"github.com/asche910/LightIM/server/tool"
	"net"
	"os"
	"time"
)

var(
	username string
	port = 9090
	scanner = bufio.NewScanner(os.Stdin)
)

func main() {
	fmt.Println("client start...")
	test()

	server, err := net.Dial("tcp", fmt.Sprintf(":%d", port))
	if err != nil{
		fmt.Println("dial failed:", err)
		return
	}

	fmt.Println("Login name:")
	scanner.Scan()
	username = scanner.Text()
	// login
	_, _ = server.Write([]byte(username))

	go readMsg(server)
	for  {
		fmt.Println("Input user to chat:")
		scanner.Scan()
		target := scanner.Text()
		fmt.Println("Input msg:")
		scanner.Scan()
		msg := scanner.Text()

		buffer := buildMeg(target, msg)
		_, _ = server.Write(buffer.Bytes())
	}
}

func readMsg(conn net.Conn)  {
	data := make([]byte, 1024)
	for  {
		_, err := conn.Read(data)
		if err != nil{
			fmt.Println("read error:", err)
			break
		}

		timestamp := int64(binary.BigEndian.Uint64(data[:8]))
		msgTime := time.Unix(timestamp, 0)
		fmt.Print(msgTime.Format("2006-01-02 15:04:05"))

		from := tool.ParseName(data[8: 24], 16)
		fmt.Printf(" %s:\n", from)

		lenBuf := data[40:42]
		length := int16(binary.BigEndian.Uint16(lenBuf))
		fmt.Println(string(data[42:42 + length]))
		//var mySlice = []byte{0, 0, 0, 0, 0, 0, 0, 23}
		//data := binary.BigEndian.Uint64(mySlice)
	}
}

func buildMeg(target , content string) bytes.Buffer {
	var buf bytes.Buffer

	timeBuf := make([]byte, 8)
	timestamp := time.Now().Unix()
	binary.BigEndian.PutUint64(timeBuf, uint64(timestamp))
	buf.Write(timeBuf)

	fromBuf := make([]byte, 16)
	targetBuf := make([]byte, 16)
	copy(fromBuf, username)
	copy(targetBuf, target)
	buf.Write(fromBuf)
	buf.Write(targetBuf)

	var length = len(content)
	lenBuf := make([]byte, 2)
	lenBuf[0], lenBuf[1]  = uint8(length >> 8), uint8(length & 0xff)
	buf.Write(lenBuf)

	buf.Write([]byte(content))
	return buf
}

func test()  {

}