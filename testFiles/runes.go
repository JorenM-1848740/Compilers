package main

func test(a rune) rune {
	a++;
	return a;
}

func main() {
	print('a' + 3)
	print(test('a'));
}
