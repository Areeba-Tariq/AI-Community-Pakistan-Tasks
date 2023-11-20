import javax.swing.plaf.TableHeaderUI;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[][] unitsConsumed = {
                {50, 100, 25},
                {110, 150, 200},
                {220, 210, 300}
        };
        int option = 1;
        while (option == 1 || option == 2) {
            System.out.println("\nMy Student Id is X123 \n" + "Press 1" +
                    " to display slab1 and slab2\nPress 2 to display " +
                    "slab3\nPress any Key to exit");
            Scanner scanner = new Scanner(System.in);
            switch (scanner.nextInt()) {
                case 1:
                    int ans[] = new int[3];
                    int ans1[] = new int[3];
                    for (int i = 0; i < 3; i++) {
                        ans[i] = unitsConsumed[0][i] * 10;
                    }
                    for (int i = 0; i < 3; i++) {
                        ans1[i] = unitsConsumed[1][i] * 15;
                    }
                    System.out.println("The Bill for slab 1 is");
                    for(int i=0;i<3;i++)
                    {
                        System.out.print(ans[i]+" ");
                    }
                    System.out.println("\nThe Bill for slab 2 is");
                    for(int i=0;i<3;i++)
                    {
                        System.out.print(ans1[i]+" ");
                    }
                    option = 1;
                    break;
                case 2:
                    int ans2[] = new int[3];
                    for (int i = 0; i < 3; i++) {
                        ans2[i] = unitsConsumed[2][i] * 20;
                    }
                        option = 2;
                        System.out.println("\nThe Bill for slab 3 is");
                    for(int i=0;i<3;i++)
                    {
                        System.out.print(ans2[i]+" ");
                    }

                    break;
                default:
                    option = 3;

            }
        }
    }
}