#include <iostream>
#include <fstream>
#include <filesystem>

std::string streamFile(std::string);

bool test1();
bool test2();
bool test3();
bool test4();
bool test5();
bool test6();
bool test7();
bool test8();
bool test9();
bool test10();

int testTask();

int main() 
{
	unsigned N = testTask();
	if (N == 0)
	{
		std::cout << "OK";
	}
	else
	{
		std::cout <<"Test " << N << " failed";
	}
}


int testTask()
{
	std::vector<bool (*)()>functptr = { test1, test2, test3, test4, test5, test6, test7, test8,  test9, test10 }; 
	for (size_t i = 0; i < functptr.size(); i++)
	{
		if (!(*functptr[i])())
		{
			return i + 1;
		}
	}
	return 0;
}


bool test1() //нечет - общее кол-во символов, нечет - конкретной буквы
{
	return streamFile("ASDZXCQWEVVV") == "VAV";
}

bool test2() // чет, нечет
{
	return streamFile("ASDZXVCVDFGV") == "DVAVD";
}

bool test3() // чет, чет
{
	return streamFile("AAEDEDFGFG") == "ADEFGGFEDA";
}

bool test4() //
{
	return streamFile("POLLLINDROM") == "LODOL";
}

bool test5() //
{
	return streamFile("ASDASDASDASDASDZSDZSDZSDZSDZSDZSFFEFEFEFEFQEFSEFSDFGDFHGDFHHD") == "AADDDDDDDEEEFFFFFGHSSSSSSZZZAZZZSSSSSSHGFFFFFEEEDDDDDDDAA";
}

bool test6() //проверка пустого символа
{
	return  streamFile("") == "";

}

bool test7() //проверка недопустимых символов (кириллицы)
{
	return streamFile("Проверка кириллицы") == "";
}

bool test8() //проверка недопустимых символов
{
	return streamFile("!~@#$%^^*(&%_)__+") == "";
}

bool test9() //проверка нижнего регистра
{
	return streamFile("aassddffgg") == "";
}

bool test10() //проверка палиндрома из 1 символа
{
	return streamFile("A") == "A";
}

std::string streamFile(std::string str)
{
	std::ofstream out("..\\test11.txt");
	//std::string dsa = std::filesystem::absolute(".").generic_u8string();
	out << str;
	out.close();
	system("..\\x64\\Debug\\palindrome.exe");
	str = "";
	std::ifstream in("..\\out.txt");
	in >> str;
	in.close();
	return str;
}