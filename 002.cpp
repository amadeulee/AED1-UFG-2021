#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    int i;
    for(i=0; i<n; i++) {
        string str;
        cin >> str;

        int j, res = 1, chaves = 0, colchetes = 0, parenteses = 0;

        for(j=0; j<str.length(); j++) {
            if((str[j] == ')' && parenteses < 1) || (str[j] == ']' && colchetes < 1) || (str[j] == '}' && chaves < 1)) {
                res = 0;
                break;
            }
            else if(str[j] == '(') {
                parenteses++;
            }else if(str[j] == '['){ 
                colchetes++;
            }else if(str[j] == '{'){ 
                chaves++;
            }else if(str[j] == ')' && parenteses > 0){
                 parenteses--;
            }else if(str[j] == ']' && colchetes > 0){
                 colchetes--;
            }else if(str[j] == '}' && chaves > 0){
                 chaves--;
            }
        }

        if(res == 1 && parenteses == 0 && colchetes == 0 && chaves == 0) {
            printf("bem-formada\n");
        }
        else {
            printf("mal-formada\n");
        }
    }

    return 0;
}