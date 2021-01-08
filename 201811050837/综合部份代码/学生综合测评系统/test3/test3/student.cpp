#include <Windows.h>
#include <mysql.h>
#include <iostream>
#include <iomanip>
using namespace std;

//ѧ����
class Student 
{
	int number;      //ѧ��
	char name[200];  //����
	char sex[100];   //�Ա�
	char address[35];	//��ͥסַ
	char phone[14];		//�绰
	int chinese, english, math, pinde; //���ģ���ѧ��Ӣ�Ʒ��
	int huping, teacher;		        //�����֣���ʦ����
	double average, score_all;			//����ƽ���֣��ۺ��ܷ�        

public:
	void Display(); //��ʾ����
	int menu();     //�˵�����
	void input();   //¼�뺯��
	void Score_input(); //�ɼ����뺯��
	int Alter();    //�޸ĺ���
	int Alter_menu();  //�޸ĺ����˵�
	int Select();    //ѡ����
	int Select_menu();  //ѡ�����˵�
	int Delete();     //ɾ������
	int Delete_menu(); //ɾ�������˵�
	int ScoreStatistics();  //ͳ�Ʒ�������
	int ScoreStatistics_menu(); //ͳ�Ʒ��������˵�
};

//�ɼ���
class Score :public Student 
{
public:
	void Ave_Sort();   //ƽ���ɼ��������
	void Sum_Sort();  //�۲�ɼ��������
};

//��ѯ��
class Search : public Student 
{
public:
	void Number_Select(); //��ѧ����Ϣ��ѯ
};

//ɾ����
class Remove : public Student
{
public:
	void Number_Del(); 
};

//�޸���
class Change : public Student 
{
public:
	void Alter_Score(); //�޸�ѧ���ɼ�
	void Alter_Inform();//�޸�ѧ����Ϣ
};

//��ѧ��ɾ��
void Remove::Number_Del() 
{
	Student stu1;
	stu1.Display();
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk"); //�ɹ�ʱ����0

	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		printf("\n���ݿ����ӷ�������!");
	}
	else
	{
		char std[200];
		int na;
		cout << endl << "������Ҫɾ����Ϣ��ѧ��ѧ��: " << endl;
		cin >> na;
		sprintf(std, "delete from student where number=%d", na);
		if (mysql_query(&mysql, std))
		{
			cout << "���ݲ�ѯ��������" << endl;
		}
		else
		{
			cout << "ɾ���ɹ���" << endl;
		}
	}
}

//�ɼ����뺯��
void Student::Score_input()
{
	Student in;
	int numFields = 0;
	int nm;
	char std[200];
	MYSQL mysql;
	MYSQL_RES *resultset;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		printf("\n���ݿ����ӷ�������!");
	}
	else
	{
		cout << "������������ɼ���ͬѧѧ��";
		cin >> nm;
		cout << endl << "������ѧ���ɼ�����" << endl << endl;
		mysql_query(&mysql, "SET_NAMES gbk");
		cout << "���� " << "��ѧ " << "Ӣ�� " << "Ʒ�� " << "���� " << "ʦ�� "  << endl << endl;
		cin >> in.chinese >> in.math >> in.english >> in.pinde >> in.huping >> in.teacher ;
		sprintf(std, "update student set chinese=%d,math=%d,english=%d,pinde=%d,huping=%d,teacher=%d where number=%d;", in.chinese, in.math, in.english, in.pinde, in.huping, in.teacher,nm);
		mysql_query(&mysql,std);
		cout << "��ӳɹ�" << endl;

		int ave;
		mysql_query(&mysql, "select (student.chinese+student.math+student.english)/3 from student");
		//cout << "ƽ����:";
		resultset = mysql_store_result(&mysql);

		if (mysql_num_rows(resultset) != NULL)
		{
			numFields = mysql_num_fields(resultset);//��ȡ��ѯ����
			//int i = 0;
			while (row = mysql_fetch_row(resultset))
			{
				//cout << row[0];
				ave = atoi(row[0]); //���뵽ave�������С�
				//i++;
				//cout << endl;
			}
		}
		char std1[200];
		mysql_query(&mysql, "SET NAMES gbk");
		//for (int j = 0; j < numFields; j++)
	//	{
			sprintf(std1, "update student set average=%d where number=%d;", ave,nm);
		//}
		mysql_query(&mysql, std1);

		int sum;
		mysql_query(&mysql, "select (student.average*0.6+student.pinde*0.1+student.huping*0.1+student.teacher*0.2) from student");
		resultset = mysql_store_result(&mysql);

		if (mysql_num_rows(resultset) != NULL)
		{
			numFields = mysql_num_fields(resultset);//��ȡ��ѯ����
			//int i = 0;
			while (row = mysql_fetch_row(resultset))
			{
				//cout << row[0];
				sum = atoi(row[0]); //���뵽�ܳɼ��������С�
				//i++;
				//cout << endl;
			}
		}
		char std2[200];
		mysql_query(&mysql, "SET NAMES gbk");
	//	for (int j = 0; j < numFields; j++)
		//{
			sprintf(std2, "update student set score_all=%d where number=%d;", sum,nm);
		//}
		mysql_query(&mysql, std2);
		mysql_free_result(resultset);
	}
}

