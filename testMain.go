package main;

func fib(n int) (int) {
	var a bool = n == 0;
	var b bool = n == 1;
	var c bool = a || b;
	if (c) {
		return 1;
	} else {
		var left int = fib(n - 1);
		var right int = fib(n - 2);
		return left + right;
	}
};

func main() {
	print(fib(8));
};