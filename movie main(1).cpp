#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

typedef struct node {	//��Ӱ�ṹ��
	string name;	//��Ӱ����
	string scrip;	//���
	string director;//����
	string actor;	//��Ա
	string type;	//��Ӱ����
	string area;	//����
	string language;	//����
	int year;
	int month;
	int day;		//��ӳ������
	int time;		//Ƭ��
	string introduction;	//���
	double grade;		//��������
	string comment;		//����
}movies;

void Msystem(movies m[], int choose, int k);
int charsort(movies m[], int i, string name1, string name2,int flag1);
int stringIn(movies m[], int i, string name1, string name2,int flag2);
void inmovie(movies m[], int k);
void quickSort(movies Array[], int left, int right);
int SelectPivot(int left, int right);
int Partition(movies Array[], int left, int right);
template<class T>
int length(T& Array);

//template<class Record>
//void BubbleSort(Record Array[], int n);


//------------------------------------------������---------------------------------------------------------------------------------------------
int main() {
	movies m[50];
	int k = 0;
	string s;
	int choose;			//ѡ����Ϣ
	
	ifstream ifile("test1.txt");
	if (!ifile.is_open()) {
		cout << "the file can not open" << endl;
		exit(1);
	}

	for(int i = 0;!ifile.eof();i++) {
		if (!(ifile >> m[i].name))break;
		ifile  >> m[i].scrip >> m[i].director >> m[i].actor >> m[i].type >> m[i].area >> m[i].language >> m[i].year >> m[i].month >> m[i].day >> m[i].time >> m[i].introduction >> m[i].grade >> m[i].comment;
		//cout << "��Ӱ���ƣ�" << m[i].name << "\n��磺" << m[i].scrip << "\n���ݣ�" << m[i].director << "\n��Ա��" << m[i].actor << "\n���ͣ�" << m[i].type << "\n������" << m[i].area << "\n���ԣ�" << m[i].language << "\n��ӳ���ڣ�" << m[i].year << "-" << m[i].month << "-" << m[i].day << "\nƬ����" << m[i].time << "����" << "\n��飺" << m[i].introduction << "\n�������֣�" << m[i].grade << "\nӰ����" << m[i].comment << "\n" << endl;
		k++;
	}
	ifile.close();
	
	while (true) {
		cout << "--------Movie System--------" << endl;
		cout << "һ������ӰƬ" << k << "��\n";
		cout << "ѡ��һ�������ѯ�ķ��� " << endl;
		cout << "0:���� 1:���� 2:��Ӱ���� 3:���� 4:ӰƬ���� 5:��Ӱ��Ա 6:���� 7:���ӰƬ 8:��ӳʱ�� 9:�˳�" << endl;
		cout << "�����룺";
		cin >> choose;
		Msystem(m, choose, k);
		cout << "\n";
		if (choose == 7)
			k = k + 1;
	}
	system("pause");
	return 1;
}

//----------------------------------------------------------�������������֣�--------------------------------------------------------------------------------------------
void quickSort(movies Array[], int left, int right) {
	if (right <= left)return;
	int pivot = SelectPivot(left, right);
	swap(Array[left], Array[pivot]); 
	pivot = Partition(Array, left, right);
	quickSort(Array, left, pivot - 1);
	quickSort(Array, pivot + 1, right);
}
int SelectPivot(int left, int right) {
	return(left + right) / 2;
}
int Partition(movies Array[], int left, int right) {
	int l = left;
	int r = right;
	movies TempRecord;
	TempRecord = Array[l];
	while (l != r) {
		while (Array[r].grade <= TempRecord.grade && r > l)
			r--;
		if (l < r) {
			Array[l] = Array[r];
			l++;
		}
		while (Array[l].grade >= TempRecord.grade && r > l)
			l++;
		if (l < r) {
			Array[r] = Array[l];
			r--;
		}
	}
	Array[r] = TempRecord;
	return r;
}


//--------------------------------------------------------------�����鳤��-------------------------------------
template<class T>
int length(T& Array)
{
	return (sizeof(Array) / sizeof(Array[0]));
}