//��Ϣ���뺯��
void Student::input()
{
	Student in;
	char std[200];
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		cout << endl << "��¼��ѧ����Ϣ����" << endl << endl;
		mysql_query(&mysql, "SET NAMES gbk");
		cout << "ѧ��  " << "����  " << "�Ա�  " << "��ͥסַ  " << "�绰" << endl;
		cin >> in.number >> in.name >> in.sex >> in.address >> in.phone;
		sprintf(std, "insert into student(number,name,sex,address,phone) VALUES(%d,'%s','%s','%s','%s');", in.number, in.name, in.sex, in.address, in.phone);
		mysql_query(&mysql, std);
		cout << "��ӳɹ�" << endl;
	}
}

//ƽ���ɼ��������
void Score::Ave_Sort()
{
	Student Zhang;
	int numFields = 0;
	//Zhang.Display();
	MYSQL mysql;
	mysql_init(&mysql);
	MYSQL_RES *resultset;
	MYSQL_ROW row;
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		printf("\n���ݿ����ӷ�������!"); 
	}
	else
	{
		cout << endl << "------------------------------------------------------------ƽ���ɼ�����-----------------------------------------------------------------" << endl;
		cout << "  ѧ��    " << "   ����     " << "  �Ա�    " << " ��ͥסַ     " << "   �绰     " << "  ƽ���ɼ�     " << "�ܳɼ�    " << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		mysql_query(&mysql, "select number,name,sex,address,phone,average,score_all from student order by average desc");
		resultset = mysql_store_result(&mysql);

		if (mysql_num_rows(resultset) != NULL)
		{
			//int numRows = mysql_num_rows(resultset);
			int numFields = mysql_num_fields(resultset);
			while (row = mysql_fetch_row(resultset))
			{
				int i;
				for (i = 0; i < numFields; i++)
				{
					cout << "    " << row[i] << "    ";
				}
				cout << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			}
		}
	}
}

//�ۺϳɼ��������
void Score::Sum_Sort()
{
	Student Zhang;
	int numFields = 0;
	//Zhang.Display();
	MYSQL mysql;
	mysql_init(&mysql);
	MYSQL_RES *resultset;
	MYSQL_ROW row;
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		printf("\n���ݿ����ӷ�������!");
	}
	else
	{
		cout << endl << "------------------------------------------------------------�ۺϳɼ�����-----------------------------------------------------------------" << endl;
		cout << "  ѧ��    " << "   ����     " << "  �Ա�    " << " ��ͥסַ     " << "   �绰     " << "  ƽ���ɼ�     " << "�ܳɼ�    " << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		mysql_query(&mysql, "select number,name,sex,address,phone,average,score_all from student order by score_all desc");
		resultset = mysql_store_result(&mysql);

		if (mysql_num_rows(resultset) != NULL)
		{
			//int numRows = mysql_num_rows(resultset);
			int numFields = mysql_num_fields(resultset);
			while (row = mysql_fetch_row(resultset))
			{
				int i;
				for (i = 0; i < numFields; i++)
				{
					cout << "    " << row[i] << "    ";
				}
				cout << endl;
				cout << "---------------------------------------------------------------------------------------------" << endl;
			}
		}
	}
}

