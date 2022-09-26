#include <iostream>
#include "../Headers/ArrSeq.hpp"
#include "../Headers/BubbleSort.hpp"
#include "../Headers/ShellSort.hpp"
#include "../Headers/QuickSort.hpp"

using namespace std;

// int cmp (int a, int b){
//     if (a > b) return 1;
//     if (a == b) return 0;
//     else return -1;
// }

int cmp (int a, int b){
    return a - b;
}

// int cmp (float a, float b){
//     return a - b;
// }



int main(int argc, char* argv[]){
    srand(time(NULL));
   
    //Print array:
    /* 
    cout << argc << endl;
    
    for (int i = 0; i < argc; i++){
	    cout << argv[i] << endl;
    }
    */

    int arr[] = {1, 9, 8, 3, 4, 1, 40, 4};
    
    Sequence<int>* ptr = new ArraySequence<int>(arr, 8);
    // Sequence<int>* ptr = new ArraySequence<int>(3);
    //ArraySequence<int>* ptr1 = (ArraySequence<int>*)ptr;
    ISort<int>* sorter = new BubbleSort<int>();
    // ISort<int>* sorter = new ShellSort<int>();
    // ISort<int>* sorter = new QuickSort<int>();
    //ArraySequence<int>* ptr = new ArraySequence<int>(0);
    //ptr->Append(1331);
    Sequence<int>* ptr1 = nullptr;
    int flag = 0;
    int res = 0;
    while (!flag){
        cout << "Choose: ";
        cin >> res;
        switch (res){
            case 1:{
                int test1 = ptr->GetFirst();
                int test2 = ptr->GetLength();
                cout <<"First: "<<test1 << endl  << "Second: "  << test2 << endl;
                ptr->print();
                cout << "After Sort: " << endl;
                Sequence<int>* output = sorter->Sort(ptr, &cmp);
                output->print();
                cout << "Operator" << endl;

                break;
            }   
            case 2:{
                /*
                ptr->print();
                ptr = ptr->GetSubsequence(0,ptr->GetLength());
                ptr->print();
                break;
                */
            }
            
            case 3:{
                int qty = 0;
                cin >> qty;
                int* randarr = new int[qty];
                for (int i=0; i<qty; i++){
                    randarr[i] = rand()%1000000;
                }
                Sequence<int>* ptr1 = new ArraySequence<int>(randarr, qty);
                ptr1->print();
                Sequence<int>* out = sorter->Sort(ptr1, cmp);
                out->print();
                
                
                delete[] randarr;
                break;
            }

            case 0: {
                flag = 1;
                break;
            }

            default:{
                break;
            }
        }
    }
    delete ptr;
    delete ptr1;
    delete sorter; 
    return 0;
}
