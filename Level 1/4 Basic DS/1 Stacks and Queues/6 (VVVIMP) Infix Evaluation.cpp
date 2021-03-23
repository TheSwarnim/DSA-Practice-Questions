#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define calcTime cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
#define Vi vector<int>

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int precedence(char optor){
    if(optor == '+'){
        return 1;
    }else if(optor == '-'){
        return 1;
    }else if(optor == '*'){
        return 2;
    }else{
        return 2;
    }
}

int operation(int v1, int v2, char optor){
    if(optor == '+'){
        return v1+v2;
    }else if(optor == '-'){
        return v1-v2;
    }else if(optor == '*'){
        return v1*v2;
    }else{
        return v1/v2;
    }
}

void InfixEvaluation(string str){
    int n = str.size();
    stack<int> opnds;
    stack<char> optors;

    for (int i = 0; i < n; i++)
    {
        char ch=str.at(i);

        if(ch=='('){
            optors.push('(');
        }else if(isdigit(ch)){
            opnds.push(ch - '0');
        }else if(ch==')'){
            while(optors.top() != '('){
                char optor = optors.top();
                optors.pop();

                int v2=opnds.top();
                opnds.pop();
                int v1 =opnds.top();
                opnds.pop();

                char opv = operation(v1, v2, optor);
                opnds.push(opv);
            }

            optors.pop(); //pop '('
        }else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            // solve higher priority operators to solve first
            while(!optors.empty() && optors.top() != '(' && 
            precedence(ch)<=precedence(optors.top())){
                char optor = optors.top();
                optors.pop();

                int v2=opnds.top();
                opnds.pop();
                int v1 =opnds.top();
                opnds.pop();

                char opv = operation(v1, v2, optor);
                opnds.push(opv);
            }

            optors.push(ch);
        }
    }
    
    while(optors.size() != 0){
        char optor = optors.top();
        optors.pop();

        int v2=opnds.top();
        opnds.pop();
        int v1 =opnds.top();
        opnds.pop();

        char opv = operation(v1, v2, optor);
        opnds.push(opv);
    }

    cout<<opnds.top()<<endl;
}

void solve(){
    optimize();

    string str;
    getline(cin, str);
    
    InfixEvaluation(str);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}