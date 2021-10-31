import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{   
    static long mod = 1000000007;
 public static void main (String[] args) throws java.lang.Exception
 {
  // your code goes here
  Scanner sc  = new Scanner(System.in);
  int t = sc.nextInt();
  while(t-- > 0){
      long a=0,b=0;
      a = sc.nextLong();
      b = sc.nextLong();
      long ians = findPower(2, a)-1;
      System.out.println(findPower(ians,b));
  }
 }
 
 public static long findPower(long a , long b){
    if(b==0)
     return 1;
    else if(b==1)
     return a;
     
    if((b%2)==0){
        long temp = findPower(a,b/2);
        return (temp*temp)%mod;
    }
    else{
        long temp = findPower(a,(b-1)/2);
        return ((a*temp)%mod*temp)%mod;
    }
 }
}
