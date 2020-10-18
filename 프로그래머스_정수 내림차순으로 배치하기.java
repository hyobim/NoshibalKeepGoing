import java.util.Arrays;
class Solution {
    public long solution(long n) {
        char[] arr = Long.toString(n).toCharArray();   // long -> charArray
        String str = "";                              

        Arrays.sort(arr);                              // array 오름차순 정렬

        for (int i = arr.length-1; i >= 0; i--) {
            str += Character.toString(arr[i]);      // 배열 마지막부터 string으로 이어붙이기
        }
        return Long.parseLong(str);                   // string -> Long

    }
}

/*
class Solution {
    String res = "";
    public long solution(long n) {
        res = "";
        Long.toString(n).chars().sorted().forEach(c -> res = Character.valueOf((char)c) + res);
        
        return Long.parseLong(res);
    }
}
*/
