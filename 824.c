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

//LeetCode答案 其实就是创建了新的字符数组然后将原先的字符数组通过规则组装成新的数组
// 然后将新的数组添加 “ ”等之类的 完成数组的组装 完成后就返回就好了
char a[10000];
char* toGoatLatin(char* S) {
    memset(a,0,sizeof(a));
    char *s=S,p;
    int i=0,count=0,flag=1,flag2=0,t=1;
    while(s[i]!=0) // 大循环循环全部的字符
    {
//        一个单词从S到a的转化
        t++;
        while(s[i]!=' '&&s[i]!=0) // 找出一个词
        {
            if(flag) // 第一个字母
            {
                if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                {
                    a[count++]=s[i]; // 元音情况
                }
                else // 辅音情况
                {
                    flag2=1;
                    p=s[i];
                }
                flag=0;
            }else
            {
                a[count++]=s[i];
            }
            i++;
        }
        if(flag2) a[count++]=p; // 辅音将首字母放在后面
        a[count++]='m'; // 添加m
        for(int i=0;i<t;i++)   a[count++]='a'; // 添加对应个数的a
        if(s[i]==0) break;
        a[count++]=' '; // 补充a的空格
        i++;
        flag2=0;
        flag=1;
    }
    return a;
}
