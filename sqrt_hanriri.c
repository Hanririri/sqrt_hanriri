#include <stdio.h>
#include <stdint.h>


int32_t sqrt_hanriri(int64_t input) // only 62bit positive numble valid
{
    if(input >> 63) // The input number is negative
        return 0;
    
    int64_t source = input;
    uint8_t flag = 31;
    int32_t root = 0;
    int64_t temp = 0;
    int64_t diff = 0;

    while(flag > 0)
    {
        // temp = (temp << 2) + ((source>>((flag-1)*2))& 0b11);
        temp = (temp << 2) + ((source>>((--flag)<<1)) & 0b11);
        // diff = temp - ((root << 2) + 1);
        diff = temp - (root << 2) - 1;
        /*
        if(diff >= 0)
        {
            root = (root<<1) + 1;
            temp = diff;
        }
        else
        {
            root <<= 1;
        }
        flag --;
        */
        root <<= 1;
        if(diff >= 0)
        {
            root ++;
            temp = diff;
        }
    }
    return root;
}

int main()
{
    int64_t i = 0x20000;
    int32_t o = sqrt_hanriri(i);
    printf("sqrt of 0x%lx is 0x%x\n", i, o);

    return 0;
}