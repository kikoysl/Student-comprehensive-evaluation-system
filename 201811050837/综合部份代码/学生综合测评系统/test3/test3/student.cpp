#include <Windows.h>
#include <mysql.h>
#include <iostream>
#include <iomanip>
using namespace std;

//学生类
class Student 
{
	int number;      //学号
	char name[200];  //名字
	char sex[100];   //性别
	char address[35];	//家庭住址
	char phone[14];		//电话
	int chinese, english, math, pinde; //语文，数学，英语，品德
	int huping, teacher;		        //互评分，教师评分
	double average, score_all;			//三科平均分，综合总分        

public:
	void Display(); //显示函数
	int menu();     //菜单函数
	void input();   //录入函数
	void Score_input(); //成绩输入函数
	int Alter();    //修改函数
	int Alter_menu();  //修改函数菜单
	int Select();    //选择函数
	int Select_menu();  //选择函数菜单
	int Delete();     //删除函数
	int Delete_menu(); //删除函数菜单
	int ScoreStatistics();  //统计分数函数
	int ScoreStatistics_menu(); //统计分数函数菜单
};

//成绩类
class Score :public Student 
{
public:
	void Ave_Sort();   //平均成绩排序输出
	void Sum_Sort();  //综测成绩排序输出
};

//查询类
class Search : public Student 
{
public:
	void Number_Select(); //按学号信息查询
};

//删除类
class Remove : public Student
{
public:
	void Number_Del(); 
};

//修改类
class Change : public Student 
{
public:
	void Alter_Score(); //修改学生成绩
	void Alter_Inform();//修改学生信息
};

//按学号删除
void Remove::Number_Del() 
{
	Student stu1;
	stu1.Display();
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk"); //成功时返回0

	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		printf("\n数据库连接发生错误!");
	}
	else
	{
		char std[200];
		int na;
		cout << endl << "请输入要删除信息的学生学号: " << endl;
		cin >> na;
		sprintf(std, "delete from student where number=%d", na);
		if (mysql_query(&mysql, std))
		{
			cout << "数据查询发生错误" << endl;
		}
		else
		{
			cout << "删除成功！" << endl;
		}
	}
}

