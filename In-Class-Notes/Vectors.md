## Feb 16, 2023 In-Class Notes

# Vectors

* In a vector implementation, we have to keep track of the size, capactity, and a pointer to an array that is holding the elements
* We have to be able to resize the vector by creating a new array of the size we need and copying the elements in the current array to the new array. Once we are done copying the elements, we have to deallocate the old array
* Each time we have to increase the space in the vector, we double the capacity
* We make the capacity bigger than the size so that we don't have to resize and copy each time we need to add an element to the array
* When the size is less than 1/3 of the capacity, we shrink the array by half
* The Big O of ```push_back(x)``` would be **O()** because when we have to expand the array we have to copy ```n``` elements to the new array
* Even thought expanding the array by one element rather than doubling it would still be **O(n)**, doubling is still better in amortized time (averaged time)
* The amortized time for ```push_back(x)``` is **O(1)***
* Big O and Amortized time are not the same, Big O is the worst case scenario while Amortized is an average
* To insert an element into an array, you have to shift all the elements after the index one position to the right and then set the element at the index equal to the new element
* To delete an element from an array, you shift all elements after the element being deleted one position to the left, and then decrease the size by 1
  * The element at the end will stay, but since the size was decreased it cannot be accessed
