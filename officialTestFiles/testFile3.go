package main

func findGreatestNumber(a int, b int, c int) int{
	if a > b && a > c {
        return a
    } else if b > a && b > c {
        return b
    } else if c > a && c > b {
        return c
    } else {
        return 0
    }
}

func main() {

    var a, b, c int = 4, 2, 19
	print(findGreatestNumber(a, b, c));

    
}
