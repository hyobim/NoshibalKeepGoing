package org.kpu.atm.bank;

import org.kpu.atm.helpdesk.CustomerSvc;

public class Account {

	private int nID;				//계좌 번호
	private int nBalance;			//계좌 잔고
	private String strAccountName;	//고객 명
	private String strPassword;		//계좌 비밀번호
	
	public Account(int id, int money, String name, String password) {
		this.nID=id;
		this.nBalance=money;
		this.strAccountName=name;
		this.strPassword=password;
	}	
	
	public int getnID() { return nID;
	}
	
	public void setnID(int nID) {
		this.nID=nID;
	}
	
	public int getnBalance() { return nBalance;
	}

	public void setnBalance(int nBalances) {
		this.nBalance=nBalance;
	}
	
	public String getStrAccountName() {
		return strAccountName;
	}

	public void setStrAccountName(String strAccountName) {
		this.strAccountName = strAccountName;
	}

	public String getStrPassword() {
		return strPassword;
	}

	public void setStrPassword(String strPassword) {
		this.strPassword = strPassword;
	}
	
	public void deposit(int money) { // 입금
        if(money<=0){
            System.out.println("금액을 정확히 입력하세요.");
            return;
        }
        nBalance+=money;
	}
	public void widraw(int money) { // 출금
		if(money<=0){
            System.out.println("금액을 정확히 입력하세요.");
            return;
        }
        nBalance-=money;
	}
	// 비밀번호 변경
	public boolean updatePasswd(String oldPasswd, String newPasswd) {
		if(this.strPassword.equals(oldPasswd))
		{
			this.strPassword = newPasswd;
			return true;
		}
		
		return false;
	}
	public String getAccountName() { // 고객명 읽기
		return getStrAccountName();
	}
}
	