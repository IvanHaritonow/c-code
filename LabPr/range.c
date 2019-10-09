#include <stdio.h>
#include <locale.h>
#include <conio.h>

int main(){
    double s = 0;
    setlocale(LC_ALL, "RUS");
    
    for(int i = 2; i < 20; i++) {
        s += (double) i / (i + 1);
    }
    
    printf("Result is: %f", s);
    
    _getche;
}
