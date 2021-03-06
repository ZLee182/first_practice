/*
 For a web developer, it is very important to know how to design a web page's size. So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:

1. The area of the rectangular web page you designed must equal to the given target area.

2. The width W should not be larger than the length L, which means L >= W.

3. The difference between length L and width W should be as small as possible.

You need to output the length L and the width W of the web page you designed in sequence.

Example:

Input: 4
Output: [2, 2]
Explanation: The target area is 4, and all the possible ways to construct it are [1,4], [2,2], [4,1]. 
But according to requirement 2, [1,4] is illegal; according to requirement 3,  [4,1] is not optimal compared to [2,2]. So the length L is 2, and the width W is 2.

Note:

    The given area won't exceed 10,000,000 and is a positive integer
    The web page's width and length you designed must be positive integers.

*/


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
//解法一  496ms
int* constructRectangle(int area, int* returnSize) {
    int* l_w;
    int min=area,i;
    int count = -1;
    l_w = (int*)malloc(2*sizeof(int*));
    for(i = area ; i > 0 ; i--)
        if( area % i == 0 )
             if( min >= abs(i - area/i))
             {
                min = abs(i - area/i);
                count = i;
             }
    i = count;
    l_w[0] = i > area/i ? i : area/i;
    l_w[1] = i < area/i ? i : area/i;
    *returnSize = 2;
    return l_w;
}

//解法二  3ms

int* constructRectangle(int area, int* returnSize) {
    int* l_w = (int*)malloc(2*sizeof(int*));
    int w = sqrt(area);
    while(area%w!=0)
        w--;
    l_w[1] = w;
    l_w[0] = area/l_w[1];
    *returnSize = 2;
    return l_w;
}