//成绩输入函数
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
		printf("\n数据库连接发生错误!");
	}
	else
	{
		cout << "请输入想输入成绩的同学学号";
		cin >> nm;
		cout << endl << "请输入学生成绩数据" << endl << endl;
		mysql_query(&mysql, "SET_NAMES gbk");
		cout << "语文 " << "数学 " << "英语 " << "品德 " << "互评 " << "师评 "  << endl << endl;
		cin >> in.chinese >> in.math >> in.english >> in.pinde >> in.huping >> in.teacher ;
		sprintf(std, "update student set chinese=%d,math=%d,english=%d,pinde=%d,huping=%d,teacher=%d where number=%d;", in.chinese, in.math, in.english, in.pinde, in.huping, in.teacher,nm);
		mysql_query(&mysql,std);
		cout << "添加成功" << endl;

		int ave;
		mysql_query(&mysql, "select (student.chinese+student.math+student.english)/3 from student");
		//cout << "平均分:";
		resultset = mysql_store_result(&mysql);

		if (mysql_num_rows(resultset) != NULL)
		{
			numFields = mysql_num_fields(resultset);//获取查询总数
			//int i = 0;
			while (row = mysql_fetch_row(resultset))
			{
				//cout << row[0];
				ave = atoi(row[0]); //存入到ave的数组中。
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
			numFields = mysql_num_fields(resultset);//获取查询总数
			//int i = 0;
			while (row = mysql_fetch_row(resultset))
			{
				//cout << row[0];
				sum = atoi(row[0]); //存入到总成绩的数组中。
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

//信息输入函数
void Student::input()
{
	Student in;
	char std[200];
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "数据库连接错误！" << endl;
	}
	else
	{
		cout << endl << "请录入学生信息数据" << endl << endl;
		mysql_query(&mysql, "SET NAMES gbk");
		cout << "学号  " << "姓名  " << "性别  " << "家庭住址  " << "电话" << endl;
		cin >> in.number >> in.name >> in.sex >> in.address >> in.phone;
		sprintf(std, "insert into student(number,name,sex,address,phone) VALUES(%d,'%s','%s','%s','%s');", in.number, in.name, in.sex, in.address, in.phone);
		mysql_query(&mysql, std);
		cout << "添加成功" << endl;
	}
}

//平均成绩排序输出
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
		printf("\n数据库连接发生错误!"); 
	}
	else
	{
		cout << endl << "------------------------------------------------------------平均成绩排名-----------------------------------------------------------------" << endl;
		cout << "  学号    " << "   姓名     " << "  性别    " << " 家庭住址     " << "   电话     " << "  平均成绩     " << "总成绩    " << endl;
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

//综合成绩排序输出
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
		printf("\n数据库连接发生错误!");
	}
	else
	{
		cout << endl << "------------------------------------------------------------综合成绩排名-----------------------------------------------------------------" << endl;
		cout << "  学号    " << "   姓名     " << "  性别    " << " 家庭住址     " << "   电话     " << "  平均成绩     " << "总成绩    " << endl;
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

//按学号查询信息
void Search::Number_Select()
{
	MYSQL mysql;
	mysql_init(&mysql);
	MYSQL_RES *resultset = NULL;
	MYSQL_ROW row;
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "数据库连接错误！" << endl;
	}
	else
	{
		char std[200];
		int n;
		cout << endl << "请输入要查的学生学号：" << endl;
		cin >> n;
		cout << endl << "------------------------------------------------------------------------------显示信息-----------------------------------------------------------------------------------------" << endl;
		cout << "    学号    " << "姓名    " << "  性别      " << "家庭住址  " << "   电话   " << "    语文  " << "    数学  " << "   英语   " << "  品德   " << "  互评  " << "  师评  " << "  平均成绩    " << " 综合成绩    " << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		sprintf(std, "select * from student where number=%d;", n);
		if (mysql_query(&mysql, std))
		{
			printf("\n数据查询发生错误\n");
		}
		else
		{
			resultset = mysql_store_result(&mysql);
			if (mysql_num_rows(resultset) != NULL)
			{
				int numFields = mysql_num_fields(resultset);//**获得表中的字段
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
				cout << "无结果！";
			}
		}
		mysql_free_result(resultset);
	}
}

//修改学生信息
void Change::Alter_Inform()
{
	cout << "显示学生数据" << endl;
	Change Zhang;
	Zhang.Display();
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "数据库连接错误！" << endl;
	}
	else
	{
		char std[200];
		int n;
		int num;
		char name[100], sex[100], address[100], phone[100];
		cout << endl << "请输入要修改信息的学生学号：" << endl;
		cin >> n;
		cout << endl << "请输入要更新的全部信息：" << endl;
		cin >> num >> name >> sex >> address >> phone;
		sprintf(std, "update student set number=%d,name='%s',sex='%s',address='%s',phone='%s' where number=%d;", num, name, sex, address, phone, n);
		if (mysql_query(&mysql, std))
		{
			printf("\n数据库更改发生错误\n");
		}
		else
		{
			printf("\n数据库更改数据成功\n");
		}
	}
}

//修改学生成绩
void Change::Alter_Score()
{
	cout << "显示学生数据" << endl;
	Change Zhang;
	Zhang.Display();
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "数据库连接错误！" << endl;
	}
	else
	{
		char std[200];
		int n;
		int chinese,math,english,pinde,huping,teacher;
		cout << endl << "请输入要修改信息的学生学号：" << endl;
		cin >> n;
		cout << endl << "请输入要更新的全部成绩：" << endl;
		cin >> chinese >> math >> english >> pinde >> huping >> teacher;
		sprintf(std, "update student set chinese=%d,math=%d,english=%d,pinde=%d,huping=%d,teacher=%d where number=%d;", chinese, math, english, pinde, huping, teacher, n);
		if (mysql_query(&mysql, std))
		{
			printf("\n数据库更改发生错误\n");
		}
		else
		{
			printf("\n数据库更改数据成功\n");
		}
	}
}

