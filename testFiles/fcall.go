package main;

func test(x int, z int) (a, b int) {
	a, b = 1, 2
	return;
};

func main() {
	var a int = 5;
	var b int = 6;

	test(a, b);
	print(a, b);
	print(test(a, b));
};
