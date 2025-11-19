#include <bits/stdc++.h>
#include <map>
#include <string>
#include <cstring>
using namespace std;
map <char , int> nums;
map <char , string> strings;
map <double , double> doubles;
bool characterExists(const string& str, char c) {
    return str.find(c) != string::npos;
}
void changetypee(char x , int i){
    if (i==1){
        if (strings.find(x) != strings.end()){
            int num=0;
            string A;
            int j=0;
            A = strings[x];
            while(j<A.length()){
                if (A[j]<='9'&&A[j]>='0') {
                    num = num * 10 + (A[j] - '0');
                    j++;
//                    cout<<num<<endl;
                }else{
                    cout<<num<<endl;
                    break;
                }
            }
            nums.insert(pair<char , int>(x , num));
            strings.erase(x);
            cout<<num<<endl;
        }
        else if (doubles.find(x)!= doubles.end()){
            int q = doubles[x];
            cout<<q<<endl;
            nums.insert(pair<char , int>(x , q));
            doubles.erase(x);
        }
        else if (nums.find(x) != nums.end()){
            cout<<nums[x]<<endl;
        }
    }
    else if(i==2){
        if (strings.find(x) != strings.end()) {
            double num = 0.0;
            string A;
            A = strings[x];
            while (i < A.length()) {
                if (A[i] <= '9' && A[i] >= '0') {
                    num = num * 10 + (A[i] - '0');
                    i++;
                } else if (A[i] == '.') {
                    i++;
                    int kasr = 10;
                    while(A[i]<='9' && A[i]>='0'){
                        num += (A[i]-'0')/kasr;
                        i++;
                        kasr *= 10;
                    }
                }
            }
            cout<<num<<endl;
            doubles.insert(pair<char , double>(x , num));
            strings.erase(x);
        }
        else if (doubles.find(x)!= doubles.end()){
            cout<<doubles[x]<<endl;
        }
        else if (nums.find(x) != nums.end()){
            double c = nums[x];
            cout<<c<<endl;
            doubles.insert(pair<char , double>(x , c));
            nums.erase(x);
        }
    }
    else if (i==3){
        if (strings.find(x) != strings.end()){
            cout<<strings[x]<<endl;
        }
        else if (doubles.find(x)!= doubles.end()){
            cout<<doubles[x]<<endl;
        }
        else if (nums.find(x) != nums.end()){
            cout<<nums[x]<<endl;
        }
    }

}
void printType(char x) {
    if (strings.find(x) != strings.end()){
        cout << "Str"<<endl;
    }else if (doubles.find(x) != doubles.end()){
        double t = doubles[x];
        int intt = t;
        if (intt == t)
            cout<<"Int"<<endl;
        else
            cout << "Double"<< endl;
    }else if (nums.find(x) != nums.end()) {
        cout << "Int" << endl;
    }
}
int olaviat(char op){
    if (op=='='||op=='!'||op=='<'||op=='>')
        return 1;
    if(op == '+'||op == '-')
        return 2;
    if(op == '*'||op == '/')
        return 3;
    return 0;
}
int conclusion(double a , double b , string c){
    if (c[1]!=' '){
        switch(c[0]){
            case '<' : return a<=b;
            case '>' : return a>=b;
            case '!' : return a!=b;
            case '=' : return a==b;
        }
    }else{
        switch(c[0]){
            case '<': return a<b;
            case '>' : return a>b;
        }
    }
}
double operate(double a, double b, char c){
    switch(c){
        case '+': return a + b;
        case '*': return a * b;
        case '/': return a / b;
        case '-': return a - b;
    }
}
int valueq(int a , int b , int k){
//    1 is for and
//    2 is for or
    if (k==1){
        if (a==0 || b==0)
            return 0;
        else
            return 1;
    }
    else{
        if(a==0 && b==0)
            return 0;
        else{
            return 1;
        }
    }
}
double evaluate(string A){
    int i;
    int isstr = 0;
    stack <int> arzesh;
    stack <double> values;
    stack <char> ops;
    stack <int> sense;
    stack <string> str;
    int minus = 0;
    for(i = 0; i < A.length(); i++) {
        if (A[i] == ' ')
            continue;
        else if (A[i]=='-' && isdigit(A[i+1]))
            minus = 1;
        else if (A[i] == '(') {
            ops.push(A[i]);
        }
        else if (isdigit(A[i])) {
            double num = 0;
            while (i < A.length()) {
                if (A[i] <= '9' && A[i] >= '0') {
                    num = (num * 10) + (A[i] - '0');
                    i++;
                } else if (A[i] == '.') {
                    long double kasr = 10;
                    i++;
                    while (A[i] <= '9' && A[i] >= '0' && i < A.length()) {
                        num += (A[i] - '0') / kasr;
                        i++;
                        kasr *= 10;
                    }
                } else {
                    break;
                }
            }
            if (!minus) values.push(num);
            else values.push(-1 * num);
            minus = 0;
            i--;
        }
        else if (A[i] == ')') {
            if (ops.top() == '*' || ops.top() == '+' || ops.top() == '-' || ops.top() == '/') {
                while (!ops.empty() && ops.top()!='(' &&(ops.top() == '*' || ops.top() == '+' || ops.top() == '-' || ops.top() == '/')){
                    double val2 = values.top();
                    values.pop();
                    double val1 = values.top();
                    values.pop();
                    char op = ops.top();
                    ops.pop();
                    values.push(operate(val1, val2, op));
                }
            }
            else if (ops.top() == '=' || ops.top() == '!' || ops.top() == '<' || ops.top() == '>') {
                if (str.empty()){
                    while (!ops.empty() && ops.top() != '(') {
                        double val2 = values.top();
                        values.pop();
                        double val1 = values.top();
                        values.pop();
                        string op;
                        op.push_back('\0');
                        op.push_back('\0');
                        op[0] = ops.top();
                        ops.pop();
                        op[1] = ops.top();
                        ops.pop();
                        int u = conclusion(val1, val2, op);
                        arzesh.push(u);
                    }
                }else{
                    while(!str.empty()){
                        string val1 = str.top();
                        str.pop();
                        string val2 = str.top();
                        str.pop();
                        string op;
                        op.push_back('\0');
                        op.push_back('\0');
                        op[0] = ops.top();
                        ops.pop();
                        op[1] = ops.top();
                        ops.pop();
                        if (op == "=="){
                            int t = strcmp(val1.c_str() , val2.c_str());
                            if (t==0){
                                arzesh.push(1);
                            }else{
                                arzesh.push(0);
                            }
                        }
                        else{
                            int t = strcmp(val1.c_str() , val2.c_str());
                            if (t==0){
                                arzesh.push(0);
                            }
                            else{
                                arzesh.push(1);
                            }
                        }
                    }
                }

            }
            else if (!sense.empty()){
                if (!arzesh.empty()){
                    int val2 = arzesh.top();
                    arzesh.pop();
                    if(arzesh.empty()){
                        arzesh.push(val2);
                        val2 = values.top();
                        values.pop();
                        if (values.empty()){
                            int val1 = arzesh.top();
                            arzesh.pop();
                            int p = sense.top();
                            sense.pop();
                            arzesh.push(valueq(val1 , val2 , p));
                        }
                        else{
                            int val1 = values.top();
                            values.pop();
                            int p = sense.top();
                            sense.pop();
                            arzesh.push(valueq(val1 , val2 , p));
                        }
                    }
                    else{
                        int val1 = arzesh.top();
                        arzesh.pop();

                        int p = sense.top();
                        sense.pop();
                        arzesh.push(valueq(val2 , val1 , p));
                    }
                }
                else{
                    int val2 = values.top();
                    values.pop();
                    int val1 = values.top();
                    values.pop();
                    int p = sense.top();
                    sense.pop();
                    arzesh.push(valueq(val1 , val2 , p));
                }
            }
            if (!ops.empty() && ops.top() == '(') {
                ops.pop();
            }
//            cout<<arzesh.top()<<endl;
        }
        else if (A.substr(i , 3) == "and" || A.substr(i , 2) == "or"){
            if (A[i] == 'a') {
                sense.push(1);
                i += 2;
            } else {
                sense.push(2);
                i++;
            }
        }
        else if (((A[i]<='z' && A[i]>='a')||(A[i]<='Z'&& A[i]>='A' ))){
            if(nums.find(A[i]) != nums.end()) {
                values.push(nums[A[i]]);
//                    cout << nums[A[i]]<<endl;
            }
            else if (doubles.find(A[i]) != doubles.end()) {
//                cout<<"This is a float!"<<endl;
                values.push(doubles[A[i]]);
//                cout << doubles[A[i]] << endl;
            }
            else if (strings.find(A[i]) != strings.end()){
                str.push(strings[A[i]]);
//                cout<<str.top()<<endl;
            }

        }
        else if (A[i] == '*' || A[i] == '/' || A[i] == '+' || A[i] == '-') {
            while (!ops.empty() && olaviat(ops.top()) >= olaviat(A[i])) {
                if ((ops.top() == '*') || (ops.top() == '+') || (ops.top() == '/')) {
                    double val2 = values.top();
                    values.pop();

                    double val1 = values.top();
                    values.pop();

                    char op = ops.top();
                    ops.pop();

                    values.push(operate(val1, val2, op));
                }
            }
            ops.push(A[i]);
        }
        else if (A[i] == '>' || A[i]=='<' || A[i]=='=' || A[i]=='!'){
            if(ops.empty() || ops.top()== '('){
                ops.push(A[i + 1]);
                ops.push(A[i]);
                i++;
            }
            else{
                if (ops.top() == '*' || ops.top() == '+' || ops.top() == '-' || ops.top() == '/') {
                    while (!ops.empty() && ops.top()!='('){
                        double val2 = values.top();
                        values.pop();
                        double val1 = values.top();
                        values.pop();
                        char op = ops.top();
                        ops.pop();
                        values.push(operate(val1, val2, op));
                        i--;
                    }

                    if (!ops.empty() && ops.top() == '(')
                        ops.pop();
                }

            }

        }
    }
    while(!ops.empty()){
        if (ops.top()=='(')
            ops.pop();
        else{
            if (values.empty()){
                if (!str.empty()){
                    string val1 = str.top();
                    str.pop();
                    string val2 = str.top();
                    str.pop();
                    string op;
                    op.push_back('\0');
                    op.push_back('\0');
                    op[0] = ops.top();
                    ops.pop();
                    op[1] = ops.top();
                    ops.pop();
                    if (op == "=="){
                        int t = strcmp(val1.c_str() , val2.c_str());
                        if (t==0){
                            arzesh.push(1);
                        }else{
                            arzesh.push(0);
                        }
                    }
                    else{
                        int t = strcmp(val1.c_str() , val2.c_str());
                        if (t==0){
                            arzesh.push(0);
                        }
                        else{
                            arzesh.push(1);
                        }
                    }
                }
            }
            else{
                double val2 = values.top();
                values.pop();
                double val1 =values.top();
                values.pop();
                if (ops.top()=='*'||ops.top()=='/'||ops.top()=='-'||ops.top()=='+'){
                    char op = ops.top();
                    ops.pop();
                    values.push(operate(val1, val2, op));
                }else{
                    string op;
                    op.push_back('\0');
                    op.push_back('\0');
                    op[0] = ops.top();
                    ops.pop();
                    op[1] = ops.top();
                    ops.pop();
                    int u = conclusion(val1, val2, op);
                    arzesh.push(u);
                }
            }
        }


    }
    while(!sense.empty()){
        if (!arzesh.empty()){
            int val2 = arzesh.top();
            arzesh.pop();
            if(arzesh.empty()){
                arzesh.push(val2);
                break;
            }
            else{
                int val1 = arzesh.top();
                arzesh.pop();

                int p = sense.top();
                sense.pop();
                arzesh.push(valueq(val2 , val1 , p));

            }
        }
        else if (!values.empty()){
            double val2 = values.top();
            values.pop();
            double val1 = values.top();
            values.pop();
            int p = sense.top();
            sense.pop();
            arzesh.push(valueq(val1 , val2 , p));
        }
//        else if (!str.empty()){
//            string val1 = str.top();
//            str.pop();
//            string val2 = str.top();
//            str.pop();
//            string op;
//            op.push_back('\0');
//            op.push_back('\0');
//            op[0] = ops.top();
//            ops.pop();
//            op[1] = ops.top();
//            ops.pop();
//            if (op == "=="){
//                int t = strcmp(val1.c_str() , val2.c_str());
//                if (t==0){
//                    cout<<"True"<<endl;
//                    return 0;
//                }else{
//                    cout<<"False"<<endl;
//                    return 0 ;
//                }
//            }
//            else{
//                int t = strcmp(val1.c_str() , val2.c_str());
//                if (t==0){
//                    cout<<"True"<<endl;
//                    return 0 ;
//                }
//                else{
//                    cout<<"False"<<endl;
//                    return 0 ;
//                }
//            }
//        }
    }
    if(!arzesh.empty()) {
        return arzesh.top();
    }
    else
        return values.top();
    return 0;
}
int main() {
    string A;
    int in = 1;
//    int w = 0;
    while (getline(cin , A) && (in==1)){
//        w++;
//        cout<<w<<endl;
        char x;
        int isint=0;
        int isfloat=0;
        int isstr=0;
        string C;
        if (A=="#")
            in = 0;
        for(int i=0 ; i<A.length();i++){
            long double num=0;

            if (A[i]==' ')
                continue;

            else if (((A[i]<='z' && A[i]>='a')||(A[i]<='Z'&& A[i]>='A')) && characterExists(A.substr(i , A.length()-i) , '=') ){
                x = A[i];
                while ((A[i]<='z' && A[i]>='a')||(A[i]<='Z'&& A[i]>='A')){
                    i++;
                }
                i--;
            }
            else if (A[i]== '='){
                if (A[i+2]=='\"') {
                    isstr=1;
                    int ptr = i + 3;
                    while(A[ptr] != '\"')
                        C.push_back(A[ptr++]);
                }
                else {
                    num=evaluate(A.substr(i+2 , A.length()-(i+2)));
//                    cout<<num<<endl;
                    int intt = num;
                    if (intt == num){
                        isint = 1;
                        isfloat = 0;
                    }else{
                        isint=0;
                        isfloat=1;
                    }
                }
            }
            if (isfloat){
                doubles.insert(pair<char , double>(x , num));
            }
            else if(isint){
                nums.insert(pair<char , int>(x , num));
            }
            else if(isstr){
                strings[x] = C;
            }
            if(A.substr(i , 4)=="Type"){
                printType(A[i+5]);
                break;
            }
            else if (A.substr(i , 3)=="Int"){
                changetypee(A[i + 4] , 1);
                break;
            }
            else if (A.substr(i , 6)=="Double"){
                changetypee(A[i + 7] , 2);
                break;
            }
            else if (A.substr(i , 3)=="Str"){
                changetypee(A[i + 4] , 3);
                break;
            }
            else if(A[i]=='['){
                int k= i-1;
                i++;
                int adad=0;
                while(A[i]!=']'){
                    adad = adad*10 + (A[i]-'0');
                    i++;
                }
                string F = strings[A[k]];
                cout<<F[adad]<<endl;
            }
            else if (A.substr(i , 4)=="Size"){
//                cout<<A[i+5]<<endl;
                if (strings.find(A[i+5]) != strings.end()){
                    cout<<strings[A[i+5]].length() << endl;
//                    cout<<strings[A[i+5]]<<endl;
                }else if (doubles.find(A[i+5]) != doubles.end()){
                    cout<<sizeof(doubles[A[i+5]])<<endl;
                }else if (nums.find(A[i+5]) != nums.end()) {
                    cout<<sizeof(nums[A[i+5]])<<endl;
                }
            }
            else if (A[i]=='@'){
                double t = evaluate(A.substr(i+1 , A.length()-(i+1)));
                int intt = t;
                if (intt == t){
                    cout<<t<<endl;
                }
                else{
                    cout << fixed << setprecision(6) << t << endl;
                    break;
                }

            }
            else if (A[i]=='$'){
//                cout << A.substr(i+1 , A.length()-(i+1))<<endl;
                if (evaluate(A.substr(i+1 , A.length()-(i+1)))==1) {
                    cout << "True" << endl;
                    break;
                }
                else {
                    cout << "False" << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
