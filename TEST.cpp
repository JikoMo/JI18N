#include <iostream>
#include "JI18N.h"
using namespace std;

int main()
{
    JI18N I18N;
    cout << "TEST :" << endl;
    cout << "English's Hello:" << I18N.Search("Hello","","English") << endl;
    cout << "Chinese's Hello:" << I18N.Search("Hello","","Chinese") << endl;
    cout << "Japanese's Hello:" << I18N.Search("Hello","","Japanese") << endl;
    return 0;
}