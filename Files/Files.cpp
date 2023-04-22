// Files
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;
//#define write_to_file
//#define read_from_file
//#define copy_file

int main()
{
    setlocale(LC_ALL, "rus");
#ifdef write_to_file
    ofstream fout;
    fout.open("File.txt", std::ios_base::app);
    fout << "Hello files!" << endl;
    fout.close();
    system("Notepad File.txt");
#endif 
#ifdef read_from_file
    const int size = 256;
    char buffer[size]{};
    ifstream fin("File.txt");
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            //fin >> buffer;
            fin.getline(buffer, size);
            cout << buffer << endl;
        }
        fin.close();
    }
    else
    {
        std::cerr << "Error: File not found" << endl;
    }
#endif 
#ifdef copy_file
    const int size = 16;
    const int size1 = 18;
    char sz_ip_buffer[size]{};
    char sz_mac_buffer1[size1]{};
    char kab[20]{};
    char kab1[11] = " ready.txt";
    char kab2[9] = " RAW.txt";
    char ready_name[30]{};
    cout << "¬ведите номер аудитории: "; cin >> kab;
    strcat(ready_name, kab);
    std::ofstream fout(strcat(ready_name, kab1));
    std::ifstream fin(strcat(kab, kab2));
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> sz_ip_buffer >> sz_mac_buffer1;
            fout << sz_mac_buffer1 << " " << sz_ip_buffer << endl;
            cout << sz_mac_buffer1 << " " << sz_ip_buffer << endl;
        }
        fin.close();
    }
    else
    {
        std::cerr << "Error: File not found" << endl;
    }
    fout.close();
    char cmd[30] = { "notepad " };
    strcat(cmd, ready_name);
    system(cmd);
#endif 
    const int size = 18;
    char buffer[size]{};
    char buffer1[size]{};
    char ready_end[size] = " RAW.dhcpd";
    char exist_end[size] = " RAW.txt";
    char number[25]{};
    char ready_name[30]{};
    std::cout << "¬ведите номер аудитории: "; std::cin >> number;
    std::strcat(ready_name, number);
    std::cout << ready_name << endl;
    std::ofstream fout(std::strcat(ready_name,ready_end));
    std::ifstream fin(std::strcat(number,exist_end));
    int count = 0;
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> buffer>>buffer1;
            fout <<"host 201"<<"-"<< count++<<endl<< "{" << endl << "\thardware ethernet: " << buffer<<";" << endl << "\tfixed-address: " << buffer1 << ";" << endl << "}" << endl;
        }
    }
    else
    {
        std::cerr << "Error: File not found" << endl;
    }
    fout.close();
    char cmd[30] = "notepad ";
    std::strcat(cmd, ready_name);
    std::system(cmd);
}
