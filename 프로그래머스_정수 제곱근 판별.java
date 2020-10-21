class Solution {
    public long solution(long n) {
        long answer = 0;
        double temp = Math.pow(n, 0.5);

        if((double)n%temp==0){                    // (Math.pow((int)Math.sqrt(n), 2)
            answer=(long)Math.pow((temp+1), 2);         
        }
        else{
            answer=-1;
        }
        
        return answer;
    }
}
