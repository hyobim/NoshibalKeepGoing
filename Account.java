package org.kpu.atm.bank;

public class Account {

	private int nID;				//���� ��ȣ
	private int nBalance;			//���� �ܰ�
	private String strAccountName;	//�� ��
	private String strPassword;		//���� ��й�ȣ
	
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
	
	public int deposit(int money) {
		account.setBalance(account.getBalance() + money);
		return 
	}
}
	