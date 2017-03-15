import java.util.Objects;
import java.util.Scanner;

/**
 * 阿里在线笔试for dangshen
 * Created by steel on 2017/3/15.
 */
public class Main {
    public static void main(String[] args){
        int[] counts=new int[31];
        int[] vector = new int[31];
        Scanner s = new Scanner(System.in);
        int size=0;
        for(int i=0;i<31;i++) counts[i]=0;
        for(;size<31;size++){
            String str = s.next();
            if(str==null || Objects.equals(str, "") || Objects.equals(str, "0")) break;
            vector[size] = Integer.parseInt(str.trim());
        }
        int lowerFloor = vector[size-1]/100;
        for(int i=size-1;i>=0;i--){
            int index = (vector[i]%100)/10;
            int floor = vector[i]/100;
            int cntIndex = (int)Math.pow(2,floor-1)+index;
            if(lowerFloor==floor || counts[cntIndex*2]+counts[cntIndex*2-1]==0)counts[cntIndex]=1;
            else counts[cntIndex] =counts[cntIndex*2]+counts[cntIndex*2-1];
        }
        int sum=0;
        for(int i=0;i<size;i++){
            int value = vector[i]%10;
            int index = (vector[i]%100)/10;
            int floor = vector[i]/100;
            int cntIndex = (int)Math.pow(2,floor-1)+index;
            sum+=value*counts[cntIndex];
        }
        System.out.println(sum);
    }
}
