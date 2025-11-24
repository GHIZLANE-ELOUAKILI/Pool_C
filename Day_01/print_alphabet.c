#include <unistd.h>

void print_alphabet(void)
{
    char c;
    
    c = 'a';
    while (c <= 'z')
    {
        write(1, &c, 1);
        c++;
    }
}

int main(void)
{
    print_alphabet();
    return (0);
}