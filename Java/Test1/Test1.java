package src;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class Test1 
{
    static void one()
    {
        System.out.println("Number\tSquare Root\tFourth Root\n======\t===========\t===========");

        for (int i = 200; i <= 400; i++) 
        {
            if (i % 6 == 0 && i % 7 == 0)
            {
                System.out.println(i + "\t" + Math.round(Math.sqrt(i) * 100) / 100.0 + "\t\t" + Math.round(Math.sqrt(Math.sqrt(i)) * 10000) / 10000.0);
            }
        }
    }

    static void two()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a word that is at least 4 charachters long and ends in 'ate':");
        String str = sc.next();
        int count = 1;

        while (str.length() < 4 || str.endsWith("ate") != true)
        {
            if (str.length() < 4)
            {
                System.out.println("\nThe length is less than four charcters, try again:");
                str = sc.next();
            }
            else if (str.endsWith("ate") != true)
            {
                System.out.println("\nThe word does not end in 'ate', try again:");
                str = sc.next();
            }
            count++;
        }

        System.out.println("Thank you, it took you " + count + " tries.\n");
    }

    static void select()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Numbers and Roots\n2. Word Check");
        char lett = sc.next().charAt(0);

        switch (lett)
        {
            case '1':
                one();
                return;
            case '2':
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
            select();
        }
    }
}