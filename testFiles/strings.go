package main;

func length(x string) (string, int) {
	return x, len(x);
};

func main() {
	a := "Hello there";
	print(a);
	b := "General";
	c := "Kenobi";
	print(b + " \t" + c + "!" + "\n");
	print(len(a));
	print(length(a));
	print("\v\v\v\\\\\'\"\f");
};