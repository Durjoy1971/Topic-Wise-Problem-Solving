import java.util.Map;
import java.util.TreeMap;

public class LearnCollection {
    public static void main(String[] args)
    {
        System.out.println(checkPermutation("abc", "bac"));
        System.out.println(checkPermutation("abc  ", "bac"));
        System.out.println(checkPermutation("abc", "bad"));

        System.out.println(checkPermutationOther("abc", "bac"));
        System.out.println(checkPermutationOther("abc  ", "bac"));
        System.out.println(checkPermutationOther("abc", "bad"));
    }

    static boolean checkPermutation(String first, String second)
    {
        if(first.length() != second.length()) return false;

        // Assuming the input string is lowercase
        int [] counter = new int[26];

        for(int i = 0; i < first.length(); i++){
            int curr = first.charAt(i) - 'a';
            counter[curr]++;
        }

        for(int i = 0; i < second.length(); i++){
            int curr = second.charAt(i) - 'a';
            counter[curr]--;
            if(counter[curr] < 0) return false;
        }
        return true;
    }

    static boolean checkPermutationOther(String first, String second)
    {
        if(first.length() != second.length()) return false;

        // Assuming the input string is lowercase
        Map<Character,Integer> counter = new TreeMap<>();

        for(int i = 0; i < first.length(); i++){
            char ch = first.charAt(i);
            int cur_value = counter.get(ch) == null ? 0 : counter.get(ch);
            counter.put(ch,cur_value+1);
        }

        for(int i = 0; i < second.length(); i++){
            char ch = second.charAt(i);
            int cur_value = counter.get(ch) == null ? 0 : counter.get(ch);
            if(cur_value == 0) return false;
            counter.put(ch,cur_value-1);
        }
        return true;
    }
}
