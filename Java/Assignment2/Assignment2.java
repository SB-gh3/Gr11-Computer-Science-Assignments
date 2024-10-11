package Assignment2.src;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.stream.Collectors;

import javax.swing.JOptionPane;

public class Assignment2 
{
    static String one(double cost)
    {
        int[] change = new int[8];
        double remain = 0;
        //double time = System.nanoTime();

        while (cost > 0)
        {
            if (cost - 20 >= 0)
            {
                ++change[0];
                cost -= 20;
            }
            else if (cost - 10 >= 0)
            {
                ++change[1];
                cost -= 10;
            }
            else if (cost - 5 >= 0)
            {
                ++change[2];
                cost -= 5;
            }
            else if (cost - 2 >= 0)
            {
                ++change[3];
                cost -= 2;
            }
            else if (cost - 1 >= 0)
            {
                ++change[4];
                cost -= 1;
            }
            else if (cost - .25 >= 0)
            {
                ++change[5];
                cost -= .25;
            }
            else if (cost - .1 >= 0)
            {
                ++change[6];
                cost -= .1;
            }
            else if (cost - .05 >= 0)
            {
                ++change[7];
                cost -= .05;
            }
            else
            {
                remain = cost;
                break;
            }
            cost = Math.round(cost * 100.0) / 100.0;
        }

        //System.out.println((System.nanoTime() - time) / 1000);
        return change[0] + " x $20\n" + change[1] + " x $10\n" + change[2] + " x $5\n" + change[3] + " x $2\n" + change[4] + " x $1\n" + change[5] + " x $0.25\n" + change[6] + " x $0.10\n" + change[7] + " x $0.05\n$" + remain + " remaining";
    }

    static String two(int[] arr)
    {
        List<Integer> vec = new ArrayList<>();

        for (int index = 0; index < arr.length - 1; ++index) 
        {
            if ((index + 1) % 2 != 0)
            {
                vec.add(arr[index] + arr[index + 1]);
            }
            else
            {
                if (index == arr.length - 2)
                {
                    vec.add(arr[index + 1]);
                }
            }
        }

        String listString = vec.stream().map(Object::toString).collect(Collectors.joining(", "));
        return listString;
    }

    static String three(String str, char chara)
    {
        List<String> split = new ArrayList<>();
        str+=chara;

        while (str.length() != 0)
        {
            split.add(str.substring(0, str.indexOf(chara)));
            str = str.replace(str.substring(0, str.indexOf(chara) + 1), "");
        }

        //split.set(split.size() - 1, split.getLast().substring(0, split.getLast().length() - 1));
        String listString = String.join(", ", split);
        return listString;
    }
    
    static List<Integer> four(int[] array)
    {
        List<Integer> orderedArray = new ArrayList<>();
        int count = 0;

        for (int i= 0; i < array.length; i++) 
        {
            if (array[i] == 0)
            {
                ++count;
            }
            else
            {
                orderedArray.add(array[i]);
            }
        }

        for (int index = 0; index < count; index++) 
        {
            orderedArray.add(0);
        }
        return orderedArray;
    }

    static String five(int n)
    {
        int one = 0;
        int two = 0;
        int three = 0;
        int four = 0;
        int five = 0;
        int six = 0;
        String sone = "";
        String stwo = "";
        String sthree = "";
        String sfour = "";
        String sfive = "";
        String ssix = "";
        Random roll = new Random();

        for (int i = 0; i < n; ++i) 
        {
            int nroll = roll.nextInt(7);

            switch (nroll)
            {
                case 1:
                    ++one;
                    sone += "*";
                    break;

                case 2:
                    ++two;
                    stwo += "*";
                    break;

                case 3:
                    ++three;
                    sthree += "*";
                    break;

                case 4:
                    ++four;
                    sfour += "*";
                    break;

                case 5:
                    ++five;
                    sfive += "*";
                    break;

                case 6:
                    ++six;
                    ssix += "*";
                    break;
            }
        }

        String output = "Die Number    Frequency    Histogram\n==========    =========    =========\n         1    " + one + "    " + sone + "\n         2    " + two + "    " + stwo + "\n         3    " + three + "    " + sthree + "\n         4    " + four + "    " + sfour + "\n         5    " + five + "    " + sfive + "\n         6    " + six + "    " + ssix;
        return output;
    }

    static void six()
    {
        Scanner sc = new Scanner(System.in);
        char cont = ' '; 
        double score = 0;
        double count = 0;

        while (cont != 'N' || cont != 'n')
        {
            System.out.println("Enter your answer as a letter: ");
            char answer = sc.next().charAt(0);

            if (answer == 'A' || answer == 'a')
            {
                System.out.println("Correct");
                ++score;
            }
            else
            {
                System.out.println("Incorrect");
                score -= 0.2;
            }

            ++count;
            System.out.println("Your score is " + score / count * 100.0 + "%\nDo you wish to proceed?(Y/N)");
            cont = sc.next().charAt(0);
        }
    }

    static void seven(int nume, int deno)
    {
        int divisor = Math.min(nume, deno);
        double numnum = Integer.MAX_VALUE;
        double denden = Integer.MAX_VALUE;
        String frac = "";

        for (double i = 1; i <= divisor; ++i) 
        {
            if (nume / i == (int)(nume / i) && deno / i == (int)(deno / i))
            {
                if (nume / i < numnum && deno / i < denden)
                {
                    numnum = nume / i;
                    denden = deno / i;
                    frac = nume / i + "/" + deno / i;
                }
            }
        }

        System.out.println("Lowest Fraction: " + frac);
    }

    static void select()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Coins\n2. Array Add\n3. Split that String\n4. Zeroed Out\n5. Die\n6. Test\n7. Fraction");
        int choice = sc.nextInt();

        switch (choice)
        {
            case 1:
                System.out.print("Enter monetary value: ");
                double cost = sc.nextDouble();
                System.out.println(one(cost));
                return;

            case 2:
                System.out.print("Enter array length: ");
                int len = sc.nextInt();
                int[] arr = new int[len];
                for (int i = 0; i != len; ++i)
                {
                    System.out.print("\nEnter element " + (i + 1) + ": ");
                    arr[i] = sc.nextInt();
                }
                System.out.println(two(arr));
                return;

            case 3:
                System.out.print("Enter string: ");
                sc.nextLine();
                String init = sc.nextLine();
                System.out.print("Enter splitter attribute: ");
                char character = sc.nextLine().charAt(0);
                System.out.println(three(init, character));
                return;

            case 4:
                System.out.println("Enter array length: ");
                int lent = sc.nextInt();
                int[] array = new int[lent];

                for (int index = 0; index < array.length; index++) 
                {
                    System.out.println("Enter element " + (index + 1) + ": ");
                    array[index] = sc.nextInt();
                }

                System.out.println(four(array).toString());
                return;

            case 5:
                System.out.println("Enter n: ");
                int n = sc.nextInt();
                System.out.println(five(n));
                return;

            case 6:
                six();
                return;

            case 7:
                System.out.println("Enter Numerator:");
                int nume = sc.nextInt();
                System.out.println("Enter Denomonator:");
                int deno = sc.nextInt();
                seven(nume, deno);
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
