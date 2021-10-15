import java.util.ArrayList;
import java.util.Scanner; 
public class Return_subsets_sum_to_K{
    public static int returnSumofK(){
        Scanner k = new Scanner(System.in);
        int n = k.nextInt();
        String np = k.nextLine();
        String arr = k.nextLine();
        int K = k.nextInt();
        
        String[] arr2 = arr.split(" ");
        int[] arr3 = new int[arr2.length];
        
       
        for(int i=0; i<arr2.length; i++) {
        	 //if(Integer.parseInt(arr2[i]) <= K) {
        		 arr3[i] = Integer.parseInt(arr2[i]);
        	// }
        }
        
        
       
        String sumAll = "";
        for (int i=0; i<(1<<arr3.length); i++){
        	ArrayList<Integer> sumlist = new ArrayList<Integer>();
            int sum = 0;
            int m = 1;
            for (int j=0; j<arr3.length; j++){
                if ((i&m)>0){       
                    //System.out.print(arr3[j] + " ");
                	sumlist.add(arr3[j]);
                }
                m = m << 1;
            }
            for(int t=0; t<sumlist.size(); t++) {
            	sum = sum + sumlist.get(t);
            }
            if(sum == K) {
            	for(int t=0; t<sumlist.size(); t++) {
            		if(sumAll.equals("")) {
            			sumAll = String.valueOf(sumlist.get(t)); 
            		}
            		else {
            			sumAll = sumAll + " " + String.valueOf(sumlist.get(t)); 
            		}
            	}
            	sumAll = sumAll + "+";
            }
        }
        String sumAllLast = sumAll.substring(0, sumAll.length()-1);
        String[] strarr = sumAllLast.split("\\+ ");
        for(int i=0; i<strarr.length; i++) {
        	System.out.println(strarr[i]);
        }
        
        return 0;
    }
    
    
    public static void main(String[] args) {
    	returnSumofK();
    	
    }
}