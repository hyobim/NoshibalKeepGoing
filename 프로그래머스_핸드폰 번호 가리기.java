class Solution {
    public String solution(String phone_number) {
        int len = phone_number.length();
        String str = phone_number.substring(len-4,len);
        String repeated = new String(new char[len-4]).replace("\0", "*");

        return repeated+str;
    }
}

/*char[] ch = phone_number.toCharArray();
     for(int i = 0; i < ch.length - 4; i ++){
         ch[i] = '*';
     }
     return String.valueOf(ch);
*/
     
// return phone_number.replaceAll(".(?=.{4})", "*");
