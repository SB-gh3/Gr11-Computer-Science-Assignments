package Assignment1.src;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class Assignment1 
{
    static void one()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter array length: ");
        int var = sc.nextInt();
        int[] initial = new int[var];
        List<Integer> even = new ArrayList<>();
        List<Integer> odd = new ArrayList<>();

        for (int i = 0; i < initial.length; i++) 
        {
            System.out.println("Enter the " + (i + 1) + " element: ");
            initial[i] = sc.nextInt();
        }

        for (int j = 0; j < initial.length; j++) 
        {
            if (initial[j] % 2 == 0)
            {
               even.add(initial[j]);
            }
            else
            {
                odd.add(initial[j]);
            }
        }

        JOptionPane.showMessageDialog(null, "Even: " + even + "\nOdd: " + odd);
    }

    static void two()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter array length: ");
        int len = sc.nextInt();
        int[] arr = new int[len];
        String out = "";
        int pos = 0;
        int neg = 0;
        int count = 0;

        for (int i = 0; i < arr.length; i++) 
        {
            System.out.println("Enter value " + (i + 1) + ": ");
            arr[i] = sc.nextInt();
        }

        for (int i = 0; i < (arr.length - 1); i++) 
        {
            if (arr[i] < arr[i + 1])
            {
                if (out != "")
                {
                    if (out.substring(out.length() - 15, out.length()).equals(" (Negative) -> "))
                    {
                        count++;
                    }
                }

                out += arr[i] + " (Positive) -> ";
                pos++;
            }
            else if (arr[i] > arr[i + 1])
            {
                if (out != "")
                {
                    if (out.substring(out.length() - 15, out.length()).equals(" (Positive) -> "))
                    {
                        count++;
                    }
                }

                out += arr[i] + " (Negative) -> ";
                neg++;
            }
        }

        if (pos == 0 ^ neg == 0)
        {
            System.out.println(Arrays.toString(arr) + "\n No directional changes");
        }
        else
        {
            out += arr[arr.length - 1];
            System.out.println(out + "\nThere are " + count + " directional changes.");
        }
    }

    static void three()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter array length: ");
        int len = sc.nextInt();
        int[] array = new int[len];
        int sma = Integer.MAX_VALUE;
        int lar = Integer.MIN_VALUE;

        for (int i = 0; i < array.length; i++) 
        {
            System.out.println("Enter element " + (i + 1) + ": ");
            array[i] = sc.nextInt();
        }

        for (int i = 0; i < array.length; i++) 
        {     
            for (int j = i + 1; j < array.length; j++) 
            {     
               if (array[i] > array[j]) 
               {    
                   int temp = array[i];    
                   array[i] = array[j];    
                   array[j] = temp;    
               }     
            }     
        }

        for (int i = 1; i < array.length; i++) 
        {
            if (array[i] - array[i - 1] < sma)
            {
                sma = array[i] - array[i - 1];
            }
            else if (array[i] - array[i - 1] > lar)
            {
                lar = array[i] - array[i - 1];
            }
        }

        JOptionPane.showMessageDialog(null, "The smallest difference is " + sma + "\nThe largest difference is " + lar);
    }

    static void four()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter first array length: ");
        int len = sc.nextInt();
        Integer[] arr1 = new Integer[len];
        System.out.println("Enter second array length: ");
        len = sc.nextInt();
        Integer[] arr2 = new Integer[len];
        boolean check = true;

        for (int i = 0; i < arr1.length; i++) 
        {
            System.out.println("Enter element " + (i + 1) + " for array one: ");
            arr1[i] = sc.nextInt();
        }

        for (int i = 0; i < arr2.length; i++) 
        {
            System.out.println("Enter element " + (i + 1) + " for array two: ");
            arr2[i] = sc.nextInt();
        }

        for (int i = 0; i < arr1.length; i++) 
        {     
            for (int j = i + 1; j < arr1.length; j++) 
            {     
               if (arr1[i] > arr1[j]) 
               {    
                   int temp = arr1[i];    
                   arr1[i] = arr1[j];    
                   arr1[j] = temp;    
               }     
            }     
        }

        for (int i = 0; i < arr2.length; i++) 
        {     
            for (int j = i + 1; j < arr2.length; j++) 
            {     
               if (arr2[i] > arr2[j]) 
               {    
                   int temp = arr2[i];    
                   arr2[i] = arr2[j];    
                   arr2[j] = temp;    
               }     
            }     
        }

        if (checkArr1(arr1, arr2))
        {
            JOptionPane.showMessageDialog(null, "Array 1 contains aray 2");
        }
        else if (checkArr2(arr1, arr2))
        {
            JOptionPane.showMessageDialog(null, "Array 2 contains aray 1");
        }
        else
        {
            JOptionPane.showMessageDialog(null, "One or more elements are not present");
        }
    }

    static boolean checkArr1(Integer[] arr1, Integer[] arr2) 
    {
        return Arrays.asList(arr1).containsAll(Arrays.asList(arr2));
    }

    static boolean checkArr2(Integer[] arr1, Integer[] arr2) 
    {
        return Arrays.asList(arr2).containsAll(Arrays.asList(arr1));
    }

    static void five()
    {
        Scanner sc = new Scanner(System.in);
        int[][] array = new int[3][3];
        int row1 = 0;
        int row2 = 0;
        int row3 = 0;
        int col1 = 0;
        int col2 = 0;
        int col3 = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                System.out.println("Enter element " + (j + 1) + " for row " + (i + 1));
                array[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < 3; i++)
        {
            row1 += array[0][i];
            row2 += array[1][i];
            row3 += array[2][i];
            col1 += array[i][0];
            col2 += array[i][1];
            col3 += array[i][2];
        }

        if (row1 == col1 || row1 == col2 || row1 == col3 || row2 == col1 || row2 == col2 || row2 == col3 || row3 == col1 || row3 == col2 || row3 == col3)
        {
            JOptionPane.showMessageDialog(null, "The array is symmetrical");
        }
        else 
        {
            JOptionPane.showMessageDialog(null, "The array is not symmetrical");
        }
    }

    static void six()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter how many games you want to play");
        double game = sc.nextDouble();
        int player = 0;
        int dealer = 0;
        int win = 0;
        int rolls = 0;
        Random die = new Random();

        for (int i = 0; i < game; i++)
        {
            dealer = 0;
            player = 0;
            
            for (int j = 0; j < 3; j++) 
            {
                dealer += die.nextInt(1, 12);
            }

            if (dealer > 21)
            {
                System.out.println("Dealer bust.");
                win++;
                continue;
            }
            else if (dealer == 21)
            {
                System.out.println("Dealer natural victory.");
                continue;
            }

            while (player < dealer && player < 21)
            {
                System.out.println("Player: " + player + "\nDealer: " + dealer + "\n");
                player += die.nextInt(1, 7);
                rolls++;
            }

            if (player > dealer && player <= 21)
            {
                System.out.println("Player: " + player + "\nDealer: " + dealer + "\n");
                System.out.println("Win!");
                win++;
            }
            else
            {
                System.out.println("Player: " + player + "\nDealer: " + dealer + "\n");
                System.out.println("Loss.");
            }
        }

        JOptionPane.showMessageDialog(null, "Win percentage: " + ((win / game) * 100) + "\nAverage dice rolls: " + (rolls / game));
    }

    static void select()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("1. A tale of two arrays\n2. Direction\n3. Difference\n4. Compare\n5. Symmetry\n6. Blackjack");
        int num = sc.nextInt();

        switch (num)
        {
            case 1:
                one();
                return;

            case 2:
                two();
                return;
            
            case 3:
                three();
                return;

            case 4:
                four();
                return;

            case 5:
                five();
                return;

            case 6:
                six();
                return;

            default:
                JOptionPane.showMessageDialog(null, "ERROR");
                return;
        }
    }

    public static void main(String[] args) 
    {
        while (true)
        {
            select();
        }
    }
}