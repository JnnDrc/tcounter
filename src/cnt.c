#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "input.h"

int main(int argc, char** argv){
    int cntrs_cnt = argc > 1 ? atoi(argv[1]) : 1;
    int slct = 0;
    uint64_t* cntrs = malloc(cntrs_cnt*sizeof(uint64_t)); 
    printf("\033[2J");
    enable_nbi();
    while(1){
        switch(get_key()){
            case '+':
            case 'a':
            case 'l':
                cntrs[slct] = cntrs[slct] == UINT64_MAX ? UINT64_MAX : cntrs[slct] + 1;
                break;
            case '-':
            case 's':
            case 'h':
                cntrs[slct] = cntrs[slct] == 0 ? 0 : cntrs[slct] - 1;
                break;
            case 'A':
            case 'L':
                cntrs[slct] = cntrs[slct] == UINT64_MAX ? UINT64_MAX : cntrs[slct] + 10;
                break;
            case 'S':
            case 'H':
                cntrs[slct] = cntrs[slct] == 0 ? 0 : cntrs[slct] - 10;
                break;
            case 'c':
                cntrs[slct] = 0;
                break;
            case 'n':
            case 'j':
                slct = slct == (cntrs_cnt - 1) ? cntrs_cnt-1 : slct + 1;
                break;
            case 'p':
            case 'k':
                slct = slct == 0 ? 0 : slct - 1;
                break;
            case 'q': 
            case 'Q':
                goto exit;
                break;
            default:
                break;
        }   
        printf("\033[1;1H");
        for(int i = 0; i < cntrs_cnt; i++){
            printf("%c counter: %lu                                                            \n",
                    slct == i ? '>':'-',cntrs[i]);
        }
        sleep(200);
    }
exit:
    printf("\033[2J");
    disable_nbi();
    free(cntrs);
    return 0;
}

