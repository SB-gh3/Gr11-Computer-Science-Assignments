package Exam.src;

import java.util.Arrays;

public class Exam
{
    static int[] plusFour(int[] arr)
    {
        for (int i = 0; i < arr.length; ++i)
        {
            arr[i] += 4;
        }

        return arr;
    }

    static void timesThree(int[] arr)
    {
        for (int i = 0; i < arr.length; ++i)
        {
            arr[i] *= 3;
        }

        System.out.println(Arrays.toString(plusFour(arr)));
    }

    public static void main(String[] args) throws Exception 
    {
        int[] arr = {1, 2, 3, 4};
        timesThree(arr);
    }
}
