package main

func fib(n int) (a int) {
	
	a = 1;
	if n == 0 || n == 1 {
		
		return 
	}
	a = fib(n - 1) + fib(n - 2)
	return
};

func returns2() (int, int){
	return 0, 0
}

func main() {
	var i int;

	var a, j, k int= fib(10), returns2()
	print(j)
	
}
