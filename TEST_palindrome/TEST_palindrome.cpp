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

int testTask()
{
	std::vector<bool (*)()>functptr = { test1, test2, test3, test4, test5 };//, test6, test7, test8, test9, test10 };
	for (size_t i = 0; i < functptr.size(); i++)
	{
		if (!(*functptr[i])())
		{
			return i + 1;
		}		
	}
	return 0;
}


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

std::string streamFile(std::string str)
{
	std::ofstream out("..\\test11.txt");
	//std::string dsa = std::filesystem::absolute(".").generic_u8string();
	out << str;
	out.close();
	system("..\\x64\\Debug\\palindrome.exe");
	std::ifstream in("..\\out.txt");
	in >> str;
	in.close();
	return str;
}