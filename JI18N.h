#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#define Chinese "zh"
#define English "en"
#define Japanese "ja"
#define Korean "ko"
#define Russian "ru"
#define Spanish "es"
#define French "fr"

class JI18N
{
public:
    JI18N();
    JI18N(string LANG);
    JI18N(string LANG_DIRECTORY, string LANG);
    ~JI18N();

    string Search(string KEY);
    string Search(string KEY, string LANG);
    string Search(string KEY, string LANG, string DEFAULT);
    string use(string KEY);
    string use(string KEY,string DEFAULT);

    void SetLang_Lang(string LANG);
    void SetLang_Dir(string LANG_DIRECTORY);

private:
    string _LANG_DIRECTORY;
    string _LANG;
};

JI18N::JI18N()
{
    _LANG_DIRECTORY = "LANG/";
    _LANG = "English";
}

JI18N::JI18N(string LANG)
{
    _LANG_DIRECTORY = "LANG/";
    _LANG = LANG;
}

JI18N::JI18N(string LANG_DIRECTORY, string LANG)
{
    _LANG_DIRECTORY = LANG_DIRECTORY;
    _LANG = LANG;
}

JI18N::~JI18N() {}

string JI18N::Search(string KEY)
{
    return this->Search(KEY, this->_LANG);
}

string JI18N::Search(string KEY, string LANG)
{
    return this->Search(KEY, LANG, KEY);
}

string JI18N::Search(string KEY, string LANG, string DEFAULT)
{
    ifstream in;
    string line;
    string result;

    in.open(this->_LANG_DIRECTORY + LANG + ".txt");
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

void JI18N::SetLang_Lang(string LANG)
{
    _LANG = LANG;
}

void JI18N::SetLang_Dir(string LANG_DIRECTORY)
{
    _LANG_DIRECTORY = LANG_DIRECTORY;
}

string JI18N::use(string KEY)
{
    return this->use(KEY, KEY);
}

string JI18N::use(string KEY, string DEFAULT)
{
    string language;
    string key;
    int ii;
    for (int i = 0; i < KEY.size(); i++)
    {
        if (KEY[i] == '.')
        {
            language = KEY.substr(0,i);
            key = KEY.substr(i + 1, KEY.size() - 1);
        }
    }

    return this->Search(key,language,DEFAULT);
}