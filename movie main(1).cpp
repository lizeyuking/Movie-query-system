#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

typedef struct node {	//电影结构体
	string name;	//电影名称
	string scrip;	//编剧
	string director;//导演
	string actor;	//演员
	string type;	//电影类型
	string area;	//地区
	string language;	//语言
	int year;
	int month;
	int day;		//上映年月日
	int time;		//片场
	string introduction;	//简介
	double grade;		//豆瓣评分
	string comment;		//评论
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


//------------------------------------------主函数---------------------------------------------------------------------------------------------
int main() {
	movies m[50];
	int k = 0;
	string s;
	int choose;			//选择信息
	
	ifstream ifile("test1.txt");
	if (!ifile.is_open()) {
		cout << "the file can not open" << endl;
		exit(1);
	}

	for(int i = 0;!ifile.eof();i++) {
		if (!(ifile >> m[i].name))break;
		ifile  >> m[i].scrip >> m[i].director >> m[i].actor >> m[i].type >> m[i].area >> m[i].language >> m[i].year >> m[i].month >> m[i].day >> m[i].time >> m[i].introduction >> m[i].grade >> m[i].comment;
		//cout << "电影名称：" << m[i].name << "\n编剧：" << m[i].scrip << "\n导演：" << m[i].director << "\n演员：" << m[i].actor << "\n类型：" << m[i].type << "\n地区：" << m[i].area << "\n语言：" << m[i].language << "\n上映日期：" << m[i].year << "-" << m[i].month << "-" << m[i].day << "\n片长：" << m[i].time << "分钟" << "\n简介：" << m[i].introduction << "\n豆瓣评分：" << m[i].grade << "\n影评：" << m[i].comment << "\n" << endl;
		k++;
	}
	ifile.close();
	
	while (true) {
		cout << "--------Movie System--------" << endl;
		cout << "一共收入影片" << k << "部\n";
		cout << "选择一个你想查询的分类 " << endl;
		cout << "0:评分 1:导演 2:电影名称 3:地域 4:影片类型 5:电影演员 6:语言 7:添加影片 8:上映时间 9:退出" << endl;
		cout << "请输入：";
		cin >> choose;
		Msystem(m, choose, k);
		cout << "\n";
		if (choose == 7)
			k = k + 1;
	}
	system("pause");
	return 1;
}

//----------------------------------------------------------快速排序（排评分）--------------------------------------------------------------------------------------------
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


//--------------------------------------------------------------求数组长度-------------------------------------
template<class T>
int length(T& Array)
{
	return (sizeof(Array) / sizeof(Array[0]));
}




//------------------------------------------------------------冒泡排序（排评分）------------------------------------------------------------------------------------------
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

//-----------------------------------------------------------字符串查询函数---------------------------------------------------------------------------
int charsort(movies m[], int i, string name1, string name2,int flag1) {
	if (name1.compare(name2) == 0) {
		cout << "\n电影名称：" << m[i].name << "\n编剧：" << m[i].scrip << "\n导演：" << m[i].director << "\n演员：" << m[i].actor << "\n类型：" << m[i].type << "\n地区：" << m[i].area << "\n语言：" << m[i].language << "\n上映日期：" << m[i].year << "-" << m[i].month << "-" << m[i].day << "\n片长：" << m[i].time << "分钟" << "\n简介：" << m[i].introduction << "\n豆瓣评分：" << m[i].grade << "\n影评：" << m[i].comment << "\n" << endl;
		flag1 = flag1 + 1;
		return flag1;
	}
	else
		return flag1;
}

//------------------------------------------------------------字符串包含查询函数------------------------------------------------------------------------
int stringIn(movies m[], int i, string name1, string name2,int flag2) {
	string::size_type flag;
	flag = name1.find(name2);
	if (flag != string::npos) {
		cout << "\n电影名称：" << m[i].name << "\n编剧：" << m[i].scrip << "\n导演：" << m[i].director << "\n演员：" << m[i].actor << "\n类型：" << m[i].type << "\n地区：" << m[i].area << "\n语言：" << m[i].language << "\n上映日期：" << m[i].year << "-" << m[i].month << "-" << m[i].day << "\n片长：" << m[i].time << "分钟" << "\n简介：" << m[i].introduction << "\n豆瓣评分：" << m[i].grade << "\n影评：" << m[i].comment << "\n" << endl;
		flag2 = flag2 + 1;
		return flag2;
	}
	else
		return flag2;
}


//------------------------------------------------------------上映日期排序函数----------------------------------------------------------------------------
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
		cout << "电影名称：" << m[i].name << "\n编剧：" << m[i].scrip << "\n导演：" << m[i].director << "\n演员：" << m[i].actor << "\n类型：" << m[i].type << "\n地区：" << m[i].area << "\n语言：" << m[i].language << "\n上映日期：" << m[i].year << "-" << m[i].month << "-" << m[i].day << "\n片长：" << m[i].time << "分钟" << "\n简介：" << m[i].introduction << "\n豆瓣评分：" << m[i].grade << "\n影评：" << m[i].comment << "\n" << endl;
	}
}

