package Test2.src;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class Test2 
{
    static void one()
    {
        Scanner sc = new Scanner(System.in);
        int[][] arr = new int[3][3];

        for (int index = 0; index < 3; ++index) 
        {
            for (int jindex = 0; jindex < 3; ++jindex) 
            {
                System.out.println("Enter element " + (jindex + 1) + " on line " + (index + 1));
                arr[index][jindex] = sc.nextInt();
            }
        }

        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j)
            {
                if (arr[i][j] % 2 == 0) 
                {
                    arr[i][j] = (int) Math.pow(arr[i][j], 2);
                }
                else
                {
                    arr[i][j] = (int) Math.pow(arr[i][j], 3);
                }
            }
        }

        for (int ib = 0; ib < 3; ++ib) 
        {
            System.out.println();
            for (int jb = 0; jb < 3; ++jb)
            {
                System.out.print(arr[ib][jb] + " ");
            }
        }
    }

    static void two()
    {
        int[]  array = {2, 5, 7, 9, 13, 15, 16, 18, 23, 24};
        List<Integer> arrayList = new ArrayList<>();
        arrayList.add(14);
        arrayList.add(23);
        arrayList.add(27);
        arrayList.add(31);
        arrayList.add(34);
        arrayList.add(39);
        arrayList.add(40);
        List<Integer> arrL = new ArrayList<>();

        for (int index = 0; index < array.length; ++index) 
        {
            if (array[index] % 3 == 0)
            {
                arrL.add(array[index]);
            }
        }

        for (int i = 0; i != arrayList.size(); ++i)
        {
            if (arrayList.get(i) % 3 == 0)
            {
                arrL.add(arrayList.get(i));
            }
        }

        System.out.println("\n" + arrL);
    }

    static void input()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("\n1. Squares and cubes\n2. Array Shenanigans");
        int choice = sc.nextInt();

        switch (choice)
        {
            case 1:
                one();
                return;

            case 2:
                two();
                return;

            default:
                JOptionPane.showMessageDialog(null, "ERROR");
                return;
        }
    }

    public static void main(String[] args) throws Exception 
    {
        while (true)
        {
            input();
        }
    }
}
