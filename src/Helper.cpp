#include "Helper.h"

namespace SHOPManagement
{

string Helper::m_message = "";

vector<string> Helper::split(const string &t_str,
                             char t_delimeter)
{
    stringstream ss(t_str);
    string item;
    vector<string> splitted_strings;

    while (getline(ss, item, t_delimeter))
    {
        splitted_strings.push_back(item);
    }

    return splitted_strings;
}

vector<string> Helper::loadFileByLine(const string &file_path)
{
    ifstream file_data(file_path);
    vector<string> lines;
    string line;

    if(!file_data.is_open())
    {
        cerr << file_path << " can't open!";
        exit(EXIT_FAILURE);
    }

    while(getline(file_data, line))
    {
        lines.push_back(line);
    }

    file_data.close();
    return lines;
}

bool Helper::saveFileByLine(const string &file_path, const vector<string> &t_data)
{
    ofstream file_data(file_path);

    if(!file_data.is_open())
    {
        cerr << file_path << " can't open!";
        exit(EXIT_FAILURE);
    }

    for(auto line : t_data)
    {
        file_data << line;
        file_data << endl;
    }

    file_data.close();
    return file_data.good();
}

int Helper::createMenu(const vector<string> &t_options)
{
    int choice = -1,
        len = t_options.size();

    do
    {
        cout << "### Menu ###" << endl;
        for(int i = 0; i < len; i++)
        {
            cout << (i + 1) << ". " << t_options[i] << endl;
        }

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<int>::max(), '\n');
        cin.sync();

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            continue;
        }
    }
    while(choice < 1 || choice > len);

    return choice;
}

bool Helper::findCaseInsensitive(const string &t_data, const string &t_search)
{
    string data_lower = t_data,
           search_term_lower = t_search;

    transform(data_lower.begin(), data_lower.end(), data_lower.begin(), ::tolower);
    transform(search_term_lower.begin(), search_term_lower.end(), search_term_lower.begin(), ::tolower);

    return data_lower.compare(search_term_lower);
}

void Helper::showMessage()
{
    int message_length =  Helper::m_message.size();
    char prev;

    if(message_length == 0)
        return;

    prev = cout.fill ('/');
    cout.width (message_length);
    cout << "" << endl;
    cout.fill(prev);

    cout << Helper::m_message << endl;

    prev = cout.fill ('\\');
    cout.width (message_length);
    cout << "" << endl;
    cout.fill(prev);

    Helper::m_message = "";
}

void Helper::clearScreen()
{
    system("cls||clear");
}

}
