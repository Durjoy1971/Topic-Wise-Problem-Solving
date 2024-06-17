import java.util.Map;
import java.util.TreeMap;

public class LearnCollection {
    public static void main(String[] args)
    {
        System.out.println(isUnique("abc"));
        System.out.println(isUnique("aba"));

        System.out.println(isUniqueOther("abc"));
        System.out.println(isUniqueOther("aba"));
    }

    static boolean isUnique(String str){
        // TreeMap Is Like Map In C++. Time complexity is also same
        Map<Character,Boolean> visited = new TreeMap<>();

        for(int i = 0; i < str.length(); i++)
        {
            char ch = str.charAt(i);
            // visited.get(ch)
            if(visited.containsKey(ch)) return false;
            visited.put(ch,true);
        }
        return true;
    }

    static boolean isUniqueOther(String str){
        int checker = 0;
        // Here we assume it is only for lowercase
        for(int i = 0; i < str.length(); i++)
        {
            int cur = str.charAt(i) - 'a';
            if((checker & (1 << cur)) > 0) return false;
            checker |= (1 << cur);
        }
        return true;
    }
}