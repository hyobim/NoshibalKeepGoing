package org.kpu.atm.bank;
import java.util.Scanner;

import org.kpu.atm.helpdesk.CustomerSvc;
import org.kpu.atm.util.Statistics;

public class ATMachine {
	private Account[] accountArray = new Account[1000];		//�����¹迭 ��������
	private int nMachineBalance;			//atm �ܰ�
	private int nMaxAccountNum;				//������ �������� �迭ũ��
	private static int nCurrentAccountNum;	//������ ������ ��
	private String strManagerPassword;		//������ ��й�ȣ
	private String name;
	private String passwd;
	static int idx=100;
	
	Scanner scan = new Scanner(System.in);
	public static final int BASE_ACCOUNT_ID = 100;
	
	public ATMachine(int size, int balance, String password) {
		nMaxAccountNum=size;
		nMachineBalance=balance;
		strManagerPassword=password;
		
	}
	public void createAccount() {
		
		System.out.println("----------����----------");
		System.out.println("�̸� �Է� : ");
		name = scan.nextLine();
		System.out.println("��й�ȣ �Է� : ");
		passwd = scan.nextLine();
	
		for (int i = 0; i < accountArray.length; i++) {
			if (accountArray[i] == null) {
				accountArray[i] = new Account(idx, 0, name, passwd);
				break;
			}
		}
		
		nCurrentAccountNum+=1;
		
		System.out.println(name+"�� "+ idx++ +"�� ���¹�ȣ�� ���������� �����ƽ��ϴ�.");
	}
	public void checkMoney() { // ������ȸ
		String accountNum;
		String pass;
		
		System.out.println("���¹�ȣ �Է�:");
		accountNum = scan.nextLine();
		
		System.out.println("��й�ȣ �Է� : ");
		pass = scan.nextLine();
		
		
			for(int i=0; i<accountArray.length; i++) {
				if(accountArray[i] != null) {
					Integer Ano = accountArray[i].getnID();
					String passw = accountArray[i].getStrPassword();
					if(Ano.toString().equals(accountNum) && passw.equals(pass)) {
						System.out.println("���� �ܾ�:"+ accountArray[i].getnBalance() );
						break;
					}
				}
				else {
					System.out.println("���� ������ �߸��Ǿ����ϴ�.");
					break;
				}
			}
	}
	
	public void depositMoney() {  // �����Ա�
		String accountNum;
		String pass;
		Integer money;
		
		System.out.println("���¹�ȣ �Է�:");
		accountNum = scan.nextLine();
		
		System.out.println("��й�ȣ �Է� : ");
		pass = scan.nextLine();
		
		System.out.println("�Ա� �� �Է� : ");
		money = Integer.parseInt(scan.nextLine());

		
			for(int i=0; i<accountArray.length; i++) {
				if(accountArray[i] != null) {
					Integer Ano = accountArray[i].getnID();
					String passw = accountArray[i].getStrPassword();
					if(Ano.toString().equals(accountNum) && passw.equals(pass)) {
						accountArray[i].deposit(money);
						System.out.println("�Ա� �� �ܾ�:"+ accountArray[i].getnBalance() );
						break;
					}
				}
				else {
					System.out.println("���� ������ �߸��Ǿ����ϴ�.");
					break;
				}
			}
	}
	
	public void widrawMoney() { // ���� ���
		String accountNum;
		String pass;
		Integer money;
		
		System.out.println("���¹�ȣ �Է�:");
		accountNum = scan.nextLine();
		
		System.out.println("��й�ȣ �Է� : ");
		pass = scan.nextLine();
		
		System.out.println("��� �� �Է� : ");
		money = Integer.parseInt(scan.nextLine());

		
			for(int i=0; i<accountArray.length; i++) {
				if(accountArray[i] != null) {
					Integer Ano = accountArray[i].getnID();
					String passw = accountArray[i].getStrPassword();
					if(Ano.toString().equals(accountNum) && passw.equals(pass)) {
						accountArray[i].widraw(money);
						System.out.println("��� �� �ܾ�:"+ accountArray[i].getnBalance() );
						break;
					}
				}
				else {
					System.out.println("���� ������ �߸��Ǿ����ϴ�.");
					break;
				}
			}
	}
	
