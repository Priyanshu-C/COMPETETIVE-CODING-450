#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fo(i,n) for(i=0;i<n;i++)
#define fok(i,k,n) for(i=k;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

struct Node {
  public:
  int data;
  Node *next;
};

//Recursively
void reverseRecur(Node *head,Node *&temp)
{
  if(head == NULL or head->next==NULL)
  {
    temp=head;
    return;
  }
  reverseRecur(head->next,temp);
  head->next->next=head;
  head->next=NULL;
}

//Iteratively 
void reverseItera(Node *&head)
{
  Node *curr = head;
  Node *prev= NULL;
  Node *next= NULL;
  while(curr!=NULL)
  {
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  head = prev;
}

//Push at front of LL
void push(int data,Node *&head)
{
  if(head==NULL)
  {
    head=new Node();
    head->data=data;
    head->next=NULL;
    return;
  }
  Node* temp = new Node();
  temp->data=data;
  temp->next=head;
  head=temp;
}

//Print the list
void print(Node *&head)
{     
  cout<<"////////////////"<<endl;
      Node *temp = head;      
      while(temp!=NULL)
      {
      cout<<temp->data<<" ";
      temp=temp->next;
      }
  cout<<"////////////////"<<endl;
}

int main() {
    FIN

      Node *head = NULL;
      push(10,head);
      push(20,head);
      push(30,head);
      push(30,head);
      push(50,head);
      push(40,head);
      Node *temp = NULL;  
      print(head);
      reverseItera(head);
      print(head);
      reverseRecur(head,temp);
      print(temp);


    return 0;
}


