import java.util.*;
  
  public class Main{
  
  public static void main(String[] args) {
      Scanner scn = new Scanner(System.in);
  
       // write ur code here
       int t=scn.nextInt();
    //   while(t>0)
    //   {
    //       int n=scn.nextInt();
    //       int cnt=0;
    //       for(int i=1;i<=n;++i)
    //       {
    //           if(n%i==0) ++cnt;
    //       }
           
    //       if(cnt==2) System.out.println("prime");
    //       else System.out.println("not prime");
           
    //       t--;
    //   }
    
    
        while(t>0)
        {
            int n=scn.nextInt();
            int cnt=0;
            // calculate sqrt(n) using library functions 
            // i*i<=n  i^2<=n => i<=root(n)
            for(int i=2; i*i<=n ;i++)
            {
                if(n%i==0)
                {
                    ++cnt;
                    break;  ///break-> termination condition for loop 
                }
                
                // factor ++cnt
            }
            
            if(cnt==0) System.out.println("prime");  
            else System.out.println("not prime");   
            /// if cnt==0  -> prime  else not a prime
             
            t--;
        }
  
   }
  }
