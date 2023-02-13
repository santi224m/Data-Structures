# Chapter 1 - Asymptotic Notation

* Big O expresses the upperbound of an algorithm's running time (worst case scenario)
* Big O is used to compare the running time of different algorithms to allow you to decide which one is the fastest
* Big Omega(Ω) does the opposite of Big O; it measures the lowerbound of an algorithm's running time, which is the best case scenario

* Theta Notation: when a function ```f(n)``` is bounded both from the top and bottom by the function ```g(n)```, then it is said that ```f(n)``` is theta of ```g(n)``` "```f(n) = Θ(g(n))```"
* **Little O Notation** - represents a loose boudning version of Big O, where ```g(n)``` bounds ```f(n)``` from the top, but not the bottom
* Little Omega Notation: ```g(n)``` is a loose lower boundary of ```f(n)```; it bounds from the bottom, but not the top

* Algorithms can be measured for both time as well as space
* Some algorithms behave differently with small amounts of data as they do with large amounts of data, so you have to make a trade off based on how much data you expect your algorithm to handle

* When finding the Big O of an algorithm, you can discard any constants from the equation
  For example: ```O(2n)``` = ```O(n)```

