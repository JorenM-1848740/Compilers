package main;

func returnMultiple() (a, b int) {
	return 1, 2;
};

func main() {
	print();
	print(returnMultiple());
	var a, b int = returnMultiple();
	print(a, b);
};
