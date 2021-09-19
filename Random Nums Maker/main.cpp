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
                cout << "비교중인 값 " << array[i] << " 배열 속 값(위치:  "  << i << " )" << array[j] <<" 중복 숫자 발견 " <<endl;
                i--;
                j--;
            }
               
        }
    }
    
    for (int i = 0; i < knd; i++) {
        cout << array[i] << " ";
    }
    
    cout << "0";
    cout << endl;



    return 0;
}
