#include <windows.h>
#include <stdio.h>
int main()
{
    ///PlaySound("C:/Do.wav", NULL, SND_SYNC);
    PlaySound("mykbeat.wav", NULL, SND_ASYNC);
    printf("�п�J�@�Ӿ��: ");
    int n;
    scanf("%d", &n);
}