//-----------------------------------------------------------添加影片------------------------------------------------------------------------------
void inmovie(movies m[],int k) {
	movies madd;
	cout << "请输入要添加影片的信息:\n";
	cout << "电影名:";
	cin >> madd.name;
	cout << "编剧:";
	cin >> madd.scrip;
	cout << "导演:";
	cin >> madd.director;
	cout << "演员:";
	cin >> madd.actor;
	cout << "类型:";
	cin >> madd.type;
	cout << "地区:";
	cin >> madd.area;
	cout << "语言:";
	cin >> madd.language;
	cout << "上映日期:";
	cin >> madd.year >> madd.month >> madd.day;
	cout << "片长:";
	cin >> madd.time;
	cout << "简介:";
	cin >> madd.introduction;
	cout << "评分:";
	cin >> madd.grade;
	cout << "影评:";
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
//-----------------------------------------------------------主运行函数-------------------------------------------------------------------------------
void Msystem(movies m[],int choose,int k) {
	string nameem;  //键盘输入的电影名称
	string dname;	//键盘输入导演名称
	string marea;   //键盘输入查询地域
	string mactor;	//键盘输入影星名字
	string mlanguage; //语言
	string huojiang;//获奖
	string mtype;
	int test;  //判断是否查询到了
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
			cout <<"《"<< m[i].name <<"》"<< endl;
		}
		break;
	case 1:
		cout << "输入导演名称：";
		cin >> dname;
		test = 0;
		for (i = 0; i < k; i++) {
			test = stringIn(m, i, m[i].director, dname,test);
		}
		if (test == 0)
			cout << "没有该信息！" << endl;
		break;
	case 2:
		cout << "输入想要的电影名称：";
		cin >> nameem;
		test = 0;
		for (i = 0; i < k; i++) {
			test = stringIn(m, i, m[i].name, nameem,test);
		}
		if (test == 0)
			cout << "没有该信息！" << endl;
		break;
	case 3:
		cout << "请输入想要的地域名称：";
		cin >> marea;
		test = 0;
		for ( i = 0; i < k; i++) {
			test = charsort(m, i, marea, m[i].area,test);
		}
		if (test == 0)
			cout << "没有该信息！" << endl;
		break;
	case 4:
		cout << "请输入想要查询的类型：";
		cin >> mtype;
		test = 0;
		for (i = 0; i < k; i++) {
			test = stringIn(m, i, m[i].type, mtype,test);
		}
		if (test == 0)
			cout << "没有该信息！" << endl;
		break;
	case 5:
		cout << "请输入想要的影星名字：";
		cin >> mactor;
		test = 0;
		for (i = 0; i < k; i++) {
			test = stringIn(m, i, m[i].actor, mactor,test);
		}
		if (test == 0)
			cout << "没有该信息！" << endl;
		break;
	case 6:
		cout << "请输入想要查询的语言：";
		cin >> mlanguage;
		test = 0;
		for ( i = 0; i < k; i++) {
			test = charsort(m, i, mlanguage, m[i].language,test);
		}
		if (test == 0)
			cout << "没有该信息！" << endl;
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
		cout << "输入不符合规范" << endl;
		cin.clear();
		cin.sync();
		break;
	}
}