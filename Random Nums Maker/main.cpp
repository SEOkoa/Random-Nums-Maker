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
    int dup_counter = 0;
    
    cout << "1 ~ 99 사이의 '중복되지 않는' 난수를 생성합니다." <<endl;
    cout << "몇 개의 난수를 생성하시겠습니까? : ";
    scanf (" %d", &knd);
    
    for (int i = 0; i < knd; i++) {
        notOverlap:
        array[i] = rand() % 100;
        
        if( array[i] == 0) { //랜덤으로 0이 입력되어 프로그램이 종료되는 것을 방지. 얘는 중복에 아니니까 포함 안됨!
            
//            cout << "0이 입력되어 i 재시도" <<endl; // 정렬 프로그램은 0을 입력 종료값으로 받기 때문에 0이 중간에 나와서는 안됨.
            goto notOverlap;
        }
        
        for (int j = 0; j < i; j++) { // 이전에 호출된 숫자들과 중복되지 않는지 검사
            
            if ( array[i] == array[j] ) {
//                cout << "비교값: " << array[i] << " 검사중인 값(위치:  "  << i << " )" << array[j] <<" 중복 숫자 발견 " <<endl;
                dup_counter++;
                goto notOverlap;
            }
        }
    }
    
    cout << knd << " 개의 난수를 생성하는 중 " << dup_counter << "번의 중복이 발생하였습니다. " << endl;
    
    
    for (int i = 0; i < knd; i++) { // 뽑아낸 난수들을 출력함
        
        if (i%10 == 0)   //10개마다 끊어서 보여줌
            cout << endl;
        
        if (array[i] < 10) //한자릿수인 경우 일의자리에 위치하도록 간격을 맞춰줌
            cout << " ";
        
        cout << array[i] << " ";
    }
    
    cout << "0" <<endl;        // 입력종료값 0 추가

    return 0;
}
