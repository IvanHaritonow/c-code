#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    typedef const char* string;
    
    int n = 1;
    
    string res1 = "", res2 = "", res3 = "", res4 = "",
    chiliad = "", check1 = "", check2 = "";
    
    string units[] = {"", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
    string decades[] = {"", "", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};
    string hundred[] = {"", "сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот"};
    string chiliads[] = {"", "одна", "две", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
    string exceptions[] = {"десять", "одиннадцать", "двеннадцать", "триннадцать", "четырданцать", "пятнадцать", "шестнадцать", "семнадцать",
    "восемнадцать", "девятнадцать"};
    
    setlocale(LC_ALL, "RUS"); 
    
    if (n == 0) {
        printf("ноль");
    } else
    
    if (n < 10) {
        res1 = units[n];
        printf("%s", res1);
    } else
    
    if (n < 100) {
        if (n < 20 && n >= 10) {
            res1 = exceptions[n % 10];
            printf("%s", res1);
        } else {
            res1 = units[n % 10];
            res2 = decades[n / 10];
            printf("%s %s", res2, res1);
        }
    } else 
    
    if (n < 1000) {
        res3 = hundred[n / 100];
        n = n % 100;
        
        if (n / 10 != 0) check1 = " ";
        
        if (n < 20 && n >= 10) {
            res1 = exceptions[n % 10];
            printf("%s %s", res3, res1);
        } else {
            res1 = units[n % 10];
            res2 = decades[n / 10];
            printf("%s %s%s%s", res3, res2, check1, res1);
        }
    } else
    
    if (n < 10000) {
        if (n / 1000 == 1) chiliad = "тысяча";
        if (n / 1000 > 1 && n / 1000 < 5) chiliad = "тысячи";
        if (n / 1000 > 4 && n / 1000 < 10) chiliad = "тысяч";
        
        res4 = chiliads[n / 1000];
        n = n % 1000;
        
        if (n / 100 != 0) check1 = " ";
        int d = n / 10;
        d %= 10;
        if (d != 0) check2 = " ";
        
        res3 = hundred[n / 100];
        n = n % 100;
        if (n < 20 && n >= 10) {
            res1 = exceptions[n % 10];
            printf("%s %s %s", res4, chiliad, res1);
        } else {
            res1 = units[n % 10];
            res2 = decades[n / 10]; 
            printf("%s %s %s%s%s%s%s", res4, chiliad, res3, check1, res2, check2, res1);
        }
    } else printf("Значение вне зоны возможностей прогрмаммы");
    _getch();
}
