package main;

func test(x, y int) (a, b, c int) {
	return a, c, 5;
};

func main() {
	var a, q, s int = test(1, 2);
	var b = a;
	a++
	b++
};