//------------------------------------------------------------ð�����������֣�------------------------------------------------------------------------------------------
/*
template<class Record>
void BubbleSort(Record Array[], int n) {
	bool NoSwap;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		NoSwap = true;
		for (j = n - 1; j > i; j--) {
			if (Array[j] < Array[j - 1]) {
				swap(Array[j], Array[j - 1]);
				NoSwap = false;
			}
		}
		if (NoSwap)
			return;
	}
}
*/

//-----------------------------------------------------------�ַ�����ѯ����---------------------------------------------------------------------------
int charsort(movies m[], int i, string name1, string name2,int flag1) {
	if (name1.compare(name2) == 0) {
		cout << "\n��Ӱ���ƣ�" << m[i].name << "\n��磺" << m[i].scrip << "\n���ݣ�" << m[i].director << "\n��Ա��" << m[i].actor << "\n���ͣ�" << m[i].type << "\n������" << m[i].area << "\n���ԣ�" << m[i].language << "\n��ӳ���ڣ�" << m[i].year << "-" << m[i].month << "-" << m[i].day << "\nƬ����" << m[i].time << "����" << "\n��飺" << m[i].introduction << "\n�������֣�" << m[i].grade << "\nӰ����" << m[i].comment << "\n" << endl;
		flag1 = flag1 + 1;
		return flag1;
	}
	else
		return flag1;
}

//------------------------------------------------------------�ַ���������ѯ����------------------------------------------------------------------------
int stringIn(movies m[], int i, string name1, string name2,int flag2) {
	string::size_type flag;
	flag = name1.find(name2);
	if (flag != string::npos) {
		cout << "\n��Ӱ���ƣ�" << m[i].name << "\n��磺" << m[i].scrip << "\n���ݣ�" << m[i].director << "\n��Ա��" << m[i].actor << "\n���ͣ�" << m[i].type << "\n������" << m[i].area << "\n���ԣ�" << m[i].language << "\n��ӳ���ڣ�" << m[i].year << "-" << m[i].month << "-" << m[i].day << "\nƬ����" << m[i].time << "����" << "\n��飺" << m[i].introduction << "\n�������֣�" << m[i].grade << "\nӰ����" << m[i].comment << "\n" << endl;
		flag2 = flag2 + 1;
		return flag2;
	}
	else
		return flag2;
}


//------------------------------------------------------------��ӳ����������----------------------------------------------------------------------------
void datesort(movies m[],int k) {
	bool NoSwap;
	int i, j;
	for (i = 0; i < k - 1; i++) {
		for (j = k - 1; j > i; j--) {
			if (m[j].year > m[j - 1].year) {
				swap(m[j], m[j - 1]);
			}
		}
	}
	for (i = 0; i < k - 1; i++) {
		for (j = k - 1; j > i; j--) {
			if (m[j].year == m[j-1].year&&m[j].month > m[j - 1].month) {
				swap(m[j], m[j - 1]);
			}
		}
	}
	for (i = 0; i < k - 1; i++) {
		for (j = k - 1; j > i; j--) {
			if (m[j].year == m[j - 1].year&&m[j].month == m[j - 1].month&&m[j].day > m[j-1].day) {
				swap(m[j], m[j - 1]);
			}
		}
	}
	for (i = 0; i < k; i++) {
		cout << "��Ӱ���ƣ�" << m[i].name << "\n��磺" << m[i].scrip << "\n���ݣ�" << m[i].director << "\n��Ա��" << m[i].actor << "\n���ͣ�" << m[i].type << "\n������" << m[i].area << "\n���ԣ�" << m[i].language << "\n��ӳ���ڣ�" << m[i].year << "-" << m[i].month << "-" << m[i].day << "\nƬ����" << m[i].time << "����" << "\n��飺" << m[i].introduction << "\n�������֣�" << m[i].grade << "\nӰ����" << m[i].comment << "\n" << endl;
	}
}

