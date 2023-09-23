# JI18N: I18N for Jiko

# First step: Download

```bash
git clone https://github.com/JikoMo/JI18N.git
cp ./JI18N/JI18N.h <Your Project Directory>
```

Then add `#include "JI18N.h"` to your code

# Second step: Use

## 1.Add language file

**Please add "language.txt" in the "LANG/" directory by _default_**

"language.txt" file format:
```
Key=Content
```

## 2.Use language file

### 1.Create a new JI18N class

```C++
JI18N I18N;
JI18N I18N(string LANG_DIRECTORY, string LANG);
```

### 2.Search language file

```C++
string Search(string KEY);
string Search(string KEY, string LANG);
string Search(string KEY, string LANG, string DEFAULT);
```

**Such as**
```C++
I18N.Search("Hello", Chinese);
```

### Reset

```C++
void SetLang_Lang(string LANG);
void SetLang_Dir(string LANG_DIRECTORY);
```

**Such as**

```C++
I18N.SetLang_Lang(Japanese);
I18N.SetLang_Dir("LANG/");
```

### Use language file

```C++
string use(string KEY);
string use(string KEY,string DEFAULT);
```

**Such as**

```C++
I18N.use("zh.Hello");
I18N.use("en.Hello");
```
