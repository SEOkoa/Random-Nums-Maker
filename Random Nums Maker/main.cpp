//
//  main.cpp
//  Random Nums Maker
//
//  Created by SEO.koa on 2021/09/19.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;



int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    int knd = 0;
    int array[100] = {0};
    
    cout << "1 ~ 99 사이의 '중복되지 않는' 난수를 생성합니다." <<endl;
    cout << "몇 개의 난수를 생성하시겠습니까? : ";
    scanf (" %d", &knd);
    
    for (int i = 0; i < knd; i++) {
        array[i] = rand() % 100;
        
        if( array[i] == 0) {
            i--;
            cout << "0이 입력되어 i 재시도" <<endl;
            continue;
        }
        
        for (int j = 0; j < i - 1; j++) {
            
            if ( array[i] == array[j] ) {
                cout << "비교값: " << array[i] << " 검사중인 값(위치:  "  << i << " )" << array[j] <<" 중복 숫자 발견 " <<endl;
                i--;
            }
        }
    }
    
    for (int i = 0; i < knd; i++) {
        cout << array[i] << " ";
    }
    
    cout << "0";

    
    for ( int i = 0; i < knd; i ++) {
        
        if ( i + 1 > 100 )
            break;
        
        if (array[i] == array[i + 1]) {
            printf ("\n중복 숫자가 있습니다. %d 번째 %d와 %d번째 %d.\n", i, array[i], i + 1, array[ i + 1 ]);
        }
    }
    
        cout << endl;



    return 0;
}
