package main;

func f() int {
	switch x := 5>6; {
	case x:
		return 5
	case false:
		return 1
	default:
		return 123456789
	}
}

func main() {
	print(f())
};