package Test3.src;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class Test3 
{
    static int[] one(int[] arr, int[] glarr)
    {
        int[] output = new int[arr.length];

        for (int i = 0; i < arr.length; ++i) 
        {
            if (glarr[i] != 0)
            {
                output[i] = arr[i] / glarr[i];
            }
            else
            {
                output[i] = -1;
            }
        }

        return output;
    }

    static List<String> two(List<String> vec)
    {
        for (int i = 0; i < vec.size(); ++i) 
        {
            if (vec.indexOf(vec.get(i)) < i)
            {
                vec.remove(i);
                --i;
            }
        }

        return vec;
    }

    static void select()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Division Array\n2. Duplicates");
        int choice = sc.nextInt();

        switch (choice)
        {
            case 1:
                int[] arr = {4, 9, 16, 24};
                int[] glarr = {2, 3, 0, 6};
                System.out.println(Arrays.toString(one(arr, glarr)));
                return;

            case 2:
                List<String> vec = new ArrayList<>();
                vec.add("dog");
                vec.add("cat");
                vec.add("bird");
                vec.add("mouse");
                vec.add("dog");
                vec.add("wolf");
                vec.add("dog");
                vec.add("bird");
                System.out.println((two(vec)));
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
            select();
        }
    }
}
