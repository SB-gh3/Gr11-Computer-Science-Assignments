package Test4.src;

import java.util.Arrays;
import java.util.Scanner;
import javax.swing.JOptionPane;

class boat
{
    String colour;
    int weight;
    boolean hasMotor;
    String name;
    static boolean hasRudder = true;

    boat(String colour, int weight, boolean hasMotor, String name)
    {
        this.colour = colour;
        this.weight = weight;
        this.hasMotor = hasMotor;
        this.name = name;
    }
}

class duck
{
    String name;
    boolean canSwim;

    duck(String name)
    {
        this.name = name;
        this.canSwim = true;
    }

    public void duckInfo()
    {
        System.out.println("Name: " + this.name + "\tCan he swim: " + this.canSwim);
    }
}

class duckling extends duck
{
    String featherColour;

    duckling(String name, String featherColour)
    {
        super(name);
        this.featherColour = featherColour;
        this.canSwim = false;
    }

    public void duckInfo()
    {
        System.out.println("Name: " + this.name + "\tCan he swim: " + this.canSwim + "\tFeather Colour: " + this.featherColour);
    }
}

public class Test4 
{
    static void one(boat[] boot)
    {
        String output = "Boat Type\tColor\tWeight\tMotor\tRudder\n========\t=====\t======\t=====\t======";
        int count = 0;

        for (boat i : boot) 
        {
            output += "\n" + i.name + "\t" + i.colour + "\t" + i.weight + "\t" + i.hasMotor + "\t" + i.hasRudder;
            ++count;
        }

        System.out.println(output);
    }

    static void select()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Boat\n2. Duck");
        int choice = sc.nextInt();

        switch (choice) 
        {
            case 1:
                boat motorboat = new boat("blue", 500, true, "motorboat");
                boat sailboat = new boat("red", 150, false, "sailboat");
                boat yacht = new boat("white", 3000, true, "yacht");
                boat[] boot = {motorboat, sailboat, yacht};
                one(boot);
                break;

            case 2:
                duck bill = new duck("Bill");
                duckling phil = new duckling("Phil", "yellow");
                bill.duckInfo();
                phil.duckInfo();
                break;
        
            default:
                JOptionPane.showMessageDialog(null, "ERROR");
                break;
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
