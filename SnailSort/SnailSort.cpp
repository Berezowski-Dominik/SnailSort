// SnailSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Snail Sort
Given an n x n array, return the array elements arranged from
outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]

This image will illustrate things more clearly:

NOTE: The idea is not sort the elements from the lowest value to the highest; the
idea is to traverse the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].

*/

#include <iostream>
#include <vector>

using namespace std;

std::vector<int> snail(const std::vector<std::vector<int>>& snail_map)
{
    if (snail_map[0].empty())
    { 
        vector <int> expected;
        return expected;
    }

    int size_vector = snail_map.size();

    vector <int> expected(size_vector * size_vector);       //  if input vetor 2d have size 5x5 return must have 25

    int counterWhile = 0;                                   //  counter main loop while

    int counterElements = 0;                                //  counter in return vector

    while (size_vector > 0)
    {
        --size_vector;

        for (int i = counterWhile; i <= size_vector; i++)
        {
            expected[counterElements] = snail_map[counterWhile][i];
            counterElements++;
        }

        for (int i = (1 + counterWhile); i <= size_vector; i++)
        {
            expected[counterElements] = snail_map[i][size_vector];
            counterElements++;
        }

        for (int i = (size_vector - 1); counterWhile <= i ; i--)
        {
            expected[counterElements] = snail_map[size_vector][i];
            counterElements++;
        }

        for (int i = (size_vector - 1); (counterWhile + 1) <= i; i--)
        {
            expected[counterElements] = snail_map[i][counterWhile];
            counterElements++;
        }

        counterWhile++;
    }

    return expected;
}



int main()
{
    vector <int> value{ {} };
    //value = snail({{}});
    value = snail({ {1} });
    //value = snail({ {1, 2}, { 4,3 } });
    //value = snail({ { 1, 2, 3 }, { 8,9,4 }, { 7,6,5 } });
    //value = snail({ {1,2,3,4,5}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7} });

    for (int i = 0; i < value.size(); i++)
        cout << value[i] << endl;

    return 0;
}
