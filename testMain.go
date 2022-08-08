package main

var (t3, t4 int = 3, 5; t5 int = 6;);
var t7 bool = false;
var t9 = (t7 || false);
var t6 int = testing(testing2());
var tt = FibonacciRecursion(20);
var ttt = forLoop(10);

func main(a int) (b int){
    var n int;
    var t1 = 4 +6
    var t2  = 5;
    var bbb int;
    var i int;
    
    return 5;

    
}

func zeroReturn(){
    return
}

func forLoop(a int)int{
    var i int;
    for i = 0;i<10;i++{
        print(i);
    }
    print(FibonacciRecursion());
    return 5;
}

func FibonacciRecursion(n int) int {
    if n <= 1 {
        return n
    }
    return FibonacciRecursion(n-1) + FibonacciRecursion(n-2)
}

func testing(d int, e bool) (t3 int){

    return d;
}

func testing2() (a int, b bool){

    var t3 = 0;
    t3++;
    
    return t3, true;
}
