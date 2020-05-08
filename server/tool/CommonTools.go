package tool

func ParseName(buff []byte, n int) string{
	idx := 0
	for i := 0; i < n * 8; i++ {
		if buff[i] == 0{
			idx = i
			break
		}
	}
	return string(buff[:idx])
}
