package Exam.src;

public class Team 
{
    String name;
    String position;
    String team;

    Team(String name, String position, String team)
    {
        this.name = name;
        this.position = position;
        this.team = team;
    }

    public static void main(String[] args) 
    {
        Player p1 = new Player("Connor McDavid", "Centre", "Edmonton Oilers", 32, 100);
        Player p2 = new Player("Cale Makar", "Defense", "Colorado Avalanche", 21, 69);
        Goalie g1 = new Goalie("Sergei Bobrovsky", "Goalie", "Florida Panthers", 36, 2.37);
        p1.displayInfo();
        p2.displayInfo();
        g1.displayInfo();
    }
}

class Player extends Team
{
    int goals;
    int assists;

    Player(String name, String position, String team, int goals, int assists)
    {
        super(name, position, team);
        this.goals = goals;
        this.assists = assists;
    }

    public void displayInfo()
    {
        System.out.println(name + " " + team + " " + position + " " + "G:" + goals + " " + "A:" + assists);
    }
}

class Goalie extends Team
{
    int wins;
    double gaa;

    Goalie(String name, String position, String team, int wins, double gaa)
    {
        super(name, position, team);
        this.wins = wins;
        this.gaa = gaa;
    }

    public void displayInfo()
    {
        System.out.println(name + " " + team + " " + position + " " + "Wins:" + wins + " " + "GAA:" + gaa);
    }
}
