#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <crypt.h>

int main(void)
{
    char password[] = "AAAA";
    char toCrack[] = "AAzz";
    printf("%s\n", password);
    printf("%s\n", toCrack);

    char *toCrackCiph = crypt(toCrack, "da");
    printf("%s\n", toCrackCiph);

    char *passwordCiph = crypt(password, "aa");
    printf("%s\n", passwordCiph);
    return 0;
}
