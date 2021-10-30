package Problems;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class TellTriangleType {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the sides of the triangle : ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        // Checking Triangle Valid or Not:
        if(a!=0 && b!=0 && c!=0){
            // Checking Triangle Valid or Not:
            if (a+b>c && b+c>a && c+a>b){

              if(a==b && b==c){
                  System.out.print("Equilateral, ");
              }
              else if(a==b || b==c || c==a){
                  System.out.print("Isosceles, ");
              }
              else{
                  System.out.print("Scalene, ");
              }
              // Now checking for the triangle to be Acute, Obtuse or Right:
                ArrayList<Integer> temp=new ArrayList<>();
              temp.add(a);
              temp.add(b);
              temp.add(c);
              Collections.sort(temp);
              int x=temp.get(0);
              int y=temp.get(1);
              int z=temp.get(2);
              int value= x*x + y*y;
              if(value==z*z){
                  System.out.println("Right Angled Triangle");
              }
              else if(value<z*z){
                  System.out.println("Obtuse Triangle");
              }
              else{
                  System.out.println("Acute Triangle");
              }
            }
            else{
                System.out.println("Triangle Not Possible");
            }
        }
        else{
            System.out.println("Triangle Not Possible");
        }
    }
}
