class Solution {                                   Long -> String -> char[] -> int[]
  public int[] solution(long n) {
      String tempStr = new String(n+"");
        char[] tempChar = tempStr.toCharArray();
        int[] answer=new int[tempChar.length];
        
        for(int i =0; i<tempChar.length; i++){
            answer[i] = Integer.parseInt(tempChar[tempChar.length-1-i]+"");
        }
        return answer;
  }
}
/*class Solution {                               10씩 나눠서 배열에 저장         
  public int[] solution(long n) {
      String a = "" + n;
        int[] answer = new int[a.length()];
        int cnt=0;

        while(n>0) {
            answer[cnt]=(int)(n%10);
            n/=10;
            System.out.println(n);
            cnt++;
        }
      return answer;
  }
}*/
/*
      StringBuilder sb = new StringBuilder(s);
      sb = sb.reverse();
      String[] ss = sb.toString().split("");

      int[] answer = new int[ss.length];
      for (int i=0; i<ss.length; i++) {
          answer[i] = Integer.parseInt(ss[i]);
      }
      return answer;*/
