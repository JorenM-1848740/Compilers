package main;

func test(x, y int) (a, b, c int) {
	print(x, y);
	return x, y, 5;
};

func main() {
	var a, q, s = test(1, 2);
	var b = a;
	print(a, q, s, b)
	a++
	print(a, q, s, b)
	b++
	print(a, q, s, b)
};
