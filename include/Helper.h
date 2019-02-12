#ifndef HELPER_H
#define HELPER_H

#include "Header.h"

namespace SHOPManagement
{

class Helper
{
public:
    static string m_message;
    static const char ADDRESS_SEPERATOR = '|';
    static vector<string> split(const string &t_str,
                                char t_delimeter);

    static vector<string> loadFileByLine(const string &file_path);
    static bool saveFileByLine(const string &file_path, const vector<string> &t_data);
    static int createMenu(const vector<string> &t_options);
    static bool findCaseInsensitive(const string &t_data, const string &t_search);
    static void showMessage();
    static void clearScreen();
};

}
#endif // HELPER_H
