#include <bits/stdc++.h>
#include <math.h>
#include<unordered_map>

#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define enl "\n"
#define INF std::numeric_limits<ll>::max()
#define F first
#define S second
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ldb;
typedef vector<long long> vll;
typedef pair<long long,long long> pll;
 
ll greatestSubarraySum(ll array[], ll n);
ll powerrr(ll a, ll b);
void swapp(ll *a, ll*b);
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
ll min(ll a, ll b);
ll max(ll a, ll b);
ll search(ll arr[], ll n, ll k);
string findSum(string s1, string s2);

 
string findSum(string s1, string s2) 
{ 
    // Before proceeding further, make sure length 
    // of s2 is larger. 
    if (s1.length() > s2.length())
    {
        string s = s1;
        s1=s2;
        s2=s;
    }
  
    // Take an empty string for storing result 
    string s = ""; 
  
    // Calculate length of both string 
    int n1 = s1.length(), n2 = s2.length(); 
  
    // Reverse both of strings 
    reverse(s1.begin(), s1.end()); 
    reverse(s2.begin(), s2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((s1[i]-'0')+(s2[i]-'0')+carry); 
        s.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((s2[i]-'0')+carry); 
        s.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        s.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(s.begin(), s.end()); 
  
    return s;
} 
 
 
 
ll search(ll arr[], ll n, ll k){
    
    ll u = k;
    ll l = 0;
 
    
    while(u>=l){
        
        if(arr[(u+l)/2] == n){
            
            return (u+l)/2;
            
        } else if(arr[(u+l)/2] > n){
            
            u = (u+l)/2 - 1;
            
        } else {
            
            l = (u+l)/2 + 1;
            
        }
        
        
    }
    
    return -1;
    
    
}
 
ll greatestSubarraySum(ll array[], ll n){
 
    ll best = 0, sum = 0;
    for (ll k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
 
    return best;
}
 
ll powerrr(ll a, ll b){
 
    ll ans = 1;
 
    for(ll i = 0; i < b; i++)ans*=a;
 
    return ans;
 
 
}
 
void swapp(ll *a, ll*b){
 
    ll temp = *a;
    *a = *b;
    *b = temp;
 
 
}
 
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    
    return gcd(b%a, a);
}
 
ll lcm(ll a, ll b)  
{  
    return (a*b)/gcd(a, b);  
} 
 
ll min(ll a, ll b){
    if(a < b)return a;  
    return b;
}
 
ll max(ll a, ll b){
    if(a > b)return a;
    return b;
}
 
struct node {

    string s;
    struct node *left;
    struct node *right;

};


vector<string> post(string s){

    stack<char> a;
    vector<string> ans;

    REP(i,0,s.length()){

        if(s[i] != '-' && s[i] != '+' && s[i] != '/' && s[i] != '*' && s[i] != '^' && s[i] != ')' && s[i] != '('){

            string temp;
            ll j;
            for(j=i; j<s.length(); j++){

                if(s[j] != '-' && s[j] != '+' && s[j] != '/' && s[j] != '*' && s[j] != '^' && s[j] != ')' && s[j] != '('){
                    temp+=s[j];

                } else break;

            }

            i=j-1;

            ans.PB(temp);

        } else {

            if(s[i] == '-' || s[i]=='+'){

                if(s[i]=='-' && (i==0 || s[i-1] == '+' || s[i-1] == '-' || s[i-1] == '*' || s[i-1] == '/' || s[i-1] == '^' || s[i-1] == '(')){a.push('~');}
                else {
                    if(a.empty())a.push(s[i]);
                    else{

                        while(!a.empty() && a.top() != '('){


                            char x=a.top();
                            a.pop();
                            string tempy;
                            tempy+=x;
                            ans.push_back(tempy);
                        }
                        a.push(s[i]);

                    }

                }

            } else if(s[i] == '*' || s[i] == '/'){

                if(a.empty())a.push(s[i]);
                else{

                    if(a.top() == '+' || a.top() == '-' || a.top()=='(')a.push(s[i]);
                    else{

                        while(!a.empty() && a.top() != '(' && a.top() != '+' && a.top() != '-'){

                            char x=a.top();
                            a.pop();
                            string tempy;
                            tempy+=x;
                            ans.push_back(tempy);

                        }
                        a.push(s[i]);


                    }

                }

            } else if(s[i] == '(')a.push(s[i]);
            else if(s[i] == ')'){

                while(a.top() != '('){

                    char x=a.top();
                    a.pop();
                    string tempy;
                    tempy+=x;
                    ans.PB(tempy);
                }
                a.pop();


            } else if(s[i] == '^'){

                if(a.empty())a.push(s[i]);
                else {

                    while(!a.empty() && a.top() == '~'){

                        char x=a.top();
                        string tempy;
                        tempy+=x;
                        a.pop();
                        ans.PB(tempy);

                    }

                    a.push('^');

                }

            }

            //if(!a.empty())cout<<a.top()<<endl;
        }


    }

    while(!a.empty()){

        string tempy;
        tempy+=a.top();
        a.pop();
        ans.PB(tempy);

    }

    return ans;


}

unordered_map<string, ll> values;
ll flagl;

ll figure(string s){

    if(s[0] == '0' || s[0] == '1' || s[0] == '2' || s[0] == '3' || s[0] == '4' || s[0] == '5' || s[0] == '6' || s[0] == '7' || s[0] == '8' || s[0] == '9')return stoll(s);
    

    if(values.find(s) == values.end() || values[s]==INF){flagl=1;return INF;}
    else return values[s];

    

}

struct node *createNode(){

    struct node *temp=(struct node *)malloc(sizeof(struct node));
    return temp;

}

void build(struct node **start, vector<string> s){

    stack<struct node *> a;

    REP(i,0,s.size()){

        if(s[i][0] != '+' && s[i][0] != '*' && s[i][0] != '-' && s[i][0] != '/' && s[i][0] != '^' && s[i][0] != '~'){

            struct node *temp=createNode();

            temp->left=NULL;
            temp->right=NULL;
            temp->s = s[i];
            a.push(temp);

        } else{

            if(s[i][0]=='~'){


                if(((a.top())->s)[0] != '~')(a.top())->s = "~"+(a.top())->s;
                else (a.top())->s = ((a.top())->s).substr(1);

            }
            else{


                struct node *temp=createNode();
                struct node *temp2 = a.top();
                a.pop();
                struct node *temp3 = a.top();
                a.pop();
                temp->right=temp2;
                temp->left=temp3;
                temp->s=s[i];
                a.push(temp);

            }


        }

    }

    *start = a.top();



}

void inorder(struct node *start){

    if(start == NULL)return;
    inorder(start->left);
    cout<<start->s<<endl;
    inorder(start->right);

}

ll evaluate(struct node *start){

    ll x=0;

    if(start->s=="+")return evaluate(start->left)+evaluate(start->right);
    else if (start->s=="-") return evaluate(start->left)-evaluate(start->right);
    else if (start->s=="*") return evaluate(start->left)*evaluate(start->right);
    else if (start->s=="/") return evaluate(start->left)/evaluate(start->right);
    else if (start->s=="^") return powerrr(evaluate(start->left), evaluate(start->right));
    else {

        if((start->s)[0] =='~')return -1*figure((start->s).substr(1));
        else return figure((start->s));

    }


}


int main(){


    io

    ll n;
    cin>>n;
    while(n--){
        ll t;
        cin>>t;

        while(t--){

            flagl=0;

            string s;
            cin>>s;

            ll flag2=0;
            REP(i,0,s.length()){

                if(s[i]=='='){
                    flag2=1;

                    vector<string> posy=post(s.substr(i+1));

                    struct node *start=createNode();

                    build(&start, posy);
                    ll y = evaluate(start);
                    if(flagl==1)values[s.substr(0,i)] = INF;
                    else values[s.substr(0,i)]=y;
                    break;
                }
            }
            if(flag2)continue;

            vector<string> pos=post(s);
            //REP(i,0,pos.size())cout<<pos[i]<<" ";
            //cout<<enl;
            struct node *start = createNode();
            build(&start, pos);
            //inorder(start);
            ll y = evaluate(start);
            if(flagl)cout<<"CANT BE EVALUATED"<<endl;
            else cout<<y<<endl;

        }
        values.clear();

    }
}
