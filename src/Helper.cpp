#include "Helper.h"

namespace SHOPManagement
{

    std::string Helper::m_message = "";

    std::vector<std::string> Helper::split(const std::string &t_str, char t_delimeter)
    {
        std::stringstream ss(t_str);
        std::string item;
        std::vector<std::string> splitted_strings;

        while (getline(ss, item, t_delimeter))
        {
            splitted_strings.push_back(item);
        }

        return splitted_strings;
    }

    std::vector<std::string> Helper::loadFileByLine(const std::string &file_path)
    {
        std::ifstream file_data(file_path);
        std::vector<std::string> lines;
        std::string line;

        if (!file_data.is_open())
        {
            std::cerr << file_path << " can't open!";
            exit(EXIT_FAILURE);
        }

        while (getline(file_data, line))
        {
            lines.push_back(line);
        }

        file_data.close();
        return lines;
    }

    bool Helper::saveFileByLine(const std::string &file_path, const std::vector<std::string> &t_data)
    {
        std::ofstream file_data(file_path);

        if (!file_data.is_open())
        {
            std::cerr << file_path << " can't open!";
            exit(EXIT_FAILURE);
        }

        for (auto line : t_data)
        {
            file_data << line;
            file_data << std::endl;
        }

        file_data.close();
        return file_data.good();
    }

    int Helper::createMenu(const std::vector<std::string> &t_options)
    {
        int choice = -1,
            len = t_options.size();

        do
        {
            std::cout << "### Menu ###" << std::endl;
            for (int i = 0; i < len; i++)
            {
                std::cout << (i + 1) << ". " << t_options[i] << std::endl;
            }

            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            std::cin.sync();

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                continue;
            }
        } while (choice < 1 || choice > len);

        return choice;
    }

    bool Helper::findCaseInsensitive(const std::string &t_data, const std::string &t_search)
    {
        std::string data_lower = t_data,
                    search_term_lower = t_search;

        transform(data_lower.begin(), data_lower.end(), data_lower.begin(), ::tolower);
        transform(search_term_lower.begin(), search_term_lower.end(), search_term_lower.begin(), ::tolower);

        return data_lower.compare(search_term_lower);
    }

    void Helper::showMessage()
    {
        int message_length = Helper::m_message.size();
        char prev;

        if (message_length == 0)
            return;

        prev = std::cout.fill('/');
        std::cout.width(message_length);
        std::cout << "" << std::endl;
        std::cout.fill(prev);

        std::cout << Helper::m_message << std::endl;

        prev = std::cout.fill('\\');
        std::cout.width(message_length);
        std::cout << "" << std::endl;
        std::cout.fill(prev);

        Helper::m_message = "";
    }

    void Helper::clearScreen()
    {
        system("cls||clear");
    }

}