//��ѧ�Ų�ѯ��Ϣ
void Search::Number_Select()
{
	MYSQL mysql;
	mysql_init(&mysql);
	MYSQL_RES *resultset = NULL;
	MYSQL_ROW row;
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		char std[200];
		int n;
		cout << endl << "������Ҫ���ѧ��ѧ�ţ�" << endl;
		cin >> n;
		cout << endl << "------------------------------------------------------------------------------��ʾ��Ϣ-----------------------------------------------------------------------------------------" << endl;
		cout << "    ѧ��    " << "����    " << "  �Ա�      " << "��ͥסַ  " << "   �绰   " << "    ����  " << "    ��ѧ  " << "   Ӣ��   " << "  Ʒ��   " << "  ����  " << "  ʦ��  " << "  ƽ���ɼ�    " << " �ۺϳɼ�    " << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		sprintf(std, "select * from student where number=%d;", n);
		if (mysql_query(&mysql, std))
		{
			printf("\n���ݲ�ѯ��������\n");
		}
		else
		{
			resultset = mysql_store_result(&mysql);
			if (mysql_num_rows(resultset) != NULL)
			{
				int numFields = mysql_num_fields(resultset);//**��ñ��е��ֶ�
				while (row = mysql_fetch_row(resultset))
				{
					int i = 0;
					for (i = 0; i < numFields; i++)
					{
						mysql_query(&mysql, "SET NAMES gbk");
						cout << "    " << row[i] << "    ";
					}
					cout << endl;
				}
				cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "�޽����";
			}
		}
		mysql_free_result(resultset);
	}
}

//�޸�ѧ����Ϣ
void Change::Alter_Inform()
{
	cout << "��ʾѧ������" << endl;
	Change Zhang;
	Zhang.Display();
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		char std[200];
		int n;
		int num;
		char name[100], sex[100], address[100], phone[100];
		cout << endl << "������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�" << endl;
		cin >> n;
		cout << endl << "������Ҫ���µ�ȫ����Ϣ��" << endl;
		cin >> num >> name >> sex >> address >> phone;
		sprintf(std, "update student set number=%d,name='%s',sex='%s',address='%s',phone='%s' where number=%d;", num, name, sex, address, phone, n);
		if (mysql_query(&mysql, std))
		{
			printf("\n���ݿ���ķ�������\n");
		}
		else
		{
			printf("\n���ݿ�������ݳɹ�\n");
		}
	}
}

//�޸�ѧ���ɼ�
void Change::Alter_Score()
{
	cout << "��ʾѧ������" << endl;
	Change Zhang;
	Zhang.Display();
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		char std[200];
		int n;
		int chinese,math,english,pinde,huping,teacher;
		cout << endl << "������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�" << endl;
		cin >> n;
		cout << endl << "������Ҫ���µ�ȫ���ɼ���" << endl;
		cin >> chinese >> math >> english >> pinde >> huping >> teacher;
		sprintf(std, "update student set chinese=%d,math=%d,english=%d,pinde=%d,huping=%d,teacher=%d where number=%d;", chinese, math, english, pinde, huping, teacher, n);
		if (mysql_query(&mysql, std))
		{
			printf("\n���ݿ���ķ�������\n");
		}
		else
		{
			printf("\n���ݿ�������ݳɹ�\n");
		}
	}
}

//չʾ����
void Student::Display()
{
	MYSQL mysql;
	MYSQL_RES *resultset = NULL;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "\n���ݿ����ӷ�������";
	}
	else
	{
		if (mysql_query(&mysql, "select * from student"))
		{
			cout << "���������ʾʧ�ܣ�";
		}
		else
		{
			cout << endl << "------------------------------------------------------------------------------��ʾ��Ϣ-----------------------------------------------------------------------------------------" << endl;
			cout << "    ѧ��    " << "����    " << "  �Ա�      " << "��ͥסַ  " << "   �绰   " << "    ����  " << "    ��ѧ  " << "   Ӣ��   " << "  Ʒ��   " << "  ����  " << "  ʦ��  " << "  ƽ���ɼ�    " << " �ۺϳɼ�    " << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl; 
			resultset = mysql_store_result(&mysql);
			if (mysql_num_rows(resultset) != NULL)
			{
				int numFields = mysql_num_fields(resultset);//**��ñ��е��ֶ�
				while (row = mysql_fetch_row(resultset))
				{
					int i = 0;
					for (i = 0; i < numFields; i++)
					{
						mysql_query(&mysql, "SET NAMES gbk");
						cout << "    " << row[i] << "   ";
					}
					cout << endl;
					cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "��ʾ�޹���";
			}
		}
		mysql_free_result(resultset);
	}
}

//���˵�
int Student::menu()
{
	int s;
	cout
		<< endl
		<< "1:¼��ѧ����Ϣ" << endl
		<< "2:��ʾѧ����Ϣ" << endl
		<< "3:��ѯѧ����Ϣ" << endl
		<< "4:ɾ��ѧ����Ϣ" << endl
		<< "5:�޸�ѧ����Ϣ" << endl
		<< "6:ͳ��ѧ���ɼ�" << endl
		<< "0:�˳�ϵͳ" << endl << endl
		<< "��ѡ��:";
	cin >> s;
	return s;
}

