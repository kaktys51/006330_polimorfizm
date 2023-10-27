#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
using std::cout;
using std::cin;

class IPAddress
{
protected:
	string strIP;
	vector<int> convetedIP;
public:
	IPAddress() {}
	IPAddress(string newip) :
		strIP(newip) 
	{
		inputConvert();
	}
	IPAddress(const IPAddress& obj) : strIP(obj.strIP) 
	{
		inputConvert();
	}

	void setIP()									//������� ������������ ����� IP
	{												//� ����� �������� ������� ��� ����������� �� � ������
		convetedIP.clear();
		cout << "Type IP address:" << endl;
		getline(cin, strIP);
		inputConvert();
	}

	virtual void printIP() 							//������� �������� IP �� �����
	{
		cout << "IP address : "<< " ";
		for (int i = 0; i < convetedIP.size(); ++i)
		{
			if (i == convetedIP.size() - 1) cout << convetedIP[i] << endl;
			else cout << convetedIP[i] << ".";
		}
	}

	virtual void inputConvert() 					//����������� �� string � vector ��� �������� ������
	{
		stringstream ss(strIP);
		string tempSegment;
		while (getline(ss, tempSegment, '.'))
		{
			convetedIP.push_back(stoi(tempSegment));
		}
	}
};

class IPAddressChecked : public IPAddress
{
protected:
	bool checkIP;
public:
	IPAddressChecked() {}
	IPAddressChecked(std::string newIP) :
		IPAddress(newIP) {}
	IPAddressChecked(const IPAddressChecked& obj) : IPAddress(obj.strIP) {}
	
	void inputConvert()								//�� �� ������� ����������� �� � ���������� �� ������������ IP
	{												//� ������ ����������� � bool checkIP
		stringstream ss(strIP);
		string tempSegment;
		while (getline(ss, tempSegment, '.'))
		{
			convetedIP.push_back(stoi(tempSegment));
		}

		if (convetedIP.size() != 4) checkIP = false;
		else
		{
			for (int i = 0; i < convetedIP.size(); ++i)
			{
				if (convetedIP[i] < 0 || convetedIP[i] > 256)
				{
					checkIP = false;
					break;
				}
				else checkIP = true;
			}
		}

	}

	void printIP()									//����� IP � ������� � ������� ����������� ���������� IP ��� ���
	{
		cout << "IP address : " << " ";
		for (int i = 0; i < convetedIP.size(); ++i)
		{
			if (i == convetedIP.size() - 1) cout << convetedIP[i] << endl;
			else cout << convetedIP[i] << ".";
		}
		getCheckStatus();
	}

	void getCheckStatus()							//������������ ��� ������ ������� ������������ IP
	{
		if (checkIP == true) cout << " IP address is correct" << endl;
		else cout << " IP address is incorect" << endl;
	}
};


int main()
{
	IPAddress ip0("111.999.12.1");
	ip0.printIP();
	cout << endl;

	IPAddressChecked ip_1("125.195.1.1");
	ip_1.printIP();
	cout << endl;

	IPAddressChecked ip_2;
	ip_2.setIP();
	ip_2.printIP();


	return 0;
}