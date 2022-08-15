package main

func fib(n int) (a int) {
	
	a = 1;
	if n == 0 || n == 1 {
		
		return 
	}
	a = fib(n - 1) + fib(n - 2)
	return
};

func main() {
	print(fib(10)+fib(10));
}