//展示函数
void Student::Display()
{
	MYSQL mysql;
	MYSQL_RES *resultset = NULL;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "\n数据库连接发生错误！";
	}
	else
	{
		if (mysql_query(&mysql, "select * from student"))
		{
			cout << "表格数据显示失败！";
		}
		else
		{
			cout << endl << "------------------------------------------------------------------------------显示信息-----------------------------------------------------------------------------------------" << endl;
			cout << "    学号    " << "姓名    " << "  性别      " << "家庭住址  " << "   电话   " << "    语文  " << "    数学  " << "   英语   " << "  品德   " << "  互评  " << "  师评  " << "  平均成绩    " << " 综合成绩    " << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl; 
			resultset = mysql_store_result(&mysql);
			if (mysql_num_rows(resultset) != NULL)
			{
				int numFields = mysql_num_fields(resultset);//**获得表中的字段
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
				cout << "显示无果！";
			}
		}
		mysql_free_result(resultset);
	}
}

//主菜单
int Student::menu()
{
	int s;
	cout
		<< endl
		<< "1:录入学生信息" << endl
		<< "2:显示学生信息" << endl
		<< "3:查询学生信息" << endl
		<< "4:删除学生信息" << endl
		<< "5:修改学生信息" << endl
		<< "6:统计学生成绩" << endl
		<< "0:退出系统" << endl << endl
		<< "请选择:";
	cin >> s;
	return s;
}

//修改菜单
int Student::Alter_menu()
{
	int a;
	cout
		<< endl
		<< "1:修改学生信息" << endl
		<< "2:修改学生成绩" << endl
		<< "0:后退" << endl << endl
		<< "请选择:";
	cin >> a;
	return a;
}

//查询菜单
int Student::Select_menu()
{
	int k;
	cout
		<< endl
		<< "1:按学号查询" << endl
		<< "0:后退" << endl << endl
		<< "请选择:";
	cin >> k;
	return k;
}

//删除菜单
int Student::Delete_menu()
{
	int g;
	cout
		<< endl
		<< "1:按学号删除" << endl
		<< "0:后退" << endl << endl
		<< "请选择:";
	cin >> g;
	return g;
}

//成绩菜单
int Student::ScoreStatistics_menu()//成绩统计菜单
{
	int d;
	cout
		<< endl
		<< "1:输入学生成绩" << endl
		<< "2:平均成绩排名输出" << endl
		<< "3:综合成绩排名输出" << endl
		<< "0:后退" << endl << endl
		<< "请选择:";
	cin >> d;
	return d;
}

//修改函数
int Student::Alter()//修改
{
	cout << endl << "进入修改系统..." << endl;
	int h;
	Change change;
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "数据库连接错误！" << endl;
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
				cout << "请选择正确的菜单项进行操作。多谢合作!" << endl;
			}
		}
	}
	return 0;
}

//查询函数
int Student::Select()//查询
{
	cout << endl << "进入查询系统..." << endl;
	Search search;
	MYSQL mysql;
	int h;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "数据库连接错误！" << endl;
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
				cout << "请选择正确的菜单项进行操作。多谢合作!" << endl;
			}
		}
	}
	return 0;
}

//删除函数
int Student::Delete()//删除
{
	cout << endl << "进入删除系统..." << endl;
	Remove remove;
	MYSQL mysql;
	int h;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "数据库连接错误！" << endl;
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
				cout << "请选择正确的菜单项进行操作。多谢合作!" << endl;
			}
		}
	}
	return 0;
}

//成绩函数
int Student::ScoreStatistics()//成绩统计
{
	cout << endl << "进入成绩统计系统..." << endl;
	Score statistics;
	MYSQL mysql;
	int h;
	mysql_init(&mysql);
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (!mysql_real_connect(&mysql, "localhost", "root", "yeyuni147", "students", 3306, NULL, 0))
	{
		cout << "数据库连接错误！" << endl;
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
				cout << "请选择正确的菜单项进行操作。多谢合作!" << endl;
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
		cout << "\n数据库连接发生错误！\n";
	}
	else
	{
		cout << "数据库连接成功！\n";
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
				cout << endl << "~学生信息管理系统操作完毕~" << endl;
				exit(1);
				break;
			default:
				cout << endl << "请选择正确的菜单项进行操作!" << endl;
			}
		}
	}
	return 0;
}