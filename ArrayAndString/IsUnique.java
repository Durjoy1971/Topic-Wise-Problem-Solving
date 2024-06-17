// Implement an algorithm to determine if a string has all unique characters.

import java.util.Map;
import java.util.TreeMap;

public class LearnCollection {
    public static void main(String[] args)
    {
        System.out.println(isUnique("abc"));
        System.out.println(isUnique("aba"));
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
}
