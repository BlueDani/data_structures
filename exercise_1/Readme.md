# Exercise 1

Given an integer array nums sorted in non-decreasing order, return an array of
the squares of each number sorted in non-decreasing order.

## Example 1
**Input:** nums = [-4,-1,0,3,10]<br>
**Output:** [0,1,9,16,100]<br>
**Explanation:** After squaring, the array becomes [16,1,0,9,100].<br>
After sorting, it becomes [0,1,9,16,100].<br>

## Example 2
**Input:** nums = [-7,-3,2,3,11]<br>
**Output:** [4,9,9,49,121]<br>

## Constraints
* 1 <= nums.length <= 104<br>
* -104 <= nums[i] <= 104<br>
* nums is sorted in non-decreasing order.<br>

> Squaring each element and sorting the new array is very trivial, could you
find an [O(n)](https://adrianmejia.com/most-popular-algorithms-time-complexity-every-programmer-should-know-free-online-tutorial-course/) solution using a different approach?