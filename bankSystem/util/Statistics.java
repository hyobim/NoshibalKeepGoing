package org.kpu.atm.util;

import org.kpu.atm.bank.Account;

public class Statistics {
	
	public static int sum(Account[] account, int size) {
		int bSum=0;
		for(int i=0; i<size;i++) {
			bSum+=account[i].getnBalance();
		}
		return bSum;
	}
	
	public static double average(Account [] account, int size) {
		double avg=sum(account,size)/size;
		return avg;
	}
	
	public static int max(Account [] account, int size) {
		int mx=0;
		for(int i=0; i<size;i++) {
			if(account[i].getnBalance()>mx) {
			mx=account[i].getnBalance();
			}
		}
		return mx;
	}
	
	public static Account[] sort(Account [] account, int size) {
	
		for (int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                if(account[j].getnBalance() > account[i].getnBalance()){
                	Account [] temp = new Account [size];
                    temp [j] = account [j];
                    account [j] = account [i];
                    account [i] = temp [j]; 
                }
            }
        }
		return account;
	}
}
