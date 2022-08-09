package main

func fibonaci(i int) (ret int) {
   if i == 0 {
      return 0
   }
   if i == 1 {
      return 1
   }
   ret = fibonaci(i-1) + fibonaci(i-2)
   return
}

func main() {
   var i int;
   for i = 0; i < 100; i++ {
      print(fibonaci(i))
   }
}
