#ifndef HELPER_H
#define HELPER_H

#include "Header.h"

namespace SHOPManagement
{

    class Helper
    {
    public:
        static std::string m_message;
        static const char ADDRESS_SEPERATOR = '|';
        static std::vector<std::string> split(const std::string &t_str, char t_delimeter);

        static std::vector<std::string> loadFileByLine(const std::string &file_path);
        static bool saveFileByLine(const std::string &file_path, const std::vector<std::string> &t_data);
        static int createMenu(const std::vector<std::string> &t_options);
        static bool findCaseInsensitive(const std::string &t_data, const std::string &t_search);
        static void showMessage();
        static void clearScreen();
    };

}
#endif // HELPER_H
