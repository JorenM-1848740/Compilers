package main

var n int;

func factorial(n int) int {  
	
	var factVal int = 1
	var i int = 1

    if(n < 0){
        print(0)    
    }else{        
        for i=1; i<=n; i++ {
            factVal *= i  
        }        
    }    
    return factVal
}

func main(){    
    var n int = 10
	n /= 2;
	print(factorial(n))
}