	public void transfer() { // ���� ��ü
		String accountNum;
		String pass;
		String tAccountNum;
		Integer tMoney;
		boolean f = false;
		boolean f2 = false;
		
		System.out.println("���¹�ȣ �Է�:");
		accountNum = scan.nextLine();
		
		System.out.println("��й�ȣ �Է� : ");
		pass = scan.nextLine();
		
		System.out.println("��ü���� �Է� : ");
		tAccountNum = scan.nextLine();

		System.out.println("��ü�ݾ� �Է� : ");
		tMoney = Integer.parseInt(scan.nextLine());
		
			for(int i=0; i<accountArray.length; i++) {
				if(accountArray[i] != null) {
					Integer Ano = accountArray[i].getnID();
					String passw = accountArray[i].getStrPassword();
					
					if(Ano.toString().equals(accountNum) && passw.equals(pass)) {
						f2=true;
						for(int j=0; j<accountArray.length; j++) {
							Integer tAno = accountArray[j].getnID();
							if(tAno.toString().equals(tAccountNum)) {
								accountArray[i].widraw(tMoney);
								System.out.println("���� �ܾ�:"+ accountArray[i].getnBalance());
								System.out.println("���� ��ü�� �Ϸ��߽��ϴ�");
								f=true;
								break;
							}
						}
					}
					if(f==false) {
						System.out.println("��ü ���¸� �ٽ� Ȯ���ϼ���.");
						break;
					}
				}
				if(f2==false) {
					System.out.println("���� ������ �߸��Ǿ����ϴ�.");
					break;
				}
			}
	}
	
	public void requestSvc() { // ��й�ȣ �����û
		
		CustomerSvc cSv=new CustomerSvc(accountArray, nCurrentAccountNum);
		cSv.updatePasswdReq();
		
	}
	public void managerMode() { // �� ����
		String admin;
		Statistics stat=new Statistics();
		
		System.out.println("������ ��й�ȣ �Է�:");
		admin = scan.nextLine();
		
		if(admin.equals(strManagerPassword)) {
			System.out.println("ATM �����ܰ�:\t"+ (nMachineBalance+ stat.sum(accountArray, nCurrentAccountNum)));
			System.out.println("�� �ܰ� �Ѿ�:\t"+ (stat.sum(accountArray, nCurrentAccountNum))+"��("+ nCurrentAccountNum +"��)");
			System.out.println("�� �ܰ� ���:\t"+ (stat.average(accountArray, nCurrentAccountNum))+"��");
			System.out.println("�� �ܰ� �ְ�:\t"+ (stat.max(accountArray, nCurrentAccountNum))+"��");
			System.out.println("�� ���� ��Ȳ(�� �ܰ� �������� ����)"); // �̸� ���¹�ȣ �ݾ� ��
			
			Account[] srt=stat.sort(accountArray, nCurrentAccountNum);
			
			for(int i=0;i<nCurrentAccountNum;i++) {
				System.out.println(srt[i].getAccountName()+"\t"+srt[i].getnID()+"\t"+srt[i].getnBalance()+"��");
			}
		}
		
	}
	public void displayMenu() {
		System.out.println("-----------------------");
		System.out.println("-       KPU bank      -");
		System.out.println("-----------------------");
		System.out.println(" 1. ���� ����");
		System.out.println(" 2. ���� ��ȸ");
		System.out.println(" 3. ���� �Ա�");
		System.out.println(" 4. ���� ���");
		System.out.println(" 5. ���� ��ü");
		System.out.println(" 6. �� ����");
		System.out.println(" 7. �� ����");
		System.out.println(" 9. ���� ����");
		
	}
}
