#include <iostream> 
#include <limits>
using namespace std;


struct Calculation {
    int num1;
    int num2;
    char operatorSymbol;
    int result;
};

int sum(int n1, int n2);
int dif(int n1, int n2);
int mult(int n1, int n2);
int quo(int n1, int n2);

int sum(int n1, int n2, int& ans) {
    ans = n1 + n2;
    return ans;
}

int dif(int n1, int n2, int& ans) {
    ans = n1 - n2;
    return ans;
}

int mult(int n1, int n2, int& ans) {
    ans = n1 * n2;
    return ans;
}

int quo(int n1, int n2, int& ans) {
    if (n2 == 0) {
        cout << "UNDEFINED!";
        return 0;
    }
    ans = n1 / n2;
    return ans;
}

int main() {

    int n1, n2; 
    char opt, back;
    const int limit = 100; 
    Calculation history[limit]; 
    int history_size = 0; 

    do {
        
        cout << "               CALCULATOR              " << endl;

        cout << endl;
        cout << "You can calculate a number by entering it: \n\n";
        cin >> n1 >> opt >> n2;

        while (cin.fail()) {
            cout << endl << "Invalid input! (ex. 2+2): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> n1 >> opt >> n2;
        }
        cout << endl;

        int ans = 0;
        switch (opt) {
            case '+':
                cout << "Answer: " << sum(n1, n2, ans);
                break;
            case '-':
                cout << "Answer: " << dif(n1, n2, ans);
                break;
            case '*':
                cout << "Answer: " << mult(n1, n2, ans);
                break;
            case '/':
                cout << "Answer: " << quo(n1, n2, ans);
                break;
            default:
                cout << "Answer: ";
        }
        
        Calculation calc;
        calc.num1 = n1;
        calc.num2 = n2;
        calc.operatorSymbol = opt;
        calc.result = ans;

        history[history_size] = calc;
        history_size++;

        if (history_size > 0) { 
            cout << endl << endl << "               HISTORY             " << endl;
          
            for (int i = 0; i < history_size; i++) {
                cout << endl <<" [ " << history[i].num1 << history[i].operatorSymbol << history[i].num2 << "=" << history[i].result <<" ]"<< endl;
               
                cout << endl << "Addresses: " << endl;

                cout << history[i].num1 << "| Address = " << &history[i].num1 << endl;
                cout << history[i].num2 << "| Address = " << &history[i].num2 << endl;
                cout << history[i].result << "| Address = " << &history[i].result << endl;
            }
           
            
            cout << endl << endl << "Return? [Y/N]: ";
            cin >> back;
            cout << endl << endl;
        }
    } while (back == 'y' || back == 'Y');

    return 0;
}
