package main

var a int = 0x5;
var z int = 10;
var hex int = 0xff;
var bin int = 0b11;
var oct int = 0o77;
var boolean bool = true;
var sum int = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17 + 18 + 19;
var andtf bool = true && false;
var ortf bool = true || false;
var _ int = 0;

/*
blocks
function declarations
statements: return; if; for; expression; assignment
*/

func intf() int {
	print("intf");
	//short variable declarations
	output := 0;
	for i := 0; i < 10; i++ {
		var temp = fib(i);
		print(temp)
		output += temp;
		print("ok")
	}
	return output;
}

//recursie
func fib(n int) int {
	if n == 0 || n == 1 {
		return 1
	} else {
		return fib(n - 1) + fib(n - 2)
	}
};

func main() {
	print("main")
	//ingebouwde functie print
	print(a, z, hex, bin, oct, boolean, sum, andtf, ortf)
	//function calls
	print(intf(5))
	print(boolf());
	print(stringf());
	print(runef());

	//extra arithmetic en assignment operators
	print("operators")
	print(5 << 3)
	print(123 >> 456)
	print(5 & 3)
	print(123 | 456)
	print(5 ^ 3)
	print(123 &^ 456)
	print(7 % 3)

	//switch statement
	switch x := fib(5) == fib(5); {
	case x:
		print(x, a)
	case false:
		print(1);
	default:
		print(123456789);
	}

	//switch statement
	switch {
	case 1 == 2:
		print("1 == 2")
	case 5 > 3:
		print("5 > 3");
	case "123" == "123":
		print("string comparison")
	default:
		print(123456789);
	}

	switch {
	case "1" == "2":
		print("1 == 2")
	case "123" == "123":
		print("string comparison")
	default:
		print(123456789);
	}
}

func boolf() (a, b bool, bool, bool) {
	print("boolf", a, b)
	a = true
	b = true
	//arithmetic, comparison, assignment, logical operators
	return a&&b, a||b, a==b, a!=b
}

//type string, string concatenation
func stringf() (string) {
	print("stringf")
	//string literals: enkel interpreted
	return "Lorem ipsum" + "\n" + "dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
}

//type rune
func runef() (rune, rune) {
	print("runef")
	//rune literals: enkel 'c' met c een ASCII karakter, of een escaped_char
	return 'a', '\n';
}