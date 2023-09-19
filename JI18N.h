#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class JI18N
{
public:
    JI18N();
    JI18N(string LANG_DIRECTORY, string LANG);
    ~JI18N();

    string Search(string KEY);
    string Search(string KEY, string DEFAULT);
    string Search(string KEY, string LANG);
    string Search(string KEY, string DEFAULT, string LANG);
    
    void SetLang(string LANG);
    void SetLang(string LANG_DIRECTORY);
    
    string GetNowLang();

private:
    string _LANG_DIRECTORY;
    string _LANG;
};

JI18N::JI18N()
{
    _LANG_DIRECTORY = "LANG/";
    _LANG = "English";
}

JI18N::JI18N(string LANG_DIRECTORY, string LANG)
{
    _LANG_DIRECTORY = LANG_DIRECTORY;
    _LANG = LANG;
}

JI18N::~JI18N() {}

string JI18N::Search(string KEY)
{
    return Search(KEY, KEY);
}

string JI18N::Search(string KEY, string DEFAULT)
{
    return Search(KEY, DEFAULT, _LANG);
}

string JI18N::Search(string KEY, string LANG)
{
    return Search(KEY, KEY, LANG);
}

string JI18N::Search(string KEY, string DEFAULT, string LANG)
{
    ifstream in;
    string line;
    string result;

    in.open(_LANG_DIRECTORY + LANG + ".txt");
    if (!in.is_open())
    {
        return DEFAULT;
    }

    while (getline(in, line))
    {
        if (line.find(KEY) != string::npos)
        {
            result = line.substr(line.find("=") + 1);
            break;
        }
    }

    in.close();
    return result;
}

void JI18N::SetLang(string LANG)
{
    _LANG = LANG;
}

void JI18N::SetLang(string LANG_DIRECTORY)
{
    _LANG_DIRECTORY = LANG_DIRECTORY;
}
