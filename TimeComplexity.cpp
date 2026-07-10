/* 
The rate at which the the time increases with respect to various input size.
Time
40-|             *
-|
30-|      *
-|
20-| *
-|
10-|
-|___|____|______|_______|______|__
    20    40     60      80     100  Input ize


The angle betweeen time and input size is theta that is time complexity.
The time complexity can be calculated in terms of "BigO" and can be expressed as "O(time)".
Example-
for(i=1;i<n;i++){
cout<<"Ayush"<<endl;

}
here three operation performed 
1. i<n
2. i++
3. cout<< Ayush
so BigO is= O(n*3)=O(3n)

******************************************ALGORITHMS FOR CALCULATING TIME COMPLEXITY****************************************************
1.Take always worst case scenorio.
2. Avoid Constant
3. Avoid Lower value.
************************************************CASES IN TIME COMPLEXITY*********************************************************
1. Best case: The best case is the minimum time complexity of an algorithm.
2. Average case: The average case is the average time complexity of an algorithm.[(Best+Worst)/2]
3. Worst case: The worst case is the maximum time complexity of an algorithm.



*****************************************************EXAMPLE****************************************************
if(m>25){
cout<<"D";
}
else if(m<50){
cout<<"C";
}
else if(m<70){
cout<<"B";
}
else if(m<100){
cout<<"A";
}


So for this code 1. Best case is-O(1)
                 2. Worst case is-O(4)
*/  

/*
******************************************       SPACE COMPLEXITY          *********************************************************************************
space complexity = Auxillary space  +  Input space
Auxillary space = space used by the algorithm(means to solve the problem)
Input space = space used by the input
suppose we have three variabel a,b,c and  we have to perform  add opertaion on a and b and we stores the value in c then,
a,b- Input Space
c-Auxillary space.
*/