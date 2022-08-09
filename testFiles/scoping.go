package main;

func f1() {
	var b = 6;
}

func f2() {
	var a int = 5;
	f1();
	print(a);
}

func main() {
	f2();
};
