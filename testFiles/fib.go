package main

func fib(n int) int {
	if n == 0 || n == 1 {
		return 1
	}
	return fib(n - 1) + fib(n - 2)
};

func main() {
	print(fib(8))
}
