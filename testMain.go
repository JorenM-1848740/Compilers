package main;

var a int = 0;
var z int = 10;
var hex int = 0;
var bin int = 0;
var oct int = 0;
var boolean bool = true;
var sum int = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19;
var andtf bool = true && false;
var ortf bool = true || false;
var bruh int = 5;

func main() {
	var b int = 5;
	var c int = a + b;

	print(a, b, c, z);
	
	var a1, z1 int = a, z;
	print(a1, z1);
	a1++;
	z1++
	print(a1, z1);
	print(true, false);

	if (true) {
		var abc int = 123;
		abc++;
		print(abc);
	}

	test();
	print(bruh);
}

func test() {
	bruh++;
};