//-----------------------------------------------------------���ӰƬ------------------------------------------------------------------------------
void inmovie(movies m[],int k) {
	movies madd;
	cout << "������Ҫ���ӰƬ����Ϣ:\n";
	cout << "��Ӱ��:";
	cin >> madd.name;
	cout << "���:";
	cin >> madd.scrip;
	cout << "����:";
	cin >> madd.director;
	cout << "��Ա:";
	cin >> madd.actor;
	cout << "����:";
	cin >> madd.type;
	cout << "����:";
	cin >> madd.area;
	cout << "����:";
	cin >> madd.language;
	cout << "��ӳ����:";
	cin >> madd.year >> madd.month >> madd.day;
	cout << "Ƭ��:";
	cin >> madd.time;
	cout << "���:";
	cin >> madd.introduction;
	cout << "����:";
	cin >> madd.grade;
	cout << "Ӱ��:";
	cin >> madd.comment;
	ofstream ofile("test1.txt",ios::app);
	if (!ofile.is_open()) {
		cout << "the file can not open" << endl;
		exit(1);
	}
	ofile << "\n" << madd.name << " " << madd.scrip << " " << madd.director << " " << madd.actor << " " << madd.type << " " << madd.area << " " << madd.language << " " << madd.year << " " << madd.month << " " << madd.day << " " << madd.time << " " << madd.introduction << " " << madd.grade << " " << madd.comment;
	ofile.close();
	m[k] = madd;
}
//-----------------------------------------------------------�����к���-------------------------------------------------------------------------------
void Msystem(movies m[],int choose,int k) {
	string nameem;  //��������ĵ�Ӱ����
	string dname;	//�������뵼������
	string marea;   //���������ѯ����
	string mactor;	//��������Ӱ������
	string mlanguage; //����
	string huojiang;//��
	string mtype;
	int test;  //�ж��Ƿ��ѯ����
	string::size_type flag; 
	int i;
	switch (choose) {
	case 0:
		/*for (int i = 0; i < k; i++) {
			cout << m[i].grade << "-";
			cout << m[i].name << " ";
		} */                                                      
		quickSort(m, 0, k - 1);
		cout << endl;
		for ( i = 0; i < k; i++) {
			cout.setf(ios::showpoint);
			cout << setprecision(2) << m[i].grade << "-";
			cout <<"��"<< m[i].name <<"��"<< endl;
		}
		break;
	case 1:
		cout << "���뵼�����ƣ�";
		cin >> dname;
		test = 0;
		for (i = 0; i < k; i++) {
			test = stringIn(m, i, m[i].director, dname,test);
		}
		if (test == 0)
			cout << "û�и���Ϣ��" << endl;
		break;
	case 2:
		cout << "������Ҫ�ĵ�Ӱ���ƣ�";
		cin >> nameem;
		test = 0;
		for (i = 0; i < k; i++) {
			test = stringIn(m, i, m[i].name, nameem,test);
		}
		if (test == 0)
			cout << "û�и���Ϣ��" << endl;
		break;
	case 3:
		cout << "��������Ҫ�ĵ������ƣ�";
		cin >> marea;
		test = 0;
		for ( i = 0; i < k; i++) {
			test = charsort(m, i, marea, m[i].area,test);
		}
		if (test == 0)
			cout << "û�и���Ϣ��" << endl;
		break;
	case 4:
		cout << "��������Ҫ��ѯ�����ͣ�";
		cin >> mtype;
		test = 0;
		for (i = 0; i < k; i++) {
			test = stringIn(m, i, m[i].type, mtype,test);
		}
		if (test == 0)
			cout << "û�и���Ϣ��" << endl;
		break;
	case 5:
		cout << "��������Ҫ��Ӱ�����֣�";
		cin >> mactor;
		test = 0;
		for (i = 0; i < k; i++) {
			test = stringIn(m, i, m[i].actor, mactor,test);
		}
		if (test == 0)
			cout << "û�и���Ϣ��" << endl;
		break;
	case 6:
		cout << "��������Ҫ��ѯ�����ԣ�";
		cin >> mlanguage;
		test = 0;
		for ( i = 0; i < k; i++) {
			test = charsort(m, i, mlanguage, m[i].language,test);
		}
		if (test == 0)
			cout << "û�и���Ϣ��" << endl;
		break;
	case 7:
		inmovie(m, k);
		break;
	case 8:
		datesort(m, k);
		break;
	case 9:
		exit(0) ;
	default:
		cout << "���벻���Ϲ淶" << endl;
		cin.clear();
		cin.sync();
		break;
	}
}