//�޸Ĳ˵�
int Student::Alter_menu()
{
	int a;
	cout
		<< endl
		<< "1:�޸�ѧ����Ϣ" << endl
		<< "2:�޸�ѧ���ɼ�" << endl
		<< "0:����" << endl << endl
		<< "��ѡ��:";
	cin >> a;
	return a;
}

//��ѯ�˵�
int Student::Select_menu()
{
	int k;
	cout
		<< endl
		<< "1:��ѧ�Ų�ѯ" << endl
		<< "0:����" << endl << endl
		<< "��ѡ��:";
	cin >> k;
	return k;
}

//ɾ���˵�
int Student::Delete_menu()
{
	int g;
	cout
		<< endl
		<< "1:��ѧ��ɾ��" << endl
		<< "0:����" << endl << endl
		<< "��ѡ��:";
	cin >> g;
	return g;
}

//�ɼ��˵�
int Student::ScoreStatistics_menu()//�ɼ�ͳ�Ʋ˵�
{
	int d;
	cout
		<< endl
		<< "1:����ѧ���ɼ�" << endl
		<< "2:ƽ���ɼ��������" << endl
		<< "3:�ۺϳɼ��������" << endl
		<< "0:����" << endl << endl
		<< "��ѡ��:";
	cin >> d;
	return d;
}

//�޸ĺ���
int Student::Alter()//�޸�
{
	cout << endl << "�����޸�ϵͳ..." << endl;
	int h;
	Change change;
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		while (1)
		{
			h = change.Alter_menu();
			switch (h)
			{
			case 1:
				change.Alter_Inform();
				break;
			case 2:
				change.Alter_Score();

				break;
			case 0:
				return 0;
				break;
			default:
				cout << "��ѡ����ȷ�Ĳ˵�����в�������л����!" << endl;
			}
		}
	}
	return 0;
}

//��ѯ����
int Student::Select()//��ѯ
{
	cout << endl << "�����ѯϵͳ..." << endl;
	Search search;
	MYSQL mysql;
	int h;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		while (1)
		{
			h = search.Select_menu();
			switch (h)
			{
			case 1:
				search.Number_Select();
				break;
			case 0:
				return 0;
				break;
			default:
				cout << "��ѡ����ȷ�Ĳ˵�����в�������л����!" << endl;
			}
		}
	}
	return 0;
}

//ɾ������
int Student::Delete()//ɾ��
{
	cout << endl << "����ɾ��ϵͳ..." << endl;
	Remove remove;
	MYSQL mysql;
	int h;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		while (1)
		{
			h = remove.Delete_menu();
			switch (h)
			{
			case 1:
				remove.Number_Del();

				break;
			case 0:
				return 0;
				break;
			default:
				cout << "��ѡ����ȷ�Ĳ˵�����в�������л����!" << endl;
			}
		}
	}
	return 0;
}

//�ɼ�����
int Student::ScoreStatistics()//�ɼ�ͳ��
{
	cout << endl << "����ɼ�ͳ��ϵͳ..." << endl;
	Score statistics;
	MYSQL mysql;
	int h;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "���ݿ����Ӵ���" << endl;
	}
	else
	{
		while (1)
		{
			h = statistics.ScoreStatistics_menu();
			switch (h)
			{
			case 1:
				statistics.Score_input();
				break;
			case 2:
				statistics.Ave_Sort();
				break;
			case 3:
				statistics.Sum_Sort();
				break;
			case 0:
				return 0;
				break;
			default:
				cout << "��ѡ����ȷ�Ĳ˵�����в�������л����!" << endl;
			}
		}
	}
	return 0;
}


int main()
{
	int n;
	Student Zhang;
	MYSQL mysql;
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "\n���ݿ����ӷ�������\n";
	}
	else
	{
		cout << "���ݿ����ӳɹ���\n";
		system("PAUSE");

		while (1)
		{
			n = Zhang.menu();
			switch (n)
			{
			case 1:
				Zhang.input();
				break;
			case 2:
				Zhang.Display();
				break;
			case 3:
				Zhang.Select();
				break;
			case 4:
				Zhang.Delete();
				break;
			case 5:
				Zhang.Alter();
				break;
			case 6:
				Zhang.ScoreStatistics();
				break;
			case 0:
				cout << endl << "~ѧ����Ϣ����ϵͳ�������~" << endl;
				exit(1);
				break;
			default:
				cout << endl << "��ѡ����ȷ�Ĳ˵�����в���!" << endl;
			}
		}
	}
	return 0;
}