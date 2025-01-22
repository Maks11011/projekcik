#include<stdio.h>
#include<stdbool.h>
#define and &&
#define or ||

const int n_max = 2 * 1e5;

void solve(){
    FILE * input = fopen("03.in", "r");

    int n = 6;
    char s[100000];
    int ans = 0;
    bool eneble = true;
    int n_max = 100000;


    while(fgets(s, 100000, input)){
        int nr = 0;
        int wsk = 0;
        int a1 = 0, a2 = 0;
        for(int j = 0; j < n_max; j++){
            if(s[j] == 0){
                break;
            }
            if(s[j] == '('){
                /*// odkomentowaæ dla part2
                if(j >= 5){
                    if(s[j-5] == 'd' and s[j-4] == 'o' and s[j-3] == 'n' and s[j-2] == '\'' and s[j-1] == 't' and s[j+1] == ')'){
                        eneble = false;
                    }
                }
                if(j >= 2){
                    if(s[j-2] == 'd' and s[j-1] == 'o' and s[j+1] == ')'){
                        eneble = true;
                    }
                }
                *///koniec part2
                if(j >= 3){
                    if(s[j-3] == 'm' and s[j-2] == 'u' and s[j-1] == 'l' and eneble){
                        wsk = 0;
                        bool ok = false;
                        for(int k = j + 1; k < n_max; k++){
                            if(s[k] == 0){
                                break;
                            }
                            bool ok = false;
                            if(wsk == 1){
                                if(s[k] >= '0' and s[k] <= '9'){
                                    nr = nr * 10 + s[k] - '0';
                                    ok = true;
                                }
                                if(s[k] == ')'){
                                    wsk = 2;
                                    a2 = nr;
                                    nr = 0;
                                    ans += (a1*a2);
                                    ok = true;
                                }
                            }

                            if(wsk == 0){
                                if(s[k] >= '0' and s[k] <= '9'){
                                    nr = nr * 10 + s[k] - '0';
                                    ok = true;
                                }
                                if(s[k] == ','){
                                    wsk += 1;
                                    a1 = nr;
                                    nr = 0;
                                    ok = true;
                                }
                            }
                            if(!ok){
                                nr = 0;
                                wsk = 0;
                                a1 = 0;
                                a2 = 0;
                                break;
                            }

                        }

                    }
                }
            }
        }
    }


    printf("%d", ans);

}

int main(){


    int t = 1;
    solve();
    return 0;
}
