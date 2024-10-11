package Assignment3.src;

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class Assignment3 
{
    static boolean checkbool(boolean[] boo, boolean parameter)
    {
        for (int iter = 0; iter < boo.length; ++iter)
        {
            if (boo[iter] == parameter)
            {
                return true;
            }
        }

        return false;
    }

    static boolean checkint(int[] name, int num, int top)
    {
        for (int iter = name.length - top; iter < name.length; ++iter)
        {
            if (name[iter] == num)
            {
                return true;
            }
        }

        return false;
    }

    static int one(int[][] arr, String dire, int num, int size)
    {
        int sum = 0;

        if (num > size)
        {
            JOptionPane.showMessageDialog(null, "ERROR");
            return -1;
        }

        if (dire.equals("r") || dire.equals("R"))
        {
            for (int i = 0; i < size; i++)
            {
                sum += arr[num][i];
            }
        }
        else if (dire.equals("c") || dire.equals("C"))
        {
            for (int i = 0; i < size; i++)
            {
                sum += arr[i][num];
            }
        }
        else if (dire.equals("fd") || dire.equals("FD"))
        {
            for (int i = 0; i < size; i++)
            {
                sum += arr[num - i][i];
            }
        }
        else if (dire.equals("rd") || dire.equals("RD"))
        {
            for (int i = 0; i < size; i++)
            {
                sum += arr[i][i];
            }
        }

        return sum;
    }

    static String two(int n)
    {
        int dire = 1;
        int direr = 1;
        int count = 1;
        int countr = 1;
        String diamond = "";

        if (n % 2 == 0)
        {
            JOptionPane.showMessageDialog(null, "ERROR");
            return "ERROR";
        }
        else
        {
            int counto = n * 2;

            while (dire > 0)
            {
                if (dire % 2 != 0)
                {
                    if (dire <= n)
                    {
                        diamond += String.join("", Collections.nCopies(counto, " "));
                        diamond+= String.join("", Collections.nCopies(dire, "*"));
                        diamond += "\n";
                        --counto;

                        if (dire == n)
                        {
                            counto += 2;
                        }

                        ++dire;
                    }
                    else if (dire > n)
                    {
                        diamond += String.join("", Collections.nCopies(counto, " "));
                        diamond+= String.join("", Collections.nCopies(dire - 2 * (count + 1), "*"));
                        ++dire;

                        if (dire == 2 * n)
                        {
                            break;
                        }

                        diamond += "\n";
                        count += 2;
                        ++counto;
                    }
                }

                ++dire;
            }

            diamond += "\n\n";

            int countor = n * 2;

            while (direr > 0)
            {
                if (direr % 2 != 0)
                {
                    if (direr <= n)
                    {
                        diamond += String.join("", Collections.nCopies(countor, " "));
                        diamond += "*";

                        if (direr != 1)
                        {
                            diamond += String.join("", Collections.nCopies(direr - 2, " "));
                            diamond += "*";
                        }

                        diamond += "\n";
                        --countor;

                        if (direr == n)
                        {
                            countor += 2;
                        }

                        ++direr;
                    }
                    else if (direr > n)
                    {
                        diamond += String.join("", Collections.nCopies(countor, " "));
                        diamond += "*";

                        if (direr != 2 * n - 1)
                        {
                            diamond += String.join("", Collections.nCopies((direr - 2 * (countr + 1)) - 2, " ")); 
                            diamond += "*";
                        }

                        ++direr;

                        if (direr == 2 * n)
                        {
                            break;
                        }

                        diamond += "\n";
                        countr += 2;
                        ++countor;
                    }
                }

                ++direr;
            }
        }

        return diamond;
    }

    static boolean three(String num)
    {
        String copy = num;
        StringBuilder reverse = new StringBuilder();
        reverse.append(num);
        reverse.reverse();

        if (copy.equals(reverse.toString()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    static void four(int lim)
    {
        for (int i = 2; i <= lim; ++i)
        {
            int adf = 0;

            for (int j = 1; j <= i; ++j)
            {
                if (i % j == 0 && j != i)
                {
                    adf += j;
                }
            }

            if (adf == i)
            {
                System.out.println(i + " is a perfect number!");
            }
        }
    }

    static void five(int min, int max)
    {
        boolean[] check = new boolean[max];
        Arrays.fill(check, true);

        while (min < max)
        {
            if (check[min])
            {
                for (int j = min; j != check.length; ++j)
                {
                    if (j % min == 0)
                    {
                        check[j] = false;
                    }
                }
                System.out.println(min + ", ");
            }
            ++min;
        }
    }

    static void six()
    {
        Scanner sc = new Scanner(System.in);
        String password, output = "";
        boolean repeat = true;
        boolean[] rules = new boolean[4];
        Arrays.fill(rules, true);
        int iter;
        String[] build = {"password must be longer than equal to six charachters, ", "passowrd must begin with a capital, ", "password must contain two digits, ", "password must contain one and only one special charachter (!,@,#,$,%,^,&,*)"};
        
        while (repeat)
        {
            System.out.println("Enter a password: ");
            password = sc.nextLine();
            output.replaceAll("", "");

            if (password.length() < 6)
            {
                rules[0] = false;
                output += build[0];
            }

            String glerph = password.substring(0, 1).toUpperCase() + password.substring(1);

            if (password.charAt(0) != glerph.charAt(0)|| Character.isDigit(password.charAt(0)))
            {
                rules[1] = false;
                output += build[1];
            }

            int count = 0;

            for (iter = 0; iter < password.length(); ++iter)
            {
                if (Character.isDigit(password.charAt(iter)))
                {
                    ++count;
                }
            }

            if (count < 2)
            {
                rules[2] = false;
                output += build[2];
            }

            int counto = 0;

            for (int i = 0; i < password.length(); ++i)
            {
                if (password.charAt(i) == '!' || password.charAt(i) == '@' || password.charAt(i) == '#' || password.charAt(i) == '$' || password.charAt(i) == '%' || password.charAt(i) == '^' || password.charAt(i) == '&' || password.charAt(i) == '*')
                {
                    ++counto;
                }
            }

            if (counto != 1)
            {
                rules[3] = false;
                output += build[3];
            }

            if (checkbool(rules, false))
            {
                System.out.println(output);
            }
            else
            {
                System.out.println("Accepted");
                repeat = false;
            }
        }
    }

    static String seven(int[] rain, String[] month)
    {
        String output = "Month\tRainfall Amount\n=====\t===============\n";
        int[] raino = rain.clone();
        Arrays.sort(rain);

        for (int i = 0; i < month.length; ++i)
        {
            output += month[i] + "\t\t";
            output += raino[i];

            if (checkint(rain, raino[i], 3))
            {
                output += "\tBring an umbrella";
            }

            output += "\n";
        }

        return output;
    }

    static void select()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("1. 2D Addition\n2. Diamond\n3. Palidrome Number\n4. Perfect Numbers\n5. Prime Numbers (Sieve of Eratosthenes)\n6. Password\n7. Rain");
        int choice = sc.nextInt();

        switch (choice)
        {
            case 1:
                int size, num;
                System.out.print("Enter vector size: ");
                size = sc.nextInt();
                int[][] arr = new int[size][size];

                for (int i = 0; i < size; ++i)
                {
                    for (int j = 0; j < size; ++j)
                    {
                        System.out.print("Enter element " + (j + 1) + " in row " + (i + 1) + ": ");
                        arr[i][j] = sc.nextInt();
                    }
                }

                System.out.println("Which section do you want to add? (r, c, fd, rd)");
                String dire = sc.next();
                System.out.println("Which index do you want to check (0 for fd, rd)");
                num = sc.nextInt();
                System.out.println("Return value: " + (one(arr, dire, num, size)));
                return;

            case 2: 
                int n;
                System.out.print("Enter size: ");
                n = sc.nextInt();
                System.out.println(two(n));
                return;

            case 3:
                System.out.print("Enter number: ");
                String numo = sc.next();
                System.out.println(three(numo));
                return;

            case 4:
                System.out.print("Enter limit: ");
                int lim = sc.nextInt();
                four(lim);
                return;

            case 5:
                System.out.println("Enter minimum: ");
                int min = sc.nextInt();
                System.out.println("Enter maximum: ");
                int max = sc.nextInt();
                five(min, max);
                return;

            case 6:
                six();
                return;

            case 7:
                String[] month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
                int[] rain = new int[12];

                for (int i = 0; i < month.length; ++i)
                {
                    System.out.println("Enter rainfall amount for " + month[i] + ": ");
                    rain[i] = sc.nextInt();
                }
            
                System.out.println(seven(rain, month));
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