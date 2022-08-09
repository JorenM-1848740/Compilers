package main;

var a int = 3;

func test(x int) int {
	var a int = 2;
	print(a);
	for ; a < 10; a = a + 1 {
		print(a);
		a = a * 3;
		print(a);
	}

	return a;
}

func test2() {
	a = 4;
	print(a);
};

func test3() {
	a = 5;
	print(a);
};

func main() {
	print(a);
	test2();
	test(5);
	print(a);
	test3();
	print(a);
};