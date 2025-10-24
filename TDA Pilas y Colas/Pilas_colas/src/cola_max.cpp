#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "maxqueue.h"

using namespace std;

// ./cmake-build-debug/cola_max 1 2 . 3 4 . . .

int main(int argc, char *argv[]){

    // Run the current exercise
    maxqueue queue;

    for(int i = 1; i < argc; i++){
        if (argv[i][0] == '.'){
            cout << queue.front() << endl;
            queue.pop();
        } else {
            queue.push(atoi(argv[i]));
        }
    }
    return 0;
}
