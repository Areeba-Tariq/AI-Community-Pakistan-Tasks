import java.util.Scanner;

interface Shape
{
    public double CalArea();
    public double CalPeri();
    public void display();
    public int calAngleSum();
}
class Hexagon implements Shape
{
    double s;
    Hexagon(int s)
    {
        this.s=s;
    }

    @Override
    public double CalArea() {
        return 1.5*1.732*s;
    }

    @Override
    public double CalPeri() {
        return 6*s;
    }

    @Override
    public void display() {
        System.out.println("\nThe area is "+CalArea());
        System.out.println("\nThe Angle Sum is "+calAngleSum());
        System.out.println("\nThe Area is "+CalArea());
    }

    @Override
    public int calAngleSum() {
        return 6*(2*120);
    }
}
class Square implements Shape
{
    double s;
    Square(int s)
    {
        this.s=s;
    }

    @Override
    public double CalArea() {
        return 2*s;
    }

    @Override
    public double CalPeri() {
        return 4*s;
    }

    @Override
    public void display() {
        System.out.println("\nThe Area is "+CalArea());
        System.out.println("\nThe Primeter is "+CalPeri());
    }

    @Override
    public int calAngleSum() {
     return 360;
    }
}
public class Main {
    public static void main(String[] args) {

        //my cnic last digit is 8
        Shape s=new Hexagon(8);
        Shape s2=new Square(8+1);
        int op=1;
        while(op==1 || op==2) {
            System.out.println("Enter 1 for Display Hexagon 2 for Square\n");
            Scanner scan = new Scanner(System.in);
            op = scan.nextInt();
            switch (op) {
                case 1:
                    s.display();
                    break;
                case 2:
                    s2.display();
                    break;
                default:
                    System.out.println("\nExist");
            }
        }

    }
}