int vowels(char ch)
{
    return (ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u'||ch == 'A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U');
}
void strcat_ss(char* target,char* first,char* end)     //逐个单词strcpy到动态内存里;
{
    //char* tar = target;
    while(*target)
        target++;
    while (first < end)
    {
        *target = *first;
        first++;
        target++;
    }
    *target = '\0';
}
char* strcat_s(char *str1, char *str2)
{
    if (str1==NULL)
        return str2;
    else if (str2==NULL)
        return str1;
    else if(str1==NULL && str2==NULL)
        return  NULL;

    strcat_ss(str1,str2,str2+strlen(str2));
    return str1;
}
void exchange(char* pt1,char* pt2)     //若不为元音，调到后面;
{
    char temp = *pt1;
    while (pt1 < pt2)
    {
        *pt1 = *(pt1+1);
        pt1++;
    }
    *pt2 = temp;
}
char* toGoatLatin(char* S)
{
    char* fun = (char *)malloc(2000);
    memset(fun,0,2000*sizeof(char));
    //char* fun = (char*)calloc(2000,sizeof(char));
    char* afun = fun;
    char* pt = S;
    char* tr = S;
    char* addon = "ma";
    int n = 0;
    while (*tr)
    {
        if (*tr == ' ')
        {
            tr++;
            pt = tr;
        }
        while (*tr && *tr != ' ')
            tr++;

        n++;            //n 第几个单词;

        if (!vowels(*pt))
            exchange(pt, tr-1);
        strcat_ss(fun, pt, tr);
        strcat_s(afun,addon);

        while(*afun != '\0')
            afun++;
        for(int i = 1;i <= n;i++,afun++)
            *afun = 'a';
        if (*tr != '\0')
            *afun = ' ';
    }
    return fun;
}

